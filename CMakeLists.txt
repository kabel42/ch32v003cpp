cmake_minimum_required(VERSION 3.20)

project(wch_demo VERSION 0.1.0 LANGUAGES C CXX ASM)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_COMPILER "riscv64-elf-gcc")
set(CMAKE_CXX_COMPILER "riscv64-elf-gcc")

add_subdirectory(src/cppreg build/cppreg)

add_executable(wch_demo 
    src/ch32v003/startup/startup_ch32v00x.c
    src/main.cpp
)
target_include_directories(wch_demo PRIVATE
    src/Startup
)

target_compile_options(wch_demo PRIVATE 
    -march=rv32ec
    -mabi=ilp32e
    -msmall-data-limit=0
    -msave-restore
    -Os
    -fmessage-length=0
    -fsigned-char
    -ffunction-sections
    -fdata-sections
    -fno-common
    -g3
    -Wall
    -fstack-usage
    -flto
)

target_link_libraries(wch_demo cppreg)

target_link_options(wch_demo PRIVATE
    -march=rv32ec
    -mabi=ilp32e
    -msmall-data-limit=0
    -msave-restore
    -Os
    -fmessage-length=0
    -fsigned-char
    -ffunction-sections
    -fdata-sections
    -fno-common
    -g3
    -Wall
    -fstack-usage
    --specs=nano.specs
    --specs=nosys.specs
    -Wl,--print-memory-usage
    -T "${CMAKE_SOURCE_DIR}/src/Ld/Link.ld"
    -Wl,--gc-sections
    -Wl,-Map=wch_demo.map
    -nostartfiles
    -Xlinker
)

set_target_properties(wch_demo PROPERTIES
    SUFFIX ".elf"
)

add_custom_command(TARGET wch_demo POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex "$<TARGET_FILE:wch_demo>" wch_demo.hex
)
