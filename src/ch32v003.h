#ifndef CH32V003_h
#define CH32V003_h

#include <cppreg.h>
using namespace cppreg;

namespace PWR
{
    using PWR_pack = RegisterPack<0x40007000, 1024>;
    struct CTLR : PackedRegister<PWR_pack, RegBitSize::b32, 0 * 8> // Power control register
    {
        using PDDS = Field<CTLR, 1, 1, read_write>; // Power Down Deep Sleep
        using PVDE = Field<CTLR, 1, 4, read_write>; // Power Voltage Detector
        using PLS = Field<CTLR, 3, 5, read_write>;  // PVD Level Selection
    };
    struct CSR : PackedRegister<PWR_pack, RegBitSize::b32, 4 * 8> // Power control state register
    {
        using PVDO = Field<CSR, 1, 2, read_only>; // PVD Output
    };
    struct AWUCSR : PackedRegister<PWR_pack, RegBitSize::b32, 8 * 8> // Automatic wake-up control state register
    {
        using AWUEN = Field<AWUCSR, 1, 1, read_write>; // Automatic wake-up enable
    };
    struct AWUAPR : PackedRegister<PWR_pack, RegBitSize::b32, 12 * 8> // Automatic wake window comparison value register
    {
        using AWUAPRfield = Field<AWUAPR, 6, 0, read_write>; // AWU window value
    };
    struct AWUPSC : PackedRegister<PWR_pack, RegBitSize::b32, 16 * 8> // Automatic wake-up prescaler register
    {
        using AWUPSCfield = Field<AWUPSC, 4, 0, read_write>; // Wake-up prescaler
    };
} // namespace PWR
namespace RCC
{
    using RCC_pack = RegisterPack<0x40021000, 1024>;
    struct CTLR : PackedRegister<RCC_pack, RegBitSize::b32, 0 * 8> // Clock control register
    {
        using HSION = Field<CTLR, 1, 0, read_write>;   // Internal High Speed clock
        using HSIRDY = Field<CTLR, 1, 1, read_only>;   // Internal High Speed clock ready
        using HSITRIM = Field<CTLR, 5, 3, read_write>; // Internal High Speed clock
        using HSICAL = Field<CTLR, 8, 8, read_only>;   // Internal High Speed clock
        using HSEON = Field<CTLR, 1, 16, read_write>;  // External High Speed clock
        using HSERDY = Field<CTLR, 1, 17, read_only>;  // External High Speed clock ready
        using HSEBYP = Field<CTLR, 1, 18, read_write>; // External High Speed clock
        using CSSON = Field<CTLR, 1, 19, read_write>;  // Clock Security System
        using PLLON = Field<CTLR, 1, 24, read_write>;  // PLL enable
        using PLLRDY = Field<CTLR, 1, 25, read_only>;  // PLL clock ready flag
    };
    struct CFGR0 : PackedRegister<RCC_pack, RegBitSize::b32, 4 * 8> // Clock configuration register
    {
        using SW = Field<CFGR0, 2, 0, read_write>;      // System clock Switch
        using SWS = Field<CFGR0, 2, 2, read_only>;      // System Clock Switch Status
        using HPRE = Field<CFGR0, 4, 4, read_write>;    // AHB prescaler
        using PPRE1 = Field<CFGR0, 3, 8, read_write>;   // APB Low speed prescaler
        using PPRE2 = Field<CFGR0, 3, 11, read_write>;  // APB High speed prescaler
        using ADCPRE = Field<CFGR0, 2, 14, read_write>; // ADC prescaler
        using PLLSRC = Field<CFGR0, 1, 16, read_write>; // PLL entry clock source
        using MCO = Field<CFGR0, 3, 24, read_write>;    // Microcontroller clock
    };
    struct INTR : PackedRegister<RCC_pack, RegBitSize::b32, 8 * 8> // Clock interrupt register
    {
        using LSIRDYF = Field<INTR, 1, 0, read_only>;    // LSI Ready Interrupt flag
        using HSIRDYF = Field<INTR, 1, 2, read_only>;    // HSI Ready Interrupt flag
        using HSERDYF = Field<INTR, 1, 3, read_only>;    // HSE Ready Interrupt flag
        using PLLRDYF = Field<INTR, 1, 4, read_only>;    // PLL Ready Interrupt flag
        using CSSF = Field<INTR, 1, 7, read_only>;       // Clock Security System Interrupt
        using LSIRDYIE = Field<INTR, 1, 8, read_write>;  // LSI Ready Interrupt Enable
        using HSIRDYIE = Field<INTR, 1, 10, read_write>; // HSI Ready Interrupt Enable
        using HSERDYIE = Field<INTR, 1, 11, read_write>; // HSE Ready Interrupt Enable
        using PLLRDYIE = Field<INTR, 1, 12, read_write>; // PLL Ready Interrupt Enable
        using LSIRDYC = Field<INTR, 1, 16, write_only>;  // LSI Ready Interrupt Clear
        using HSIRDYC = Field<INTR, 1, 18, write_only>;  // HSI Ready Interrupt Clear
        using HSERDYC = Field<INTR, 1, 19, write_only>;  // HSE Ready Interrupt Clear
        using PLLRDYC = Field<INTR, 1, 20, write_only>;  // PLL Ready Interrupt Clear
        using CSSC = Field<INTR, 1, 23, write_only>;     // Clock security system interrupt
    };
    struct APB2PRSTR : PackedRegister<RCC_pack, RegBitSize::b32, 12 * 8> // APB2 peripheral reset register
    {
        using AFIORST = Field<APB2PRSTR, 1, 0, read_write>;    // Alternate function I/O
        using IOPARST = Field<APB2PRSTR, 1, 2, read_write>;    // IO port A reset
        using IOPCRST = Field<APB2PRSTR, 1, 4, read_write>;    // IO port C reset
        using IOPDRST = Field<APB2PRSTR, 1, 5, read_write>;    // IO port D reset
        using ADC1RST = Field<APB2PRSTR, 1, 9, read_write>;    // ADC 1 interface reset
        using TIM1RST = Field<APB2PRSTR, 1, 11, read_write>;   // TIM1 timer reset
        using SPI1RST = Field<APB2PRSTR, 1, 12, read_write>;   // SPI 1 reset
        using USART1RST = Field<APB2PRSTR, 1, 14, read_write>; // USART1 reset
    };
    struct APB1PRSTR : PackedRegister<RCC_pack, RegBitSize::b32, 16 * 8> // APB1 peripheral reset register
    {
        using WWDGRST = Field<APB1PRSTR, 1, 11, read_write>; // Window watchdog reset
        using I2C1RST = Field<APB1PRSTR, 1, 21, read_write>; // I2C1 reset
        using PWRRST = Field<APB1PRSTR, 1, 28, read_write>;  // Power interface reset
    };
    struct AHBPCENR : PackedRegister<RCC_pack, RegBitSize::b32, 20 * 8> // AHB Peripheral Clock enable register
    {
        using DMA1EN = Field<AHBPCENR, 1, 0, read_write>; // DMA clock enable
        using SRAMEN = Field<AHBPCENR, 1, 2, read_write>; // SRAM interface clock
    };
    struct APB2PCENR : PackedRegister<RCC_pack, RegBitSize::b32, 24 * 8> // APB2 peripheral clock enable register
    {
        using AFIOEN = Field<APB2PCENR, 1, 0, read_write>;    // Alternate function I/O clock
        using IOPAEN = Field<APB2PCENR, 1, 2, read_write>;    // I/O port A clock enable
        using IOPCEN = Field<APB2PCENR, 1, 4, read_write>;    // I/O port C clock enable
        using IOPDEN = Field<APB2PCENR, 1, 5, read_write>;    // I/O port D clock enable
        using ADC1EN = Field<APB2PCENR, 1, 9, read_write>;    // ADC1 interface clock
        using TIM1EN = Field<APB2PCENR, 1, 11, read_write>;   // TIM1 Timer clock enable
        using SPI1EN = Field<APB2PCENR, 1, 12, read_write>;   // SPI 1 clock enable
        using USART1EN = Field<APB2PCENR, 1, 14, read_write>; // USART1 clock enable
    };
    struct APB1PCENR : PackedRegister<RCC_pack, RegBitSize::b32, 28 * 8> // APB1 peripheral clock enable register
    {
        using TIM2EN = Field<APB1PCENR, 1, 0, read_write>;  // Timer 2 clock enable
        using WWDGEN = Field<APB1PCENR, 1, 11, read_write>; // Window watchdog clock
        using I2C1EN = Field<APB1PCENR, 1, 21, read_write>; // I2C 1 clock enable
        using PWREN = Field<APB1PCENR, 1, 28, read_write>;  // Power interface clock
    };
    struct RSTSCKR : PackedRegister<RCC_pack, RegBitSize::b32, 36 * 8> // Control/status register
    {
        using LSION = Field<RSTSCKR, 1, 0, read_write>;    // Internal low speed oscillator
        using LSIRDY = Field<RSTSCKR, 1, 1, read_only>;    // Internal low speed oscillator
        using RMVF = Field<RSTSCKR, 1, 24, read_write>;    // Remove reset flag
        using PINRSTF = Field<RSTSCKR, 1, 26, read_only>;  // PIN reset flag
        using PORRSTF = Field<RSTSCKR, 1, 27, read_only>;  // POR/PDR reset flag
        using SFTRSTF = Field<RSTSCKR, 1, 28, read_only>;  // Software reset flag
        using IWDGRSTF = Field<RSTSCKR, 1, 29, read_only>; // Independent watchdog reset
        using WWDGRSTF = Field<RSTSCKR, 1, 30, read_only>; // Window watchdog reset flag
        using LPWRRSTF = Field<RSTSCKR, 1, 31, read_only>; // Low-power reset flag
    };
} // namespace RCC
namespace EXTEND
{
    using EXTEND_pack = RegisterPack<0x40023800, 1024>;
    struct EXTEND_CTR : PackedRegister<EXTEND_pack, RegBitSize::b32, 0 * 8> // Configure the extended control register
    {
        using PLL_CFG = Field<EXTEND_CTR, 4, 0, read_write>;         // Configure the PLL clock delay time
        using LOCKUP_EN = Field<EXTEND_CTR, 1, 6, read_write>;       // LOCKUP_Enable
        using LOCKUP_RESET = Field<EXTEND_CTR, 1, 7, read_write>;    // LOCKUP RESET
        using LDO_TRIM = Field<EXTEND_CTR, 1, 10, read_write>;       // LDO_TRIM
        using FLASH_CLK_TRIM = Field<EXTEND_CTR, 3, 11, read_write>; // FLASH clock trimming
        using WR_EN = Field<EXTEND_CTR, 1, 14, read_write>;          // Control Register write enable
        using WR_LOCK = Field<EXTEND_CTR, 1, 15, read_write>;        // Control Register write lock
        using OPA_EN = Field<EXTEND_CTR, 1, 16, read_write>;         // OPA Enalbe
        using OPA_NSEL = Field<EXTEND_CTR, 1, 17, read_write>;       // OPA negative end channel selection
        using OPA_PSEL = Field<EXTEND_CTR, 1, 18, read_write>;       // OPA positive end channel selection
    };
    struct EXTEND_KR : PackedRegister<EXTEND_pack, RegBitSize::b32, 4 * 8> // Configure the extended key register
    {
        using KEY = Field<EXTEND_KR, 32, 0, write_only>; // Write key value
    };
} // namespace EXTEND
namespace GPIOA
{
    using GPIOA_pack = RegisterPack<0x40010800, 1024>;
    struct CFGLR : PackedRegister<GPIOA_pack, RegBitSize::b32, 0 * 8> // Port configuration register low
    {
        using MODE0 = Field<CFGLR, 4, 4 * 0, read_write>;
        using MODE1 = Field<CFGLR, 4, 4 * 1, read_write>;
        using MODE2 = Field<CFGLR, 4, 4 * 2, read_write>;
        using MODE3 = Field<CFGLR, 4, 4 * 3, read_write>;
        using MODE4 = Field<CFGLR, 4, 4 * 4, read_write>;
        using MODE5 = Field<CFGLR, 4, 4 * 5, read_write>;
        using MODE6 = Field<CFGLR, 4, 4 * 6, read_write>;
        using MODE7 = Field<CFGLR, 4, 4 * 7, read_write>;
    };
    struct INDR : PackedRegister<GPIOA_pack, RegBitSize::b32, 8 * 8> // Port input data register
    {
        using IDR0 = Field<INDR, 1, 0, read_only>; // Port input data
        using IDR1 = Field<INDR, 1, 1, read_only>; // Port input data
        using IDR2 = Field<INDR, 1, 2, read_only>; // Port input data
        using IDR3 = Field<INDR, 1, 3, read_only>; // Port input data
        using IDR4 = Field<INDR, 1, 4, read_only>; // Port input data
        using IDR5 = Field<INDR, 1, 5, read_only>; // Port input data
        using IDR6 = Field<INDR, 1, 6, read_only>; // Port input data
        using IDR7 = Field<INDR, 1, 7, read_only>; // Port input data
    };
    struct OUTDR : PackedRegister<GPIOA_pack, RegBitSize::b32, 12 * 8> // Port output data register
    {
        using ODR0 = Field<OUTDR, 1, 0, read_write>; // Port output data
        using ODR1 = Field<OUTDR, 1, 1, read_write>; // Port output data
        using ODR2 = Field<OUTDR, 1, 2, read_write>; // Port output data
        using ODR3 = Field<OUTDR, 1, 3, read_write>; // Port output data
        using ODR4 = Field<OUTDR, 1, 4, read_write>; // Port output data
        using ODR5 = Field<OUTDR, 1, 5, read_write>; // Port output data
        using ODR6 = Field<OUTDR, 1, 6, read_write>; // Port output data
        using ODR7 = Field<OUTDR, 1, 7, read_write>; // Port output data
    };
    struct BSHR : PackedRegister<GPIOA_pack, RegBitSize::b32, 16 * 8> // Port bit set/reset register
    {
        using BS0 = Field<BSHR, 1, 0, write_only>;  // Set bit 0
        using BS1 = Field<BSHR, 1, 1, write_only>;  // Set bit 1
        using BS2 = Field<BSHR, 1, 2, write_only>;  // Set bit 1
        using BS3 = Field<BSHR, 1, 3, write_only>;  // Set bit 3
        using BS4 = Field<BSHR, 1, 4, write_only>;  // Set bit 4
        using BS5 = Field<BSHR, 1, 5, write_only>;  // Set bit 5
        using BS6 = Field<BSHR, 1, 6, write_only>;  // Set bit 6
        using BS7 = Field<BSHR, 1, 7, write_only>;  // Set bit 7
        using BR0 = Field<BSHR, 1, 16, write_only>; // Reset bit 0
        using BR1 = Field<BSHR, 1, 17, write_only>; // Reset bit 1
        using BR2 = Field<BSHR, 1, 18, write_only>; // Reset bit 2
        using BR3 = Field<BSHR, 1, 19, write_only>; // Reset bit 3
        using BR4 = Field<BSHR, 1, 20, write_only>; // Reset bit 4
        using BR5 = Field<BSHR, 1, 21, write_only>; // Reset bit 5
        using BR6 = Field<BSHR, 1, 22, write_only>; // Reset bit 6
        using BR7 = Field<BSHR, 1, 23, write_only>; // Reset bit 7
    };
    struct BCR : PackedRegister<GPIOA_pack, RegBitSize::b32, 20 * 8> // Port bit reset register
    {
        using BR0 = Field<BCR, 1, 0, write_only>; // Reset bit 0
        using BR1 = Field<BCR, 1, 1, write_only>; // Reset bit 1
        using BR2 = Field<BCR, 1, 2, write_only>; // Reset bit 1
        using BR3 = Field<BCR, 1, 3, write_only>; // Reset bit 3
        using BR4 = Field<BCR, 1, 4, write_only>; // Reset bit 4
        using BR5 = Field<BCR, 1, 5, write_only>; // Reset bit 5
        using BR6 = Field<BCR, 1, 6, write_only>; // Reset bit 6
        using BR7 = Field<BCR, 1, 7, write_only>; // Reset bit 7
    };
    struct LCKR : PackedRegister<GPIOA_pack, RegBitSize::b32, 24 * 8> // Port configuration lock
    {
        using LCK0 = Field<LCKR, 1, 0, read_write>; // Port A Lock bit 0
        using LCK1 = Field<LCKR, 1, 1, read_write>; // Port A Lock bit 1
        using LCK2 = Field<LCKR, 1, 2, read_write>; // Port A Lock bit 2
        using LCK3 = Field<LCKR, 1, 3, read_write>; // Port A Lock bit 3
        using LCK4 = Field<LCKR, 1, 4, read_write>; // Port A Lock bit 4
        using LCK5 = Field<LCKR, 1, 5, read_write>; // Port A Lock bit 5
        using LCK6 = Field<LCKR, 1, 6, read_write>; // Port A Lock bit 6
        using LCK7 = Field<LCKR, 1, 7, read_write>; // Port A Lock bit 7
        using LCKK = Field<LCKR, 1, 8, read_write>; // Lock key
    };
} // namespace GPIOA
namespace GPIOC
{
    using GPIOC_pack = RegisterPack<0x40011000, 1024>;
    struct CFGLR : PackedRegister<GPIOC_pack, RegBitSize::b32, 0 * 8> // Port configuration register low
    {
        using MODE0 = Field<CFGLR, 4, 4 * 0, read_write>;
        using MODE1 = Field<CFGLR, 4, 4 * 1, read_write>;
        using MODE2 = Field<CFGLR, 4, 4 * 2, read_write>;
        using MODE3 = Field<CFGLR, 4, 4 * 3, read_write>;
        using MODE4 = Field<CFGLR, 4, 4 * 4, read_write>;
        using MODE5 = Field<CFGLR, 4, 4 * 5, read_write>;
        using MODE6 = Field<CFGLR, 4, 4 * 6, read_write>;
        using MODE7 = Field<CFGLR, 4, 4 * 7, read_write>;
    };
    struct INDR : PackedRegister<GPIOC_pack, RegBitSize::b32, 8 * 8> // Port input data register
    {
        using IDR0 = Field<INDR, 1, 0, read_only>; // Port input data
        using IDR1 = Field<INDR, 1, 1, read_only>; // Port input data
        using IDR2 = Field<INDR, 1, 2, read_only>; // Port input data
        using IDR3 = Field<INDR, 1, 3, read_only>; // Port input data
        using IDR4 = Field<INDR, 1, 4, read_only>; // Port input data
        using IDR5 = Field<INDR, 1, 5, read_only>; // Port input data
        using IDR6 = Field<INDR, 1, 6, read_only>; // Port input data
        using IDR7 = Field<INDR, 1, 7, read_only>; // Port input data
    };
    struct OUTDR : PackedRegister<GPIOC_pack, RegBitSize::b32, 12 * 8> // Port output data register
    {
        using ODR0 = Field<OUTDR, 1, 0, read_write>; // Port output data
        using ODR1 = Field<OUTDR, 1, 1, read_write>; // Port output data
        using ODR2 = Field<OUTDR, 1, 2, read_write>; // Port output data
        using ODR3 = Field<OUTDR, 1, 3, read_write>; // Port output data
        using ODR4 = Field<OUTDR, 1, 4, read_write>; // Port output data
        using ODR5 = Field<OUTDR, 1, 5, read_write>; // Port output data
        using ODR6 = Field<OUTDR, 1, 6, read_write>; // Port output data
        using ODR7 = Field<OUTDR, 1, 7, read_write>; // Port output data
    };
    struct BSHR : PackedRegister<GPIOC_pack, RegBitSize::b32, 16 * 8> // Port bit set/reset register
    {
        using BS0 = Field<BSHR, 1, 0, write_only>;  // Set bit 0
        using BS1 = Field<BSHR, 1, 1, write_only>;  // Set bit 1
        using BS2 = Field<BSHR, 1, 2, write_only>;  // Set bit 1
        using BS3 = Field<BSHR, 1, 3, write_only>;  // Set bit 3
        using BS4 = Field<BSHR, 1, 4, write_only>;  // Set bit 4
        using BS5 = Field<BSHR, 1, 5, write_only>;  // Set bit 5
        using BS6 = Field<BSHR, 1, 6, write_only>;  // Set bit 6
        using BS7 = Field<BSHR, 1, 7, write_only>;  // Set bit 7
        using BR0 = Field<BSHR, 1, 16, write_only>; // Reset bit 0
        using BR1 = Field<BSHR, 1, 17, write_only>; // Reset bit 1
        using BR2 = Field<BSHR, 1, 18, write_only>; // Reset bit 2
        using BR3 = Field<BSHR, 1, 19, write_only>; // Reset bit 3
        using BR4 = Field<BSHR, 1, 20, write_only>; // Reset bit 4
        using BR5 = Field<BSHR, 1, 21, write_only>; // Reset bit 5
        using BR6 = Field<BSHR, 1, 22, write_only>; // Reset bit 6
        using BR7 = Field<BSHR, 1, 23, write_only>; // Reset bit 7
    };
    struct BCR : PackedRegister<GPIOC_pack, RegBitSize::b32, 20 * 8> // Port bit reset register
    {
        using BR0 = Field<BCR, 1, 0, write_only>; // Reset bit 0
        using BR1 = Field<BCR, 1, 1, write_only>; // Reset bit 1
        using BR2 = Field<BCR, 1, 2, write_only>; // Reset bit 1
        using BR3 = Field<BCR, 1, 3, write_only>; // Reset bit 3
        using BR4 = Field<BCR, 1, 4, write_only>; // Reset bit 4
        using BR5 = Field<BCR, 1, 5, write_only>; // Reset bit 5
        using BR6 = Field<BCR, 1, 6, write_only>; // Reset bit 6
        using BR7 = Field<BCR, 1, 7, write_only>; // Reset bit 7
    };
    struct LCKR : PackedRegister<GPIOC_pack, RegBitSize::b32, 24 * 8> // Port configuration lock
    {
        using LCK0 = Field<LCKR, 1, 0, read_write>; // Port A Lock bit 0
        using LCK1 = Field<LCKR, 1, 1, read_write>; // Port A Lock bit 1
        using LCK2 = Field<LCKR, 1, 2, read_write>; // Port A Lock bit 2
        using LCK3 = Field<LCKR, 1, 3, read_write>; // Port A Lock bit 3
        using LCK4 = Field<LCKR, 1, 4, read_write>; // Port A Lock bit 4
        using LCK5 = Field<LCKR, 1, 5, read_write>; // Port A Lock bit 5
        using LCK6 = Field<LCKR, 1, 6, read_write>; // Port A Lock bit 6
        using LCK7 = Field<LCKR, 1, 7, read_write>; // Port A Lock bit 7
        using LCKK = Field<LCKR, 1, 8, read_write>; // Lock key
    };
} // namespace GPIOC
namespace GPIOD
{
    using GPIOD_pack = RegisterPack<0x40011400, 1024>;
    struct CFGLR : PackedRegister<GPIOD_pack, RegBitSize::b32, 0 * 8> // Port configuration register low
    {
        using MODE0 = Field<CFGLR, 4, 4 * 0, read_write>;
        using MODE1 = Field<CFGLR, 4, 4 * 1, read_write>;
        using MODE2 = Field<CFGLR, 4, 4 * 2, read_write>;
        using MODE3 = Field<CFGLR, 4, 4 * 3, read_write>;
        using MODE4 = Field<CFGLR, 4, 4 * 4, read_write>;
        using MODE5 = Field<CFGLR, 4, 4 * 5, read_write>;
        using MODE6 = Field<CFGLR, 4, 4 * 6, read_write>;
        using MODE7 = Field<CFGLR, 4, 4 * 7, read_write>;
    };
    struct INDR : PackedRegister<GPIOD_pack, RegBitSize::b32, 8 * 8> // Port input data register
    {
        using IDR0 = Field<INDR, 1, 0, read_only>; // Port input data
        using IDR1 = Field<INDR, 1, 1, read_only>; // Port input data
        using IDR2 = Field<INDR, 1, 2, read_only>; // Port input data
        using IDR3 = Field<INDR, 1, 3, read_only>; // Port input data
        using IDR4 = Field<INDR, 1, 4, read_only>; // Port input data
        using IDR5 = Field<INDR, 1, 5, read_only>; // Port input data
        using IDR6 = Field<INDR, 1, 6, read_only>; // Port input data
        using IDR7 = Field<INDR, 1, 7, read_only>; // Port input data
    };
    struct OUTDR : PackedRegister<GPIOD_pack, RegBitSize::b32, 12 * 8> // Port output data register
    {
        using ODR0 = Field<OUTDR, 1, 0, read_write>; // Port output data
        using ODR1 = Field<OUTDR, 1, 1, read_write>; // Port output data
        using ODR2 = Field<OUTDR, 1, 2, read_write>; // Port output data
        using ODR3 = Field<OUTDR, 1, 3, read_write>; // Port output data
        using ODR4 = Field<OUTDR, 1, 4, read_write>; // Port output data
        using ODR5 = Field<OUTDR, 1, 5, read_write>; // Port output data
        using ODR6 = Field<OUTDR, 1, 6, read_write>; // Port output data
        using ODR7 = Field<OUTDR, 1, 7, read_write>; // Port output data
    };
    struct BSHR : PackedRegister<GPIOD_pack, RegBitSize::b32, 16 * 8> // Port bit set/reset register
    {
        using BS0 = Field<BSHR, 1, 0, write_only>;  // Set bit 0
        using BS1 = Field<BSHR, 1, 1, write_only>;  // Set bit 1
        using BS2 = Field<BSHR, 1, 2, write_only>;  // Set bit 1
        using BS3 = Field<BSHR, 1, 3, write_only>;  // Set bit 3
        using BS4 = Field<BSHR, 1, 4, write_only>;  // Set bit 4
        using BS5 = Field<BSHR, 1, 5, write_only>;  // Set bit 5
        using BS6 = Field<BSHR, 1, 6, write_only>;  // Set bit 6
        using BS7 = Field<BSHR, 1, 7, write_only>;  // Set bit 7
        using BR0 = Field<BSHR, 1, 16, write_only>; // Reset bit 0
        using BR1 = Field<BSHR, 1, 17, write_only>; // Reset bit 1
        using BR2 = Field<BSHR, 1, 18, write_only>; // Reset bit 2
        using BR3 = Field<BSHR, 1, 19, write_only>; // Reset bit 3
        using BR4 = Field<BSHR, 1, 20, write_only>; // Reset bit 4
        using BR5 = Field<BSHR, 1, 21, write_only>; // Reset bit 5
        using BR6 = Field<BSHR, 1, 22, write_only>; // Reset bit 6
        using BR7 = Field<BSHR, 1, 23, write_only>; // Reset bit 7
    };
    struct BCR : PackedRegister<GPIOD_pack, RegBitSize::b32, 20 * 8> // Port bit reset register
    {
        using BR0 = Field<BCR, 1, 0, write_only>; // Reset bit 0
        using BR1 = Field<BCR, 1, 1, write_only>; // Reset bit 1
        using BR2 = Field<BCR, 1, 2, write_only>; // Reset bit 1
        using BR3 = Field<BCR, 1, 3, write_only>; // Reset bit 3
        using BR4 = Field<BCR, 1, 4, write_only>; // Reset bit 4
        using BR5 = Field<BCR, 1, 5, write_only>; // Reset bit 5
        using BR6 = Field<BCR, 1, 6, write_only>; // Reset bit 6
        using BR7 = Field<BCR, 1, 7, write_only>; // Reset bit 7
    };
    struct LCKR : PackedRegister<GPIOD_pack, RegBitSize::b32, 24 * 8> // Port configuration lock
    {
        using LCK0 = Field<LCKR, 1, 0, read_write>; // Port A Lock bit 0
        using LCK1 = Field<LCKR, 1, 1, read_write>; // Port A Lock bit 1
        using LCK2 = Field<LCKR, 1, 2, read_write>; // Port A Lock bit 2
        using LCK3 = Field<LCKR, 1, 3, read_write>; // Port A Lock bit 3
        using LCK4 = Field<LCKR, 1, 4, read_write>; // Port A Lock bit 4
        using LCK5 = Field<LCKR, 1, 5, read_write>; // Port A Lock bit 5
        using LCK6 = Field<LCKR, 1, 6, read_write>; // Port A Lock bit 6
        using LCK7 = Field<LCKR, 1, 7, read_write>; // Port A Lock bit 7
        using LCKK = Field<LCKR, 1, 8, read_write>; // Lock key
    };
} // namespace GPIOD
namespace AFIO
{
    using AFIO_pack = RegisterPack<0x40010000, 1024>;
    struct PCFR : PackedRegister<AFIO_pack, RegBitSize::b32, 4 * 8> // AF remap and debug I/O configuration
    {
        using SPI1RM = Field<PCFR, 1, 0, read_write>;           // SPI1 remapping
        using I2C1RM = Field<PCFR, 1, 1, read_write>;           // I2C1 remapping
        using USART1RM = Field<PCFR, 1, 2, read_write>;         // USART1 remapping
        using TIM1RM = Field<PCFR, 2, 6, read_write>;           // TIM1 remapping
        using TIM2RM = Field<PCFR, 2, 8, read_write>;           // TIM2 remapping
        using PA12RM = Field<PCFR, 1, 15, read_write>;          // Port A1/Port A2 mapping on
        using ADC1_ETRGINJ_RM = Field<PCFR, 1, 17, read_write>; // ADC 1 External trigger injected conversion remapping
        using ADC1_ETRGREG_RM = Field<PCFR, 1, 18, read_write>; // ADC 1 external trigger regular conversion remapping
        using USART1REMAP1 = Field<PCFR, 1, 21, read_write>;    // USART1 remapping
        using I2C1REMAP1 = Field<PCFR, 1, 22, read_write>;      // I2C1 remapping
        using TIM1_IREMAP = Field<PCFR, 1, 23, read_write>;     // TIM1_CH1 channel selection
        using SWCFG = Field<PCFR, 3, 24, write_only>;           // Serial wire JTAG
    };
    struct EXTICR : PackedRegister<AFIO_pack, RegBitSize::b32, 8 * 8> // External interrupt configuration register
    {
        using EXTI0 = Field<EXTICR, 2, 0, read_write>;  // EXTI0 configuration
        using EXTI1 = Field<EXTICR, 2, 2, read_write>;  // EXTI1 configuration
        using EXTI2 = Field<EXTICR, 2, 4, read_write>;  // EXTI2 configuration
        using EXTI3 = Field<EXTICR, 2, 6, read_write>;  // EXTI3 configuration
        using EXTI4 = Field<EXTICR, 2, 8, read_write>;  // EXTI4 configuration
        using EXTI5 = Field<EXTICR, 2, 10, read_write>; // EXTI5 configuration
        using EXTI6 = Field<EXTICR, 2, 12, read_write>; // EXTI6 configuration
        using EXTI7 = Field<EXTICR, 2, 14, read_write>; // EXTI7 configuration
    };
} // namespace AFIO
namespace EXTI
{
    using EXTI_pack = RegisterPack<0x40010400, 1024>;
    struct INTENR : PackedRegister<EXTI_pack, RegBitSize::b32, 0 * 8> // Interrupt mask register
    {
        using MR0 = Field<INTENR, 1, 0, read_write>; // Interrupt Mask on line 0
        using MR1 = Field<INTENR, 1, 1, read_write>; // Interrupt Mask on line 1
        using MR2 = Field<INTENR, 1, 2, read_write>; // Interrupt Mask on line 2
        using MR3 = Field<INTENR, 1, 3, read_write>; // Interrupt Mask on line 3
        using MR4 = Field<INTENR, 1, 4, read_write>; // Interrupt Mask on line 4
        using MR5 = Field<INTENR, 1, 5, read_write>; // Interrupt Mask on line 5
        using MR6 = Field<INTENR, 1, 6, read_write>; // Interrupt Mask on line 6
        using MR7 = Field<INTENR, 1, 7, read_write>; // Interrupt Mask on line 7
        using MR8 = Field<INTENR, 1, 8, read_write>; // Interrupt Mask on line 8
        using MR9 = Field<INTENR, 1, 9, read_write>; // Interrupt Mask on line 9
    };
    struct EVENR : PackedRegister<EXTI_pack, RegBitSize::b32, 4 * 8> // Event mask register (EXTI_EVENR)
    {
        using MR0 = Field<EVENR, 1, 0, read_write>; // Event Mask on line 0
        using MR1 = Field<EVENR, 1, 1, read_write>; // Event Mask on line 1
        using MR2 = Field<EVENR, 1, 2, read_write>; // Event Mask on line 2
        using MR3 = Field<EVENR, 1, 3, read_write>; // Event Mask on line 3
        using MR4 = Field<EVENR, 1, 4, read_write>; // Event Mask on line 4
        using MR5 = Field<EVENR, 1, 5, read_write>; // Event Mask on line 5
        using MR6 = Field<EVENR, 1, 6, read_write>; // Event Mask on line 6
        using MR7 = Field<EVENR, 1, 7, read_write>; // Event Mask on line 7
        using MR8 = Field<EVENR, 1, 8, read_write>; // Event Mask on line 8
        using MR9 = Field<EVENR, 1, 9, read_write>; // Event Mask on line 9
    };
    struct RTENR : PackedRegister<EXTI_pack, RegBitSize::b32, 8 * 8> // Rising Trigger selection register
    {
        using TR0 = Field<RTENR, 1, 0, read_write>; // Rising trigger event configuration of
        using TR1 = Field<RTENR, 1, 1, read_write>; // Rising trigger event configuration of
        using TR2 = Field<RTENR, 1, 2, read_write>; // Rising trigger event configuration of
        using TR3 = Field<RTENR, 1, 3, read_write>; // Rising trigger event configuration of
        using TR4 = Field<RTENR, 1, 4, read_write>; // Rising trigger event configuration of
        using TR5 = Field<RTENR, 1, 5, read_write>; // Rising trigger event configuration of
        using TR6 = Field<RTENR, 1, 6, read_write>; // Rising trigger event configuration of
        using TR7 = Field<RTENR, 1, 7, read_write>; // Rising trigger event configuration of
        using TR8 = Field<RTENR, 1, 8, read_write>; // Rising trigger event configuration of
        using TR9 = Field<RTENR, 1, 9, read_write>; // Rising trigger event configuration of
    };
    struct FTENR : PackedRegister<EXTI_pack, RegBitSize::b32, 12 * 8> // Falling Trigger selection register
    {
        using TR0 = Field<FTENR, 1, 0, read_write>; // Falling trigger event configuration of
        using TR1 = Field<FTENR, 1, 1, read_write>; // Falling trigger event configuration of
        using TR2 = Field<FTENR, 1, 2, read_write>; // Falling trigger event configuration of
        using TR3 = Field<FTENR, 1, 3, read_write>; // Falling trigger event configuration of
        using TR4 = Field<FTENR, 1, 4, read_write>; // Falling trigger event configuration of
        using TR5 = Field<FTENR, 1, 5, read_write>; // Falling trigger event configuration of
        using TR6 = Field<FTENR, 1, 6, read_write>; // Falling trigger event configuration of
        using TR7 = Field<FTENR, 1, 7, read_write>; // Falling trigger event configuration of
        using TR8 = Field<FTENR, 1, 8, read_write>; // Falling trigger event configuration of
        using TR9 = Field<FTENR, 1, 9, read_write>; // Falling trigger event configuration of
    };
    struct SWIEVR : PackedRegister<EXTI_pack, RegBitSize::b32, 16 * 8> // Software interrupt event register
    {
        using SWIER0 = Field<SWIEVR, 1, 0, read_write>; // Software Interrupt on line
        using SWIER1 = Field<SWIEVR, 1, 1, read_write>; // Software Interrupt on line
        using SWIER2 = Field<SWIEVR, 1, 2, read_write>; // Software Interrupt on line
        using SWIER3 = Field<SWIEVR, 1, 3, read_write>; // Software Interrupt on line
        using SWIER4 = Field<SWIEVR, 1, 4, read_write>; // Software Interrupt on line
        using SWIER5 = Field<SWIEVR, 1, 5, read_write>; // Software Interrupt on line
        using SWIER6 = Field<SWIEVR, 1, 6, read_write>; // Software Interrupt on line
        using SWIER7 = Field<SWIEVR, 1, 7, read_write>; // Software Interrupt on line
        using SWIER8 = Field<SWIEVR, 1, 8, read_write>; // Software Interrupt on line
        using SWIER9 = Field<SWIEVR, 1, 9, read_write>; // Software Interrupt on line
    };
    struct INTFR : PackedRegister<EXTI_pack, RegBitSize::b32, 20 * 8> // Pending register (EXTI_INTFR)
    {
        using PR0 = Field<INTFR, 1, 0, read_write>; // Pending bit 0
        using PR1 = Field<INTFR, 1, 1, read_write>; // Pending bit 1
        using PR2 = Field<INTFR, 1, 2, read_write>; // Pending bit 2
        using PR3 = Field<INTFR, 1, 3, read_write>; // Pending bit 3
        using PR4 = Field<INTFR, 1, 4, read_write>; // Pending bit 4
        using PR5 = Field<INTFR, 1, 5, read_write>; // Pending bit 5
        using PR6 = Field<INTFR, 1, 6, read_write>; // Pending bit 6
        using PR7 = Field<INTFR, 1, 7, read_write>; // Pending bit 7
        using PR8 = Field<INTFR, 1, 8, read_write>; // Pending bit 8
        using PR9 = Field<INTFR, 1, 9, read_write>; // Pending bit 9
    };
} // namespace EXTI
namespace DMA1
{
    using DMA1_pack = RegisterPack<0x40020000, 1024>;
    struct INTFR : PackedRegister<DMA1_pack, RegBitSize::b32, 0 * 8> // DMA interrupt status register
    {
        using GIF1 = Field<INTFR, 1, 0, read_only>;   // Channel 1 Global interrupt
        using TCIF1 = Field<INTFR, 1, 1, read_only>;  // Channel 1 Transfer Complete
        using HTIF1 = Field<INTFR, 1, 2, read_only>;  // Channel 1 Half Transfer Complete
        using TEIF1 = Field<INTFR, 1, 3, read_only>;  // Channel 1 Transfer Error
        using GIF2 = Field<INTFR, 1, 4, read_only>;   // Channel 2 Global interrupt
        using TCIF2 = Field<INTFR, 1, 5, read_only>;  // Channel 2 Transfer Complete
        using HTIF2 = Field<INTFR, 1, 6, read_only>;  // Channel 2 Half Transfer Complete
        using TEIF2 = Field<INTFR, 1, 7, read_only>;  // Channel 2 Transfer Error
        using GIF3 = Field<INTFR, 1, 8, read_only>;   // Channel 3 Global interrupt
        using TCIF3 = Field<INTFR, 1, 9, read_only>;  // Channel 3 Transfer Complete
        using HTIF3 = Field<INTFR, 1, 10, read_only>; // Channel 3 Half Transfer Complete
        using TEIF3 = Field<INTFR, 1, 11, read_only>; // Channel 3 Transfer Error
        using GIF4 = Field<INTFR, 1, 12, read_only>;  // Channel 4 Global interrupt
        using TCIF4 = Field<INTFR, 1, 13, read_only>; // Channel 4 Transfer Complete
        using HTIF4 = Field<INTFR, 1, 14, read_only>; // Channel 4 Half Transfer Complete
        using TEIF4 = Field<INTFR, 1, 15, read_only>; // Channel 4 Transfer Error
        using GIF5 = Field<INTFR, 1, 16, read_only>;  // Channel 5 Global interrupt
        using TCIF5 = Field<INTFR, 1, 17, read_only>; // Channel 5 Transfer Complete
        using HTIF5 = Field<INTFR, 1, 18, read_only>; // Channel 5 Half Transfer Complete
        using TEIF5 = Field<INTFR, 1, 19, read_only>; // Channel 5 Transfer Error
        using GIF6 = Field<INTFR, 1, 20, read_only>;  // Channel 6 Global interrupt
        using TCIF6 = Field<INTFR, 1, 21, read_only>; // Channel 6 Transfer Complete
        using HTIF6 = Field<INTFR, 1, 22, read_only>; // Channel 6 Half Transfer Complete
        using TEIF6 = Field<INTFR, 1, 23, read_only>; // Channel 6 Transfer Error
        using GIF7 = Field<INTFR, 1, 24, read_only>;  // Channel 7 Global interrupt
        using TCIF7 = Field<INTFR, 1, 25, read_only>; // Channel 7 Transfer Complete
        using HTIF7 = Field<INTFR, 1, 26, read_only>; // Channel 7 Half Transfer Complete
        using TEIF7 = Field<INTFR, 1, 27, read_only>; // Channel 7 Transfer Error
    };
    struct INTFCR : PackedRegister<DMA1_pack, RegBitSize::b32, 4 * 8> // DMA interrupt flag clear register
    {
        using CGIF1 = Field<INTFCR, 1, 0, write_only>;   // Channel 1 Global interrupt
        using CGIF2 = Field<INTFCR, 1, 4, write_only>;   // Channel 2 Global interrupt
        using CGIF3 = Field<INTFCR, 1, 8, write_only>;   // Channel 3 Global interrupt
        using CGIF4 = Field<INTFCR, 1, 12, write_only>;  // Channel 4 Global interrupt
        using CGIF5 = Field<INTFCR, 1, 16, write_only>;  // Channel 5 Global interrupt
        using CGIF6 = Field<INTFCR, 1, 20, write_only>;  // Channel 6 Global interrupt
        using CGIF7 = Field<INTFCR, 1, 24, write_only>;  // Channel 7 Global interrupt
        using CTCIF1 = Field<INTFCR, 1, 1, write_only>;  // Channel 1 Transfer Complete
        using CTCIF2 = Field<INTFCR, 1, 5, write_only>;  // Channel 2 Transfer Complete
        using CTCIF3 = Field<INTFCR, 1, 9, write_only>;  // Channel 3 Transfer Complete
        using CTCIF4 = Field<INTFCR, 1, 13, write_only>; // Channel 4 Transfer Complete
        using CTCIF5 = Field<INTFCR, 1, 17, write_only>; // Channel 5 Transfer Complete
        using CTCIF6 = Field<INTFCR, 1, 21, write_only>; // Channel 6 Transfer Complete
        using CTCIF7 = Field<INTFCR, 1, 25, write_only>; // Channel 7 Transfer Complete
        using CHTIF1 = Field<INTFCR, 1, 2, write_only>;  // Channel 1 Half Transfer
        using CHTIF2 = Field<INTFCR, 1, 6, write_only>;  // Channel 2 Half Transfer
        using CHTIF3 = Field<INTFCR, 1, 10, write_only>; // Channel 3 Half Transfer
        using CHTIF4 = Field<INTFCR, 1, 14, write_only>; // Channel 4 Half Transfer
        using CHTIF5 = Field<INTFCR, 1, 18, write_only>; // Channel 5 Half Transfer
        using CHTIF6 = Field<INTFCR, 1, 22, write_only>; // Channel 6 Half Transfer
        using CHTIF7 = Field<INTFCR, 1, 26, write_only>; // Channel 7 Half Transfer
        using CTEIF1 = Field<INTFCR, 1, 3, write_only>;  // Channel 1 Transfer Error
        using CTEIF2 = Field<INTFCR, 1, 7, write_only>;  // Channel 2 Transfer Error
        using CTEIF3 = Field<INTFCR, 1, 11, write_only>; // Channel 3 Transfer Error
        using CTEIF4 = Field<INTFCR, 1, 15, write_only>; // Channel 4 Transfer Error
        using CTEIF5 = Field<INTFCR, 1, 19, write_only>; // Channel 5 Transfer Error
        using CTEIF6 = Field<INTFCR, 1, 23, write_only>; // Channel 6 Transfer Error
        using CTEIF7 = Field<INTFCR, 1, 27, write_only>; // Channel 7 Transfer Error
    };
    struct CFGR1 : PackedRegister<DMA1_pack, RegBitSize::b32, 8 * 8> // DMA channel configuration register
    {
        using EN = Field<CFGR1, 1, 0, read_write>;       // Channel enable
        using TCIE = Field<CFGR1, 1, 1, read_write>;     // Transfer complete interrupt
        using HTIE = Field<CFGR1, 1, 2, read_write>;     // Half Transfer interrupt
        using TEIE = Field<CFGR1, 1, 3, read_write>;     // Transfer error interrupt
        using DIR = Field<CFGR1, 1, 4, read_write>;      // Data transfer direction
        using CIRC = Field<CFGR1, 1, 5, read_write>;     // Circular mode
        using PINC = Field<CFGR1, 1, 6, read_write>;     // Peripheral increment mode
        using MINC = Field<CFGR1, 1, 7, read_write>;     // Memory increment mode
        using PSIZE = Field<CFGR1, 2, 8, read_write>;    // Peripheral size
        using MSIZE = Field<CFGR1, 2, 10, read_write>;   // Memory size
        using PL = Field<CFGR1, 2, 12, read_write>;      // Channel Priority level
        using MEM2MEM = Field<CFGR1, 1, 14, read_write>; // Memory to memory mode
    };
    struct CNTR1 : PackedRegister<DMA1_pack, RegBitSize::b32, 12 * 8> // DMA channel 1 number of data
    {
        using NDT = Field<CNTR1, 16, 0, read_write>; // Number of data to transfer
    };
    struct PADDR1 : PackedRegister<DMA1_pack, RegBitSize::b32, 16 * 8> // DMA channel 1 peripheral address
    {
        using PA = Field<PADDR1, 32, 0, read_write>; // Peripheral address
    };
    struct MADDR1 : PackedRegister<DMA1_pack, RegBitSize::b32, 20 * 8> // DMA channel 1 memory address
    {
        using MA = Field<MADDR1, 32, 0, read_write>; // Memory address
    };
    struct CFGR2 : PackedRegister<DMA1_pack, RegBitSize::b32, 28 * 8> // DMA channel configuration register
    {
        using EN = Field<CFGR2, 1, 0, read_write>;       // Channel enable
        using TCIE = Field<CFGR2, 1, 1, read_write>;     // Transfer complete interrupt
        using HTIE = Field<CFGR2, 1, 2, read_write>;     // Half Transfer interrupt
        using TEIE = Field<CFGR2, 1, 3, read_write>;     // Transfer error interrupt
        using DIR = Field<CFGR2, 1, 4, read_write>;      // Data transfer direction
        using CIRC = Field<CFGR2, 1, 5, read_write>;     // Circular mode
        using PINC = Field<CFGR2, 1, 6, read_write>;     // Peripheral increment mode
        using MINC = Field<CFGR2, 1, 7, read_write>;     // Memory increment mode
        using PSIZE = Field<CFGR2, 2, 8, read_write>;    // Peripheral size
        using MSIZE = Field<CFGR2, 2, 10, read_write>;   // Memory size
        using PL = Field<CFGR2, 2, 12, read_write>;      // Channel Priority level
        using MEM2MEM = Field<CFGR2, 1, 14, read_write>; // Memory to memory mode
    };
    struct CNTR2 : PackedRegister<DMA1_pack, RegBitSize::b32, 32 * 8> // DMA channel 2 number of data
    {
        using NDT = Field<CNTR2, 16, 0, read_write>; // Number of data to transfer
    };
    struct PADDR2 : PackedRegister<DMA1_pack, RegBitSize::b32, 36 * 8> // DMA channel 2 peripheral address
    {
        using PA = Field<PADDR2, 32, 0, read_write>; // Peripheral address
    };
    struct MADDR2 : PackedRegister<DMA1_pack, RegBitSize::b32, 40 * 8> // DMA channel 2 memory address
    {
        using MA = Field<MADDR2, 32, 0, read_write>; // Memory address
    };
    struct CFGR3 : PackedRegister<DMA1_pack, RegBitSize::b32, 48 * 8> // DMA channel configuration register
    {
        using EN = Field<CFGR3, 1, 0, read_write>;       // Channel enable
        using TCIE = Field<CFGR3, 1, 1, read_write>;     // Transfer complete interrupt
        using HTIE = Field<CFGR3, 1, 2, read_write>;     // Half Transfer interrupt
        using TEIE = Field<CFGR3, 1, 3, read_write>;     // Transfer error interrupt
        using DIR = Field<CFGR3, 1, 4, read_write>;      // Data transfer direction
        using CIRC = Field<CFGR3, 1, 5, read_write>;     // Circular mode
        using PINC = Field<CFGR3, 1, 6, read_write>;     // Peripheral increment mode
        using MINC = Field<CFGR3, 1, 7, read_write>;     // Memory increment mode
        using PSIZE = Field<CFGR3, 2, 8, read_write>;    // Peripheral size
        using MSIZE = Field<CFGR3, 2, 10, read_write>;   // Memory size
        using PL = Field<CFGR3, 2, 12, read_write>;      // Channel Priority level
        using MEM2MEM = Field<CFGR3, 1, 14, read_write>; // Memory to memory mode
    };
    struct CNTR3 : PackedRegister<DMA1_pack, RegBitSize::b32, 52 * 8> // DMA channel 3 number of data
    {
        using NDT = Field<CNTR3, 16, 0, read_write>; // Number of data to transfer
    };
    struct PADDR3 : PackedRegister<DMA1_pack, RegBitSize::b32, 56 * 8> // DMA channel 3 peripheral address
    {
        using PA = Field<PADDR3, 32, 0, read_write>; // Peripheral address
    };
    struct MADDR3 : PackedRegister<DMA1_pack, RegBitSize::b32, 60 * 8> // DMA channel 3 memory address
    {
        using MA = Field<MADDR3, 32, 0, read_write>; // Memory address
    };
    struct CFGR4 : PackedRegister<DMA1_pack, RegBitSize::b32, 68 * 8> // DMA channel configuration register
    {
        using EN = Field<CFGR4, 1, 0, read_write>;       // Channel enable
        using TCIE = Field<CFGR4, 1, 1, read_write>;     // Transfer complete interrupt
        using HTIE = Field<CFGR4, 1, 2, read_write>;     // Half Transfer interrupt
        using TEIE = Field<CFGR4, 1, 3, read_write>;     // Transfer error interrupt
        using DIR = Field<CFGR4, 1, 4, read_write>;      // Data transfer direction
        using CIRC = Field<CFGR4, 1, 5, read_write>;     // Circular mode
        using PINC = Field<CFGR4, 1, 6, read_write>;     // Peripheral increment mode
        using MINC = Field<CFGR4, 1, 7, read_write>;     // Memory increment mode
        using PSIZE = Field<CFGR4, 2, 8, read_write>;    // Peripheral size
        using MSIZE = Field<CFGR4, 2, 10, read_write>;   // Memory size
        using PL = Field<CFGR4, 2, 12, read_write>;      // Channel Priority level
        using MEM2MEM = Field<CFGR4, 1, 14, read_write>; // Memory to memory mode
    };
    struct CNTR4 : PackedRegister<DMA1_pack, RegBitSize::b32, 72 * 8> // DMA channel 4 number of data
    {
        using NDT = Field<CNTR4, 16, 0, read_write>; // Number of data to transfer
    };
    struct PADDR4 : PackedRegister<DMA1_pack, RegBitSize::b32, 76 * 8> // DMA channel 4 peripheral address
    {
        using PA = Field<PADDR4, 32, 0, read_write>; // Peripheral address
    };
    struct MADDR4 : PackedRegister<DMA1_pack, RegBitSize::b32, 80 * 8> // DMA channel 4 memory address
    {
        using MA = Field<MADDR4, 32, 0, read_write>; // Memory address
    };
    struct CFGR5 : PackedRegister<DMA1_pack, RegBitSize::b32, 88 * 8> // DMA channel configuration register
    {
        using EN = Field<CFGR5, 1, 0, read_write>;       // Channel enable
        using TCIE = Field<CFGR5, 1, 1, read_write>;     // Transfer complete interrupt
        using HTIE = Field<CFGR5, 1, 2, read_write>;     // Half Transfer interrupt
        using TEIE = Field<CFGR5, 1, 3, read_write>;     // Transfer error interrupt
        using DIR = Field<CFGR5, 1, 4, read_write>;      // Data transfer direction
        using CIRC = Field<CFGR5, 1, 5, read_write>;     // Circular mode
        using PINC = Field<CFGR5, 1, 6, read_write>;     // Peripheral increment mode
        using MINC = Field<CFGR5, 1, 7, read_write>;     // Memory increment mode
        using PSIZE = Field<CFGR5, 2, 8, read_write>;    // Peripheral size
        using MSIZE = Field<CFGR5, 2, 10, read_write>;   // Memory size
        using PL = Field<CFGR5, 2, 12, read_write>;      // Channel Priority level
        using MEM2MEM = Field<CFGR5, 1, 14, read_write>; // Memory to memory mode
    };
    struct CNTR5 : PackedRegister<DMA1_pack, RegBitSize::b32, 92 * 8> // DMA channel 5 number of data
    {
        using NDT = Field<CNTR5, 16, 0, read_write>; // Number of data to transfer
    };
    struct PADDR5 : PackedRegister<DMA1_pack, RegBitSize::b32, 96 * 8> // DMA channel 5 peripheral address
    {
        using PA = Field<PADDR5, 32, 0, read_write>; // Peripheral address
    };
    struct MADDR5 : PackedRegister<DMA1_pack, RegBitSize::b32, 100 * 8> // DMA channel 5 memory address
    {
        using MA = Field<MADDR5, 32, 0, read_write>; // Memory address
    };
    struct CFGR6 : PackedRegister<DMA1_pack, RegBitSize::b32, 108 * 8> // DMA channel configuration register
    {
        using EN = Field<CFGR6, 1, 0, read_write>;       // Channel enable
        using TCIE = Field<CFGR6, 1, 1, read_write>;     // Transfer complete interrupt
        using HTIE = Field<CFGR6, 1, 2, read_write>;     // Half Transfer interrupt
        using TEIE = Field<CFGR6, 1, 3, read_write>;     // Transfer error interrupt
        using DIR = Field<CFGR6, 1, 4, read_write>;      // Data transfer direction
        using CIRC = Field<CFGR6, 1, 5, read_write>;     // Circular mode
        using PINC = Field<CFGR6, 1, 6, read_write>;     // Peripheral increment mode
        using MINC = Field<CFGR6, 1, 7, read_write>;     // Memory increment mode
        using PSIZE = Field<CFGR6, 2, 8, read_write>;    // Peripheral size
        using MSIZE = Field<CFGR6, 2, 10, read_write>;   // Memory size
        using PL = Field<CFGR6, 2, 12, read_write>;      // Channel Priority level
        using MEM2MEM = Field<CFGR6, 1, 14, read_write>; // Memory to memory mode
    };
    struct CNTR6 : PackedRegister<DMA1_pack, RegBitSize::b32, 112 * 8> // DMA channel 6 number of data
    {
        using NDT = Field<CNTR6, 16, 0, read_write>; // Number of data to transfer
    };
    struct PADDR6 : PackedRegister<DMA1_pack, RegBitSize::b32, 116 * 8> // DMA channel 6 peripheral address
    {
        using PA = Field<PADDR6, 32, 0, read_write>; // Peripheral address
    };
    struct MADDR6 : PackedRegister<DMA1_pack, RegBitSize::b32, 120 * 8> // DMA channel 6 memory address
    {
        using MA = Field<MADDR6, 32, 0, read_write>; // Memory address
    };
    struct CFGR7 : PackedRegister<DMA1_pack, RegBitSize::b32, 128 * 8> // DMA channel configuration register
    {
        using EN = Field<CFGR7, 1, 0, read_write>;       // Channel enable
        using TCIE = Field<CFGR7, 1, 1, read_write>;     // Transfer complete interrupt
        using HTIE = Field<CFGR7, 1, 2, read_write>;     // Half Transfer interrupt
        using TEIE = Field<CFGR7, 1, 3, read_write>;     // Transfer error interrupt
        using DIR = Field<CFGR7, 1, 4, read_write>;      // Data transfer direction
        using CIRC = Field<CFGR7, 1, 5, read_write>;     // Circular mode
        using PINC = Field<CFGR7, 1, 6, read_write>;     // Peripheral increment mode
        using MINC = Field<CFGR7, 1, 7, read_write>;     // Memory increment mode
        using PSIZE = Field<CFGR7, 2, 8, read_write>;    // Peripheral size
        using MSIZE = Field<CFGR7, 2, 10, read_write>;   // Memory size
        using PL = Field<CFGR7, 2, 12, read_write>;      // Channel Priority level
        using MEM2MEM = Field<CFGR7, 1, 14, read_write>; // Memory to memory mode
    };
    struct CNTR7 : PackedRegister<DMA1_pack, RegBitSize::b32, 132 * 8> // DMA channel 7 number of data
    {
        using NDT = Field<CNTR7, 16, 0, read_write>; // Number of data to transfer
    };
    struct PADDR7 : PackedRegister<DMA1_pack, RegBitSize::b32, 136 * 8> // DMA channel 7 peripheral address
    {
        using PA = Field<PADDR7, 32, 0, read_write>; // Peripheral address
    };
    struct MADDR7 : PackedRegister<DMA1_pack, RegBitSize::b32, 140 * 8> // DMA channel 7 memory address
    {
        using MA = Field<MADDR7, 32, 0, read_write>; // Memory address
    };
} // namespace DMA1
namespace IWDG
{
    using IWDG_pack = RegisterPack<0x40003000, 1024>;
    struct CTLR : PackedRegister<IWDG_pack, RegBitSize::b32, 0 * 8> // Key register (IWDG_CTLR)
    {
        using KEY = Field<CTLR, 16, 0, write_only>; // Key value
    };
    struct PSCR : PackedRegister<IWDG_pack, RegBitSize::b32, 4 * 8> // Prescaler register (IWDG_PSCR)
    {
        using PR = Field<PSCR, 3, 0, read_write>; // Prescaler divider
    };
    struct RLDR : PackedRegister<IWDG_pack, RegBitSize::b32, 8 * 8> // Reload register (IWDG_RLDR)
    {
        using RL = Field<RLDR, 12, 0, read_write>; // Watchdog counter reload
    };
    struct STATR : PackedRegister<IWDG_pack, RegBitSize::b32, 12 * 8> // Status register (IWDG_SR)
    {
        using PVU = Field<STATR, 1, 0, read_only>; // Watchdog prescaler value
        using RVU = Field<STATR, 1, 1, read_only>; // Watchdog counter reload value
    };
} // namespace IWDG
namespace WWDG
{
    using WWDG_pack = RegisterPack<0x40002c00, 1024>;
    struct CTLR : PackedRegister<WWDG_pack, RegBitSize::b32, 0 * 8> // Control register (WWDG_CR)
    {
        using T = Field<CTLR, 7, 0, read_write>;    // 7-bit counter (MSB to LSB)
        using WDGA = Field<CTLR, 1, 7, read_write>; // Activation bit
    };
    struct CFGR : PackedRegister<WWDG_pack, RegBitSize::b32, 4 * 8> // Configuration register
    {
        using W = Field<CFGR, 7, 0, read_write>;     // 7-bit window value
        using WDGTB = Field<CFGR, 2, 7, read_write>; // Timer Base
        using EWI = Field<CFGR, 1, 9, read_write>;   // Early Wakeup Interrupt
    };
    struct STATR : PackedRegister<WWDG_pack, RegBitSize::b32, 8 * 8> // Status register (WWDG_SR)
    {
        using WEIF = Field<STATR, 1, 0, read_write>; // Early Wakeup Interrupt Flag
    };
} // namespace WWDG
namespace TIM1
{
    using TIM1_pack = RegisterPack<0x40012c00, 1024>;
    struct CTLR1 : PackedRegister<TIM1_pack, RegBitSize::b32, 0 * 8> // control register 1
    {
        using TMR_CAP_LVL_EN = Field<CTLR1, 1, 15, read_write>; // Timer capture level indication
        using TMR_CAP_OV_EN = Field<CTLR1, 1, 14, read_write>;  // Timer capture value configuration
        using CKD = Field<CTLR1, 2, 8, read_write>;             // Clock division
        using ARPE = Field<CTLR1, 1, 7, read_write>;            // Auto-reload preload enable
        using CMS = Field<CTLR1, 2, 5, read_write>;             // Center-aligned mode
        using DIR = Field<CTLR1, 1, 4, read_write>;             // Direction
        using OPM = Field<CTLR1, 1, 3, read_write>;             // One-pulse mode
        using URS = Field<CTLR1, 1, 2, read_write>;             // Update request source
        using UDIS = Field<CTLR1, 1, 1, read_write>;            // Update disable
        using CEN = Field<CTLR1, 1, 0, read_write>;             // Counter enable
    };
    struct CTLR2 : PackedRegister<TIM1_pack, RegBitSize::b32, 4 * 8> // control register 2
    {
        using OIS4 = Field<CTLR2, 1, 14, read_write>;  // Output Idle state 4
        using OIS3N = Field<CTLR2, 1, 13, read_write>; // Output Idle state 3
        using OIS3 = Field<CTLR2, 1, 12, read_write>;  // Output Idle state 3
        using OIS2N = Field<CTLR2, 1, 11, read_write>; // Output Idle state 2
        using OIS2 = Field<CTLR2, 1, 10, read_write>;  // Output Idle state 2
        using OIS1N = Field<CTLR2, 1, 9, read_write>;  // Output Idle state 1
        using OIS1 = Field<CTLR2, 1, 8, read_write>;   // Output Idle state 1
        using TI1S = Field<CTLR2, 1, 7, read_write>;   // TI1 selection
        using MMS = Field<CTLR2, 3, 4, read_write>;    // Master mode selection
        using CCDS = Field<CTLR2, 1, 3, read_write>;   // Capture/compare DMA
        using CCUS = Field<CTLR2, 1, 2, read_write>;   // Capture/compare control update
        using CCPC = Field<CTLR2, 1, 0, read_write>;   // Capture/compare preloaded
    };
    struct SMCFGR : PackedRegister<TIM1_pack, RegBitSize::b32, 8 * 8> // slave mode control register
    {
        using ETP = Field<SMCFGR, 1, 15, read_only>;   // External trigger polarity
        using ECE = Field<SMCFGR, 1, 14, read_write>;  // External clock enable
        using ETPS = Field<SMCFGR, 2, 12, read_write>; // External trigger prescaler
        using ETF = Field<SMCFGR, 4, 8, read_write>;   // External trigger filter
        using MSM = Field<SMCFGR, 1, 7, read_write>;   // Master/Slave mode
        using TS = Field<SMCFGR, 3, 4, read_write>;    // Trigger selection
        using SMS = Field<SMCFGR, 3, 0, read_write>;   // Slave mode selection
    };
    struct DMAINTENR : PackedRegister<TIM1_pack, RegBitSize::b32, 12 * 8> // DMA/Interrupt enable register
    {
        using TDE = Field<DMAINTENR, 1, 14, read_write>;   // Trigger DMA request enable
        using COMDE = Field<DMAINTENR, 1, 13, read_write>; // COM DMA request enable
        using CC4DE = Field<DMAINTENR, 1, 12, read_write>; // Capture/Compare 4 DMA request
        using CC3DE = Field<DMAINTENR, 1, 11, read_write>; // Capture/Compare 3 DMA request
        using CC2DE = Field<DMAINTENR, 1, 10, read_write>; // Capture/Compare 2 DMA request
        using CC1DE = Field<DMAINTENR, 1, 9, read_write>;  // Capture/Compare 1 DMA request
        using UDE = Field<DMAINTENR, 1, 8, read_write>;    // Update DMA request enable
        using BIE = Field<DMAINTENR, 1, 7, read_write>;    // Break interrupt enable
        using TIE = Field<DMAINTENR, 1, 6, read_write>;    // Trigger interrupt enable
        using COMIE = Field<DMAINTENR, 1, 5, read_write>;  // COM interrupt enable
        using CC4IE = Field<DMAINTENR, 1, 4, read_write>;  // Capture/Compare 4 interrupt
        using CC3IE = Field<DMAINTENR, 1, 3, read_write>;  // Capture/Compare 3 interrupt
        using CC2IE = Field<DMAINTENR, 1, 2, read_write>;  // Capture/Compare 2 interrupt
        using CC1IE = Field<DMAINTENR, 1, 1, read_write>;  // Capture/Compare 1 interrupt
        using UIE = Field<DMAINTENR, 1, 0, read_write>;    // Update interrupt enable
    };
    struct INTFR : PackedRegister<TIM1_pack, RegBitSize::b32, 16 * 8> // status register
    {
        using CC4OF = Field<INTFR, 1, 12, read_write>; // Capture/Compare 4 overcapture
        using CC3OF = Field<INTFR, 1, 11, read_write>; // Capture/Compare 3 overcapture
        using CC2OF = Field<INTFR, 1, 10, read_write>; // Capture/compare 2 overcapture
        using CC1OF = Field<INTFR, 1, 9, read_write>;  // Capture/Compare 1 overcapture
        using BIF = Field<INTFR, 1, 7, read_write>;    // Break interrupt flag
        using TIF = Field<INTFR, 1, 6, read_write>;    // Trigger interrupt flag
        using COMIF = Field<INTFR, 1, 5, read_write>;  // COM interrupt flag
        using CC4IF = Field<INTFR, 1, 4, read_write>;  // Capture/Compare 4 interrupt
        using CC3IF = Field<INTFR, 1, 3, read_write>;  // Capture/Compare 3 interrupt
        using CC2IF = Field<INTFR, 1, 2, read_write>;  // Capture/Compare 2 interrupt
        using CC1IF = Field<INTFR, 1, 1, read_write>;  // Capture/compare 1 interrupt
        using UIF = Field<INTFR, 1, 0, read_write>;    // Update interrupt flag
    };
    struct SWEVGR : PackedRegister<TIM1_pack, RegBitSize::b32, 20 * 8> // event generation register
    {
        using BG = Field<SWEVGR, 1, 7, write_only>;   // Break generation
        using TG = Field<SWEVGR, 1, 6, write_only>;   // Trigger generation
        using COMG = Field<SWEVGR, 1, 5, write_only>; // Capture/Compare control update
        using CC4G = Field<SWEVGR, 1, 4, write_only>; // Capture/compare 4
        using CC3G = Field<SWEVGR, 1, 3, write_only>; // Capture/compare 3
        using CC2G = Field<SWEVGR, 1, 2, write_only>; // Capture/compare 2
        using CC1G = Field<SWEVGR, 1, 1, write_only>; // Capture/compare 1
        using UG = Field<SWEVGR, 1, 0, write_only>;   // Update generation
    };
    struct CHCTLR1_Output : PackedRegister<TIM1_pack, RegBitSize::b32, 24 * 8> // capture/compare mode register (output
    {
        using OC2CE = Field<CHCTLR1_Output, 1, 15, read_write>; // Output Compare 2 clear
        using OC2M = Field<CHCTLR1_Output, 3, 12, read_write>;  // Output Compare 2 mode
        using OC2PE = Field<CHCTLR1_Output, 1, 11, read_write>; // Output Compare 2 preload
        using OC2FE = Field<CHCTLR1_Output, 1, 10, read_write>; // Output Compare 2 fast
        using CC2S = Field<CHCTLR1_Output, 2, 8, read_write>;   // Capture/Compare 2
        using OC1CE = Field<CHCTLR1_Output, 1, 7, read_write>;  // Output Compare 1 clear
        using OC1M = Field<CHCTLR1_Output, 3, 4, read_write>;   // Output Compare 1 mode
        using OC1PE = Field<CHCTLR1_Output, 1, 3, read_write>;  // Output Compare 1 preload
        using OC1FE = Field<CHCTLR1_Output, 1, 2, read_write>;  // Output Compare 1 fast
        using CC1S = Field<CHCTLR1_Output, 2, 0, read_write>;   // Capture/Compare 1
    };
    struct CHCTLR1_Input : PackedRegister<TIM1_pack, RegBitSize::b32, 24 * 8> // capture/compare mode register 1 (input
    {
        using IC2F = Field<CHCTLR1_Input, 4, 12, read_write>;   // Input capture 2 filter
        using IC2PCS = Field<CHCTLR1_Input, 2, 10, read_write>; // Input capture 2 prescaler
        using CC2S = Field<CHCTLR1_Input, 2, 8, read_write>;    // Capture/Compare 2
        using IC1F = Field<CHCTLR1_Input, 4, 4, read_write>;    // Input capture 1 filter
        using IC1PSC = Field<CHCTLR1_Input, 2, 2, read_write>;  // Input capture 1 prescaler
        using CC1S = Field<CHCTLR1_Input, 2, 0, read_write>;    // Capture/Compare 1
    };
    struct CHCTLR2_Output : PackedRegister<TIM1_pack, RegBitSize::b32, 28 * 8> // capture/compare mode register (output
    {
        using OC4CE = Field<CHCTLR2_Output, 1, 15, read_write>; // Output compare 4 clear
        using OC4M = Field<CHCTLR2_Output, 3, 12, read_write>;  // Output compare 4 mode
        using OC4PE = Field<CHCTLR2_Output, 1, 11, read_write>; // Output compare 4 preload
        using OC4FE = Field<CHCTLR2_Output, 1, 10, read_write>; // Output compare 4 fast
        using CC4S = Field<CHCTLR2_Output, 2, 8, read_write>;   // Capture/Compare 4
        using OC3CE = Field<CHCTLR2_Output, 1, 7, read_write>;  // Output compare 3 clear
        using OC3M = Field<CHCTLR2_Output, 3, 4, read_write>;   // Output compare 3 mode
        using OC3PE = Field<CHCTLR2_Output, 1, 3, read_write>;  // Output compare 3 preload
        using OC3FE = Field<CHCTLR2_Output, 1, 2, read_write>;  // Output compare 3 fast
        using CC3S = Field<CHCTLR2_Output, 2, 0, read_write>;   // Capture/Compare 3
    };
    struct CHCTLR2_Input : PackedRegister<TIM1_pack, RegBitSize::b32, 28 * 8> // capture/compare mode register 2 (input
    {
        using IC4F = Field<CHCTLR2_Input, 4, 12, read_write>;   // Input capture 4 filter
        using IC4PSC = Field<CHCTLR2_Input, 2, 10, read_write>; // Input capture 4 prescaler
        using CC4S = Field<CHCTLR2_Input, 2, 8, read_write>;    // Capture/Compare 4
        using IC3F = Field<CHCTLR2_Input, 4, 4, read_write>;    // Input capture 3 filter
        using IC3PSC = Field<CHCTLR2_Input, 2, 2, read_write>;  // Input capture 3 prescaler
        using CC3S = Field<CHCTLR2_Input, 2, 0, read_write>;    // Capture/compare 3
    };
    struct CCER : PackedRegister<TIM1_pack, RegBitSize::b32, 32 * 8> // capture/compare enable
    {
        using CC4P = Field<CCER, 1, 13, read_write>;  // Capture/Compare 3 output
        using CC4E = Field<CCER, 1, 12, read_write>;  // Capture/Compare 4 output
        using CC3NP = Field<CCER, 1, 11, read_write>; // Capture/Compare 3 output
        using CC3NE = Field<CCER, 1, 10, read_write>; // Capture/Compare 3 complementary output
        using CC3P = Field<CCER, 1, 9, read_write>;   // Capture/Compare 3 output
        using CC3E = Field<CCER, 1, 8, read_write>;   // Capture/Compare 3 output
        using CC2NP = Field<CCER, 1, 7, read_write>;  // Capture/Compare 2 output
        using CC2NE = Field<CCER, 1, 6, read_write>;  // Capture/Compare 2 complementary output
        using CC2P = Field<CCER, 1, 5, read_write>;   // Capture/Compare 2 output
        using CC2E = Field<CCER, 1, 4, read_write>;   // Capture/Compare 2 output
        using CC1NP = Field<CCER, 1, 3, read_write>;  // Capture/Compare 1 output
        using CC1NE = Field<CCER, 1, 2, read_write>;  // Capture/Compare 1 complementary output
        using CC1P = Field<CCER, 1, 1, read_write>;   // Capture/Compare 1 output
        using CC1E = Field<CCER, 1, 0, read_write>;   // Capture/Compare 1 output
    };
    struct CNT : PackedRegister<TIM1_pack, RegBitSize::b32, 36 * 8> // counter
    {
        using CNTfield = Field<CNT, 16, 0, read_write>; // counter value
    };
    struct PSC : PackedRegister<TIM1_pack, RegBitSize::b32, 40 * 8> // prescaler
    {
        using PSCfield = Field<PSC, 16, 0, read_write>; // Prescaler value
    };
    struct ATRLR : PackedRegister<TIM1_pack, RegBitSize::b32, 44 * 8> // auto-reload register
    {
        using ATRLRfield = Field<ATRLR, 16, 0, read_write>; // Auto-reload value
    };
    struct RPTCR : PackedRegister<TIM1_pack, RegBitSize::b32, 48 * 8> // repetition counter register
    {
        using RPTCRfield = Field<RPTCR, 8, 0, read_write>; // Repetition counter value
    };
    struct CH1CVR : PackedRegister<TIM1_pack, RegBitSize::b32, 52 * 8> // capture/compare register 1
    {
        using CH1CVRfield = Field<CH1CVR, 16, 0, read_write>; // Capture/Compare 1 value
    };
    struct CH2CVR : PackedRegister<TIM1_pack, RegBitSize::b32, 56 * 8> // capture/compare register 2
    {
        using CH2CVRfield = Field<CH2CVR, 16, 0, read_write>; // Capture/Compare 2 value
    };
    struct CH3CVR : PackedRegister<TIM1_pack, RegBitSize::b32, 60 * 8> // capture/compare register 3
    {
        using CH3CVRfield = Field<CH3CVR, 16, 0, read_write>; // Capture/Compare value
    };
    struct CH4CVR : PackedRegister<TIM1_pack, RegBitSize::b32, 64 * 8> // capture/compare register 4
    {
        using CH4CVRfield = Field<CH4CVR, 16, 0, read_write>; // Capture/Compare value
    };
    struct BDTR : PackedRegister<TIM1_pack, RegBitSize::b32, 68 * 8> // break and dead-time register
    {
        using MOE = Field<BDTR, 1, 15, read_write>;  // Main output enable
        using AOE = Field<BDTR, 1, 14, read_write>;  // Automatic output enable
        using BKP = Field<BDTR, 1, 13, read_write>;  // Break polarity
        using BKE = Field<BDTR, 1, 12, read_write>;  // Break enable
        using OSSR = Field<BDTR, 1, 11, read_write>; // Off-state selection for Run
        using OSSI = Field<BDTR, 1, 10, read_write>; // Off-state selection for Idle
        using LOCK = Field<BDTR, 2, 8, read_write>;  // Lock configuration
        using DTG = Field<BDTR, 8, 0, read_write>;   // Dead-time generator setup
    };
    struct DMACFGR : PackedRegister<TIM1_pack, RegBitSize::b32, 72 * 8> // DMA control register
    {
        using DBL = Field<DMACFGR, 5, 8, read_write>; // DMA burst length
        using DBA = Field<DMACFGR, 5, 0, read_write>; // DMA base address
    };
    struct DMAADR : PackedRegister<TIM1_pack, RegBitSize::b32, 76 * 8> // DMA address for full transfer
    {
        using DMAADRfield = Field<DMAADR, 16, 0, read_write>; // DMA register for burst
    };
} // namespace TIM1
namespace TIM2
{
    using TIM2_pack = RegisterPack<0x40000000, 1024>;
    struct CTLR1 : PackedRegister<TIM2_pack, RegBitSize::b32, 0 * 8> // control register 1
    {
        using TMR_CAP_LVL_EN = Field<CTLR1, 1, 15, read_write>; // Timer capture level indication
        using TMR_CAP_OV_EN = Field<CTLR1, 1, 14, read_write>;  // Timer capture value configuration
        using CKD = Field<CTLR1, 2, 8, read_write>;             // Clock division
        using ARPE = Field<CTLR1, 1, 7, read_write>;            // Auto-reload preload enable
        using CMS = Field<CTLR1, 2, 5, read_write>;             // Center-aligned mode
        using DIR = Field<CTLR1, 1, 4, read_write>;             // Direction
        using OPM = Field<CTLR1, 1, 3, read_write>;             // One-pulse mode
        using URS = Field<CTLR1, 1, 2, read_write>;             // Update request source
        using UDIS = Field<CTLR1, 1, 1, read_write>;            // Update disable
        using CEN = Field<CTLR1, 1, 0, read_write>;             // Counter enable
    };
    struct CTLR2 : PackedRegister<TIM2_pack, RegBitSize::b32, 4 * 8> // control register 2
    {
        using TI1S = Field<CTLR2, 1, 7, read_write>; // TI1 selection
        using MMS = Field<CTLR2, 3, 4, read_write>;  // Master mode selection
        using CCDS = Field<CTLR2, 1, 3, read_write>; // Capture/compare DMA
    };
    struct SMCFGR : PackedRegister<TIM2_pack, RegBitSize::b32, 8 * 8> // slave mode control register
    {
        using ETP = Field<SMCFGR, 1, 15, read_write>;  // External trigger polarity
        using ECE = Field<SMCFGR, 1, 14, read_write>;  // External clock enable
        using ETPS = Field<SMCFGR, 2, 12, read_write>; // External trigger prescaler
        using ETF = Field<SMCFGR, 4, 8, read_write>;   // External trigger filter
        using MSM = Field<SMCFGR, 1, 7, read_write>;   // Master/Slave mode
        using TS = Field<SMCFGR, 3, 4, read_write>;    // Trigger selection
        using SMS = Field<SMCFGR, 3, 0, read_write>;   // Slave mode selection
    };
    struct DMAINTENR : PackedRegister<TIM2_pack, RegBitSize::b32, 12 * 8> // DMA/Interrupt enable register
    {
        using TDE = Field<DMAINTENR, 1, 14, read_write>;   // Trigger DMA request enable
        using CC4DE = Field<DMAINTENR, 1, 12, read_write>; // Capture/Compare 4 DMA request
        using CC3DE = Field<DMAINTENR, 1, 11, read_write>; // Capture/Compare 3 DMA request
        using CC2DE = Field<DMAINTENR, 1, 10, read_write>; // Capture/Compare 2 DMA request
        using CC1DE = Field<DMAINTENR, 1, 9, read_write>;  // Capture/Compare 1 DMA request
        using UDE = Field<DMAINTENR, 1, 8, read_write>;    // Update DMA request enable
        using TIE = Field<DMAINTENR, 1, 6, read_write>;    // Trigger interrupt enable
        using CC4IE = Field<DMAINTENR, 1, 4, read_write>;  // Capture/Compare 4 interrupt
        using CC3IE = Field<DMAINTENR, 1, 3, read_write>;  // Capture/Compare 3 interrupt
        using CC2IE = Field<DMAINTENR, 1, 2, read_write>;  // Capture/Compare 2 interrupt
        using CC1IE = Field<DMAINTENR, 1, 1, read_write>;  // Capture/Compare 1 interrupt
        using UIE = Field<DMAINTENR, 1, 0, read_write>;    // Update interrupt enable
    };
    struct INTFR : PackedRegister<TIM2_pack, RegBitSize::b32, 16 * 8> // status register
    {
        using CC4OF = Field<INTFR, 1, 12, read_write>; // Capture/Compare 4 overcapture
        using CC3OF = Field<INTFR, 1, 11, read_write>; // Capture/Compare 3 overcapture
        using CC2OF = Field<INTFR, 1, 10, read_write>; // Capture/compare 2 overcapture
        using CC1OF = Field<INTFR, 1, 9, read_write>;  // Capture/Compare 1 overcapture
        using TIF = Field<INTFR, 1, 6, read_write>;    // Trigger interrupt flag
        using CC4IF = Field<INTFR, 1, 4, read_write>;  // Capture/Compare 4 interrupt
        using CC3IF = Field<INTFR, 1, 3, read_write>;  // Capture/Compare 3 interrupt
        using CC2IF = Field<INTFR, 1, 2, read_write>;  // Capture/Compare 2 interrupt
        using CC1IF = Field<INTFR, 1, 1, read_write>;  // Capture/compare 1 interrupt
        using UIF = Field<INTFR, 1, 0, read_write>;    // Update interrupt flag
    };
    struct SWEVGR : PackedRegister<TIM2_pack, RegBitSize::b32, 20 * 8> // event generation register
    {
        using TG = Field<SWEVGR, 1, 6, write_only>;   // Trigger generation
        using CC4G = Field<SWEVGR, 1, 4, write_only>; // Capture/compare 4
        using CC3G = Field<SWEVGR, 1, 3, write_only>; // Capture/compare 3
        using CC2G = Field<SWEVGR, 1, 2, write_only>; // Capture/compare 2
        using CC1G = Field<SWEVGR, 1, 1, write_only>; // Capture/compare 1
        using UG = Field<SWEVGR, 1, 0, write_only>;   // Update generation
    };
    struct CHCTLR1_Output : PackedRegister<TIM2_pack, RegBitSize::b32, 24 * 8> // capture/compare mode register 1 (output
    {
        using OC2CE = Field<CHCTLR1_Output, 1, 15, read_write>; // Output compare 2 clear
        using OC2M = Field<CHCTLR1_Output, 3, 12, read_write>;  // Output compare 2 mode
        using OC2PE = Field<CHCTLR1_Output, 1, 11, read_write>; // Output compare 2 preload
        using OC2FE = Field<CHCTLR1_Output, 1, 10, read_write>; // Output compare 2 fast
        using CC2S = Field<CHCTLR1_Output, 2, 8, read_write>;   // Capture/Compare 2
        using OC1CE = Field<CHCTLR1_Output, 1, 7, read_write>;  // Output compare 1 clear
        using OC1M = Field<CHCTLR1_Output, 3, 4, read_write>;   // Output compare 1 mode
        using OC1PE = Field<CHCTLR1_Output, 1, 3, read_write>;  // Output compare 1 preload
        using OC1FE = Field<CHCTLR1_Output, 1, 2, read_write>;  // Output compare 1 fast
        using CC1S = Field<CHCTLR1_Output, 2, 0, read_write>;   // Capture/Compare 1
    };
    struct CHCTLR1_Input : PackedRegister<TIM2_pack, RegBitSize::b32, 24 * 8> // capture/compare mode register 1 (input
    {
        using IC2F = Field<CHCTLR1_Input, 4, 12, read_write>;   // Input capture 2 filter
        using IC2PSC = Field<CHCTLR1_Input, 2, 10, read_write>; // Input capture 2 prescaler
        using CC2S = Field<CHCTLR1_Input, 2, 8, read_write>;    // Capture/compare 2
        using IC1F = Field<CHCTLR1_Input, 4, 4, read_write>;    // Input capture 1 filter
        using IC1PSC = Field<CHCTLR1_Input, 2, 2, read_write>;  // Input capture 1 prescaler
        using CC1S = Field<CHCTLR1_Input, 2, 0, read_write>;    // Capture/Compare 1
    };
    struct CHCTLR2_Output : PackedRegister<TIM2_pack, RegBitSize::b32, 28 * 8> // capture/compare mode register 2 (output
    {
        using OC4CE = Field<CHCTLR2_Output, 1, 15, read_write>; // Output compare 4 clear
        using OC4M = Field<CHCTLR2_Output, 3, 12, read_write>;  // Output compare 4 mode
        using OC4PE = Field<CHCTLR2_Output, 1, 11, read_write>; // Output compare 4 preload
        using OC4FE = Field<CHCTLR2_Output, 1, 10, read_write>; // Output compare 4 fast
        using CC4S = Field<CHCTLR2_Output, 2, 8, read_write>;   // Capture/Compare 4
        using OC3CE = Field<CHCTLR2_Output, 1, 7, read_write>;  // Output compare 3 clear
        using OC3M = Field<CHCTLR2_Output, 3, 4, read_write>;   // Output compare 3 mode
        using OC3PE = Field<CHCTLR2_Output, 1, 3, read_write>;  // Output compare 3 preload
        using OC3FE = Field<CHCTLR2_Output, 1, 2, read_write>;  // Output compare 3 fast
        using CC3S = Field<CHCTLR2_Output, 2, 0, read_write>;   // Capture/Compare 3
    };
    struct CHCTLR2_Input : PackedRegister<TIM2_pack, RegBitSize::b32, 28 * 8> // capture/compare mode register 2 (input
    {
        using IC4F = Field<CHCTLR2_Input, 4, 12, read_write>;   // Input capture 4 filter
        using IC4PSC = Field<CHCTLR2_Input, 2, 10, read_write>; // Input capture 4 prescaler
        using CC4S = Field<CHCTLR2_Input, 2, 8, read_write>;    // Capture/Compare 4
        using IC3F = Field<CHCTLR2_Input, 4, 4, read_write>;    // Input capture 3 filter
        using IC3PSC = Field<CHCTLR2_Input, 2, 2, read_write>;  // Input capture 3 prescaler
        using CC3S = Field<CHCTLR2_Input, 2, 0, read_write>;    // Capture/Compare 3
    };
    struct CCER : PackedRegister<TIM2_pack, RegBitSize::b32, 32 * 8> // capture/compare enable
    {
        using CC4P = Field<CCER, 1, 13, read_write>; // Capture/Compare 3 output
        using CC4E = Field<CCER, 1, 12, read_write>; // Capture/Compare 4 output
        using CC3P = Field<CCER, 1, 9, read_write>;  // Capture/Compare 3 output
        using CC3E = Field<CCER, 1, 8, read_write>;  // Capture/Compare 3 output
        using CC2P = Field<CCER, 1, 5, read_write>;  // Capture/Compare 2 output
        using CC2E = Field<CCER, 1, 4, read_write>;  // Capture/Compare 2 output
        using CC1P = Field<CCER, 1, 1, read_write>;  // Capture/Compare 1 output
        using CC1E = Field<CCER, 1, 0, read_write>;  // Capture/Compare 1 output
    };
    struct CNT : PackedRegister<TIM2_pack, RegBitSize::b32, 36 * 8> // counter
    {
        using CNTfield = Field<CNT, 16, 0, read_write>; // counter value
    };
    struct PSC : PackedRegister<TIM2_pack, RegBitSize::b32, 40 * 8> // prescaler
    {
        using PSCfield = Field<PSC, 16, 0, read_write>; // Prescaler value
    };
    struct ATRLR : PackedRegister<TIM2_pack, RegBitSize::b32, 44 * 8> // auto-reload register
    {
        using ATRLRfield = Field<ATRLR, 16, 0, read_write>; // Auto-reload value
    };
    struct CH1CVR : PackedRegister<TIM2_pack, RegBitSize::b32, 52 * 8> // capture/compare register 1
    {
        using CH1CVRfield = Field<CH1CVR, 16, 0, read_write>; // Capture/Compare 1 value
    };
    struct CH2CVR : PackedRegister<TIM2_pack, RegBitSize::b32, 56 * 8> // capture/compare register 2
    {
        using CH2CVRfield = Field<CH2CVR, 16, 0, read_write>; // Capture/Compare 2 value
    };
    struct CH3CVR : PackedRegister<TIM2_pack, RegBitSize::b32, 60 * 8> // capture/compare register 3
    {
        using CH3CVRfield = Field<CH3CVR, 16, 0, read_write>; // Capture/Compare value
    };
    struct CH4CVR : PackedRegister<TIM2_pack, RegBitSize::b32, 64 * 8> // capture/compare register 4
    {
        using CH4CVRfield = Field<CH4CVR, 16, 0, read_write>; // Capture/Compare value
    };
    struct DMACFGR : PackedRegister<TIM2_pack, RegBitSize::b32, 72 * 8> // DMA control register
    {
        using DBL = Field<DMACFGR, 5, 8, read_write>; // DMA burst length
        using DBA = Field<DMACFGR, 5, 0, read_write>; // DMA base address
    };
    struct DMAADR : PackedRegister<TIM2_pack, RegBitSize::b32, 76 * 8> // DMA address for full transfer
    {
        using DMAADRfield = Field<DMAADR, 16, 0, read_write>; // DMA register for burst
    };
} // namespace TIM2
namespace I2C1
{
    using I2C1_pack = RegisterPack<0x40005400, 1024>;
    struct CTLR1 : PackedRegister<I2C1_pack, RegBitSize::b32, 0 * 8> // Control register 1
    {
        using SWRST = Field<CTLR1, 1, 15, read_write>;    // Software reset
        using PEC = Field<CTLR1, 1, 12, read_write>;      // Packet error checking
        using POS = Field<CTLR1, 1, 11, read_write>;      // Acknowledge/PEC Position (for data
        using ACK = Field<CTLR1, 1, 10, read_write>;      // Acknowledge enable
        using STOP = Field<CTLR1, 1, 9, read_write>;      // Stop generation
        using START = Field<CTLR1, 1, 8, read_write>;     // Start generation
        using NOSTRETCH = Field<CTLR1, 1, 7, read_write>; // Clock stretching disable (Slave
        using ENGC = Field<CTLR1, 1, 6, read_write>;      // General call enable
        using ENPEC = Field<CTLR1, 1, 5, read_write>;     // PEC enable
        using ENARP = Field<CTLR1, 1, 4, read_write>;     // ARP enable
        using PE = Field<CTLR1, 1, 0, read_write>;        // Peripheral enable
    };
    struct CTLR2 : PackedRegister<I2C1_pack, RegBitSize::b32, 4 * 8> // Control register 2
    {
        using LAST = Field<CTLR2, 1, 12, read_write>;    // DMA last transfer
        using DMAEN = Field<CTLR2, 1, 11, read_write>;   // DMA requests enable
        using ITBUFEN = Field<CTLR2, 1, 10, read_write>; // Buffer interrupt enable
        using ITEVTEN = Field<CTLR2, 1, 9, read_write>;  // Event interrupt enable
        using ITERREN = Field<CTLR2, 1, 8, read_write>;  // Error interrupt enable
        using FREQ = Field<CTLR2, 6, 0, read_write>;     // Peripheral clock frequency
    };
    struct OADDR1 : PackedRegister<I2C1_pack, RegBitSize::b32, 8 * 8> // Own address register 1
    {
        using ADDMODE = Field<OADDR1, 1, 15, read_write>; // Addressing mode (slave
        using ADD9_8 = Field<OADDR1, 2, 8, read_write>;   // Interface address
        using ADD7_1 = Field<OADDR1, 7, 1, read_write>;   // Interface address
        using ADD0 = Field<OADDR1, 1, 0, read_write>;     // Interface address
    };
    struct OADDR2 : PackedRegister<I2C1_pack, RegBitSize::b32, 12 * 8> // Own address register 2
    {
        using ADD2 = Field<OADDR2, 7, 1, read_write>;   // Interface address
        using ENDUAL = Field<OADDR2, 1, 0, read_write>; // Dual addressing mode
    };
    struct DATAR : PackedRegister<I2C1_pack, RegBitSize::b32, 16 * 8> // Data register
    {
        using DATARfield = Field<DATAR, 8, 0, read_write>; // 8-bit data register
    };
    struct STAR1 : PackedRegister<I2C1_pack, RegBitSize::b32, 20 * 8> // Status register 1
    {
        using PECERR = Field<STAR1, 1, 12, read_write>; // PEC Error in reception
        using OVR = Field<STAR1, 1, 11, read_write>;    // Overrun/Underrun
        using AF = Field<STAR1, 1, 10, read_write>;     // Acknowledge failure
        using ARLO = Field<STAR1, 1, 9, read_write>;    // Arbitration lost (master
        using BERR = Field<STAR1, 1, 8, read_write>;    // Bus error
        using TxE = Field<STAR1, 1, 7, read_only>;      // Data register empty
        using RxNE = Field<STAR1, 1, 6, read_only>;     // Data register not empty
        using STOPF = Field<STAR1, 1, 4, read_only>;    // Stop detection (slave
        using ADD10 = Field<STAR1, 1, 3, read_only>;    // 10-bit header sent (Master
        using BTF = Field<STAR1, 1, 2, read_only>;      // Byte transfer finished
        using ADDR = Field<STAR1, 1, 1, read_only>;     // Address sent (master mode)/matched
        using SB = Field<STAR1, 1, 0, read_only>;       // Start bit (Master mode)
    };
    struct STAR2 : PackedRegister<I2C1_pack, RegBitSize::b32, 24 * 8> // Status register 2
    {
        using PEC = Field<STAR2, 8, 8, read_only>;     // acket error checking
        using DUALF = Field<STAR2, 1, 7, read_only>;   // Dual flag (Slave mode)
        using GENCALL = Field<STAR2, 1, 4, read_only>; // General call address (Slave
        using TRA = Field<STAR2, 1, 2, read_only>;     // Transmitter/receiver
        using BUSY = Field<STAR2, 1, 1, read_only>;    // Bus busy
        using MSL = Field<STAR2, 1, 0, read_only>;     // Master/slave
    };
    struct CKCFGR : PackedRegister<I2C1_pack, RegBitSize::b32, 28 * 8> // Clock control register
    {
        using F_S = Field<CKCFGR, 1, 15, read_write>;  // I2C master mode selection
        using DUTY = Field<CKCFGR, 1, 14, read_write>; // Fast mode duty cycle
        using CCR = Field<CKCFGR, 12, 0, read_write>;  // Clock control register in Fast/Standard
    };
} // namespace I2C1
namespace SPI1
{
    using SPI1_pack = RegisterPack<0x40013000, 1024>;
    struct CTLR1 : PackedRegister<SPI1_pack, RegBitSize::b32, 0 * 8> // control register 1
    {
        using BIDIMODE = Field<CTLR1, 1, 15, read_write>; // Bidirectional data mode
        using BIDIOE = Field<CTLR1, 1, 14, read_write>;   // Output enable in bidirectional
        using CRCEN = Field<CTLR1, 1, 13, read_write>;    // Hardware CRC calculation
        using CRCNEXT = Field<CTLR1, 1, 12, read_write>;  // CRC transfer next
        using DFF = Field<CTLR1, 1, 11, read_write>;      // Data frame format
        using RXONLY = Field<CTLR1, 1, 10, read_write>;   // Receive only
        using SSM = Field<CTLR1, 1, 9, read_write>;       // Software slave management
        using SSI = Field<CTLR1, 1, 8, read_write>;       // Internal slave select
        using LSBFIRST = Field<CTLR1, 1, 7, read_write>;  // Frame format
        using SPE = Field<CTLR1, 1, 6, read_write>;       // SPI enable
        using BR = Field<CTLR1, 3, 3, read_write>;        // Baud rate control
        using MSTR = Field<CTLR1, 1, 2, read_write>;      // Master selection
        using CPOL = Field<CTLR1, 1, 1, read_write>;      // Clock polarity
        using CPHA = Field<CTLR1, 1, 0, read_write>;      // Clock phase
    };
    struct CTLR2 : PackedRegister<SPI1_pack, RegBitSize::b32, 4 * 8> // control register 2
    {
        using TXEIE = Field<CTLR2, 1, 7, read_write>;   // Tx buffer empty interrupt
        using RXNEIE = Field<CTLR2, 1, 6, read_write>;  // RX buffer not empty interrupt
        using ERRIE = Field<CTLR2, 1, 5, read_write>;   // Error interrupt enable
        using SSOE = Field<CTLR2, 1, 2, read_write>;    // SS output enable
        using TXDMAEN = Field<CTLR2, 1, 1, read_write>; // Tx buffer DMA enable
        using RXDMAEN = Field<CTLR2, 1, 0, read_write>; // Rx buffer DMA enable
    };
    struct STATR : PackedRegister<SPI1_pack, RegBitSize::b32, 8 * 8> // status register
    {
        using BSY = Field<STATR, 1, 7, read_only>;     // Busy flag
        using OVR = Field<STATR, 1, 6, read_write>;    // Overrun flag
        using MODF = Field<STATR, 1, 5, read_only>;    // Mode fault
        using CRCERR = Field<STATR, 1, 4, read_write>; // CRC error flag
        using CHSID = Field<STATR, 1, 2, read_only>;   // Channel side
        using UDR = Field<STATR, 1, 3, read_only>;     // Underrun flag
        using TXE = Field<STATR, 1, 1, read_only>;     // Transmit buffer empty
        using RXNE = Field<STATR, 1, 0, read_only>;    // Receive buffer not empty
    };
    struct DATAR : PackedRegister<SPI1_pack, RegBitSize::b32, 12 * 8> // data register
    {
        using DATARfield = Field<DATAR, 16, 0, read_write>; // Data register
    };
    struct CRCR : PackedRegister<SPI1_pack, RegBitSize::b32, 16 * 8> // CRCR polynomial register
    {
        using CRCPOLY = Field<CRCR, 16, 0, read_write>; // CRC polynomial register
    };
    struct RCRCR : PackedRegister<SPI1_pack, RegBitSize::b32, 20 * 8> // RX CRC register
    {
        using RXCRC = Field<RCRCR, 16, 0, read_only>; // Rx CRC register
    };
    struct TCRCR : PackedRegister<SPI1_pack, RegBitSize::b32, 24 * 8> // send CRC register
    {
        using TXCRC = Field<TCRCR, 16, 0, read_only>; // Tx CRC register
    };
    struct HSCR : PackedRegister<SPI1_pack, RegBitSize::b32, 36 * 8> // high speed control register
    {
        using HSRXEN = Field<HSCR, 1, 0, write_only>; // High speed mode read enable
    };
} // namespace SPI1
namespace USART1
{
    using USART1_pack = RegisterPack<0x40013800, 1024>;
    struct STATR : PackedRegister<USART1_pack, RegBitSize::b32, 0 * 8> // Status register
    {
        using CTS = Field<STATR, 1, 9, read_write>;  // CTS flag
        using LBD = Field<STATR, 1, 8, read_write>;  // LIN break detection flag
        using TXE = Field<STATR, 1, 7, read_only>;   // Transmit data register
        using TC = Field<STATR, 1, 6, read_write>;   // Transmission complete
        using RXNE = Field<STATR, 1, 5, read_write>; // Read data register not
        using IDLE = Field<STATR, 1, 4, read_only>;  // IDLE line detected
        using ORE = Field<STATR, 1, 3, read_only>;   // Overrun error
        using NE = Field<STATR, 1, 2, read_only>;    // Noise error flag
        using FE = Field<STATR, 1, 1, read_only>;    // Framing error
        using PE = Field<STATR, 1, 0, read_only>;    // Parity error
    };
    struct DATAR : PackedRegister<USART1_pack, RegBitSize::b32, 4 * 8> // Data register
    {
        using DR = Field<DATAR, 9, 0, read_write>; // Data value
    };
    struct BRR : PackedRegister<USART1_pack, RegBitSize::b32, 8 * 8> // Baud rate register
    {
        using DIV_Mantissa = Field<BRR, 12, 4, read_write>; // mantissa of USARTDIV
        using DIV_Fraction = Field<BRR, 4, 0, read_write>;  // fraction of USARTDIV
    };
    struct CTLR1 : PackedRegister<USART1_pack, RegBitSize::b32, 12 * 8> // Control register 1
    {
        using UE = Field<CTLR1, 1, 13, read_write>;    // USART enable
        using M = Field<CTLR1, 1, 12, read_write>;     // Word length
        using WAKE = Field<CTLR1, 1, 11, read_write>;  // Wakeup method
        using PCE = Field<CTLR1, 1, 10, read_write>;   // Parity control enable
        using PS = Field<CTLR1, 1, 9, read_write>;     // Parity selection
        using PEIE = Field<CTLR1, 1, 8, read_write>;   // PE interrupt enable
        using TXEIE = Field<CTLR1, 1, 7, read_write>;  // TXE interrupt enable
        using TCIE = Field<CTLR1, 1, 6, read_write>;   // Transmission complete interrupt
        using RXNEIE = Field<CTLR1, 1, 5, read_write>; // RXNE interrupt enable
        using IDLEIE = Field<CTLR1, 1, 4, read_write>; // IDLE interrupt enable
        using TE = Field<CTLR1, 1, 3, read_write>;     // Transmitter enable
        using RE = Field<CTLR1, 1, 2, read_write>;     // Receiver enable
        using RWU = Field<CTLR1, 1, 1, read_write>;    // Receiver wakeup
        using SBK = Field<CTLR1, 1, 0, read_write>;    // Send break
    };
    struct CTLR2 : PackedRegister<USART1_pack, RegBitSize::b32, 16 * 8> // Control register 2
    {
        using LINEN = Field<CTLR2, 1, 14, read_write>; // LIN mode enable
        using STOP = Field<CTLR2, 2, 12, read_write>;  // STOP bits
        using CLKEN = Field<CTLR2, 1, 11, read_write>; // Clock enable
        using CPOL = Field<CTLR2, 1, 10, read_write>;  // Clock polarity
        using CPHA = Field<CTLR2, 1, 9, read_write>;   // Clock phase
        using LBCL = Field<CTLR2, 1, 8, read_write>;   // Last bit clock pulse
        using LBDIE = Field<CTLR2, 1, 6, read_write>;  // LIN break detection interrupt
        using LBDL = Field<CTLR2, 1, 5, read_write>;   // lin break detection length
        using ADD = Field<CTLR2, 4, 0, read_write>;    // Address of the USART node
    };
    struct CTLR3 : PackedRegister<USART1_pack, RegBitSize::b32, 20 * 8> // Control register 3
    {
        using CTSIE = Field<CTLR3, 1, 10, read_write>; // CTS interrupt enable
        using CTSE = Field<CTLR3, 1, 9, read_write>;   // CTS enable
        using RTSE = Field<CTLR3, 1, 8, read_write>;   // RTS enable
        using DMAT = Field<CTLR3, 1, 7, read_write>;   // DMA enable transmitter
        using DMAR = Field<CTLR3, 1, 6, read_write>;   // DMA enable receiver
        using SCEN = Field<CTLR3, 1, 5, read_write>;   // Smartcard mode enable
        using NACK = Field<CTLR3, 1, 4, read_write>;   // Smartcard NACK enable
        using HDSEL = Field<CTLR3, 1, 3, read_write>;  // Half-duplex selection
        using IRLP = Field<CTLR3, 1, 2, read_write>;   // IrDA low-power
        using IREN = Field<CTLR3, 1, 1, read_write>;   // IrDA mode enable
        using EIE = Field<CTLR3, 1, 0, read_write>;    // Error interrupt enable
    };
    struct GPR : PackedRegister<USART1_pack, RegBitSize::b32, 24 * 8> // Guard time and prescaler
    {
        using GT = Field<GPR, 8, 8, read_write>;  // Guard time value
        using PSC = Field<GPR, 8, 0, read_write>; // Prescaler value
    };
} // namespace USART1
namespace ADC1
{
    using ADC1_pack = RegisterPack<0x40012400, 1024>;
    struct STATR : PackedRegister<ADC1_pack, RegBitSize::b32, 0 * 8> // status register
    {
        using STRT = Field<STATR, 1, 4, read_write>;  // Regular channel start flag
        using JSTRT = Field<STATR, 1, 3, read_write>; // Injected channel start
        using JEOC = Field<STATR, 1, 2, read_write>;  // Injected channel end of
        using EOC = Field<STATR, 1, 1, read_write>;   // Regular channel end of
        using AWD = Field<STATR, 1, 0, read_write>;   // Analog watchdog flag
    };
    struct CTLR1 : PackedRegister<ADC1_pack, RegBitSize::b32, 4 * 8> // control register 1/TKEY_V_CTLR
    {
        using ADC_CAL_VOL = Field<CTLR1, 2, 25, read_write>; // ADC Calibration voltage selection
        using AWDEN = Field<CTLR1, 1, 23, read_write>;       // Analog watchdog enable on regular
        using JAWDEN = Field<CTLR1, 1, 22, read_write>;      // Analog watchdog enable on injected
        using DISCNUM = Field<CTLR1, 3, 13, read_write>;     // Discontinuous mode channel
        using JDISCEN = Field<CTLR1, 1, 12, read_write>;     // Discontinuous mode on injected
        using DISCEN = Field<CTLR1, 1, 11, read_write>;      // Discontinuous mode on regular
        using JAUTO = Field<CTLR1, 1, 10, read_write>;       // Automatic injected group
        using AWDSGL = Field<CTLR1, 1, 9, read_write>;       // Enable the watchdog on a single channel
        using SCAN = Field<CTLR1, 1, 8, read_write>;         // Scan mode enable
        using JEOCIE = Field<CTLR1, 1, 7, read_write>;       // Interrupt enable for injected
        using AWDIE = Field<CTLR1, 1, 6, read_write>;        // Analog watchdog interrupt
        using EOCIE = Field<CTLR1, 1, 5, read_write>;        // Interrupt enable for EOC
        using AWDCH = Field<CTLR1, 5, 0, read_write>;        // Analog watchdog channel select
    };
    struct CTLR2 : PackedRegister<ADC1_pack, RegBitSize::b32, 8 * 8> // control register 2
    {
        using SWSTART = Field<CTLR2, 1, 22, read_write>;  // Start conversion of regular
        using JSWSTART = Field<CTLR2, 1, 21, read_write>; // Start conversion of injected
        using EXTTRIG = Field<CTLR2, 1, 20, read_write>;  // External trigger conversion mode for
        using EXTSEL = Field<CTLR2, 3, 17, read_write>;   // External event select for regular
        using JEXTTRIG = Field<CTLR2, 1, 15, read_write>; // External trigger conversion mode for
        using JEXTSEL = Field<CTLR2, 3, 12, read_write>;  // External event select for injected
        using ALIGN = Field<CTLR2, 1, 11, read_write>;    // Data alignment
        using DMA = Field<CTLR2, 1, 8, read_write>;       // Direct memory access mode
        using RSTCAL = Field<CTLR2, 1, 3, read_write>;    // Reset calibration
        using CAL = Field<CTLR2, 1, 2, read_write>;       // A/D calibration
        using CONT = Field<CTLR2, 1, 1, read_write>;      // Continuous conversion
        using ADON = Field<CTLR2, 1, 0, read_write>;      // A/D converter ON / OFF
    };
    struct SAMPTR1_CHARGE1 : PackedRegister<ADC1_pack, RegBitSize::b32, 12 * 8> // sample time register 1
    {
        using SMP10_TKCG10 = Field<SAMPTR1_CHARGE1, 3, 0, read_write>;  // Channel 10 sample time
        using SMP11_TKCG11 = Field<SAMPTR1_CHARGE1, 3, 3, read_write>;  // Channel 11 sample time
        using SMP12_TKCG12 = Field<SAMPTR1_CHARGE1, 3, 6, read_write>;  // Channel 12 sample time
        using SMP13_TKCG13 = Field<SAMPTR1_CHARGE1, 3, 9, read_write>;  // Channel 13 sample time
        using SMP14_TKCG14 = Field<SAMPTR1_CHARGE1, 3, 12, read_write>; // Channel 14 sample time
        using SMP15_TKCG15 = Field<SAMPTR1_CHARGE1, 3, 15, read_write>; // Channel 15 sample time
    };
    struct SAMPTR2_CHARGE2 : PackedRegister<ADC1_pack, RegBitSize::b32, 16 * 8> // sample time register 2
    {
        using SMP0_TKCG0 = Field<SAMPTR2_CHARGE2, 3, 0, read_write>;  // Channel 0 sample time
        using SMP1_TKCG1 = Field<SAMPTR2_CHARGE2, 3, 3, read_write>;  // Channel 1 sample time
        using SMP2_TKCG2 = Field<SAMPTR2_CHARGE2, 3, 6, read_write>;  // Channel 2 sample time
        using SMP3_TKCG3 = Field<SAMPTR2_CHARGE2, 3, 9, read_write>;  // Channel 3 sample time
        using SMP4_TKCG4 = Field<SAMPTR2_CHARGE2, 3, 12, read_write>; // Channel 4 sample time
        using SMP5_TKCG5 = Field<SAMPTR2_CHARGE2, 3, 15, read_write>; // Channel 5 sample time
        using SMP6_TKCG6 = Field<SAMPTR2_CHARGE2, 3, 18, read_write>; // Channel 6 sample time
        using SMP7_TKCG7 = Field<SAMPTR2_CHARGE2, 3, 21, read_write>; // Channel 7 sample time
        using SMP8_TKCG8 = Field<SAMPTR2_CHARGE2, 3, 24, read_write>; // Channel 8 sample time
        using SMP9_TKCG9 = Field<SAMPTR2_CHARGE2, 3, 27, read_write>; // Channel 9 sample time
    };
    struct IOFR1 : PackedRegister<ADC1_pack, RegBitSize::b32, 20 * 8> // injected channel data offset register
    {
        using JOFFSET1 = Field<IOFR1, 10, 0, read_write>; // Data offset for injected channel
    };
    struct IOFR2 : PackedRegister<ADC1_pack, RegBitSize::b32, 24 * 8> // injected channel data offset register
    {
        using JOFFSET2 = Field<IOFR2, 10, 0, read_write>; // Data offset for injected channel
    };
    struct IOFR3 : PackedRegister<ADC1_pack, RegBitSize::b32, 28 * 8> // injected channel data offset register
    {
        using JOFFSET3 = Field<IOFR3, 10, 0, read_write>; // Data offset for injected channel
    };
    struct IOFR4 : PackedRegister<ADC1_pack, RegBitSize::b32, 32 * 8> // injected channel data offset register
    {
        using JOFFSET4 = Field<IOFR4, 10, 0, read_write>; // Data offset for injected channel
    };
    struct WDHTR : PackedRegister<ADC1_pack, RegBitSize::b32, 36 * 8> // watchdog higher threshold
    {
        using HT = Field<WDHTR, 10, 0, read_write>; // Analog watchdog higher
    };
    struct WDLTR : PackedRegister<ADC1_pack, RegBitSize::b32, 40 * 8> // watchdog lower threshold
    {
        using LT = Field<WDLTR, 10, 0, read_write>; // Analog watchdog lower
    };
    struct RSQR1 : PackedRegister<ADC1_pack, RegBitSize::b32, 44 * 8> // regular sequence register 1
    {
        using L = Field<RSQR1, 4, 20, read_write>;    // Regular channel sequence
        using SQ16 = Field<RSQR1, 5, 15, read_write>; // 16th conversion in regular
        using SQ15 = Field<RSQR1, 5, 10, read_write>; // 15th conversion in regular
        using SQ14 = Field<RSQR1, 5, 5, read_write>;  // 14th conversion in regular
        using SQ13 = Field<RSQR1, 5, 0, read_write>;  // 13th conversion in regular
    };
    struct RSQR2 : PackedRegister<ADC1_pack, RegBitSize::b32, 48 * 8> // regular sequence register 2
    {
        using SQ12 = Field<RSQR2, 5, 25, read_write>; // 12th conversion in regular
        using SQ11 = Field<RSQR2, 5, 20, read_write>; // 11th conversion in regular
        using SQ10 = Field<RSQR2, 5, 15, read_write>; // 10th conversion in regular
        using SQ9 = Field<RSQR2, 5, 10, read_write>;  // 9th conversion in regular
        using SQ8 = Field<RSQR2, 5, 5, read_write>;   // 8th conversion in regular
        using SQ7 = Field<RSQR2, 5, 0, read_write>;   // 7th conversion in regular
    };
    struct RSQR3 : PackedRegister<ADC1_pack, RegBitSize::b32, 52 * 8> // regular sequence register 3
    {
        using SQ6 = Field<RSQR3, 5, 25, read_write>; // 6th conversion in regular
        using SQ5 = Field<RSQR3, 5, 20, read_write>; // 5th conversion in regular
        using SQ4 = Field<RSQR3, 5, 15, read_write>; // 4th conversion in regular
        using SQ3 = Field<RSQR3, 5, 10, read_write>; // 3rd conversion in regular
        using SQ2 = Field<RSQR3, 5, 5, read_write>;  // 2nd conversion in regular
        using SQ1 = Field<RSQR3, 5, 0, read_write>;  // 1st conversion in regular
    };
    struct ISQR : PackedRegister<ADC1_pack, RegBitSize::b32, 56 * 8> // injected sequence register
    {
        using JL = Field<ISQR, 2, 20, read_write>;   // Injected sequence length
        using JSQ4 = Field<ISQR, 5, 15, read_write>; // 4th conversion in injected
        using JSQ3 = Field<ISQR, 5, 10, read_write>; // 3rd conversion in injected
        using JSQ2 = Field<ISQR, 5, 5, read_write>;  // 2nd conversion in injected
        using JSQ1 = Field<ISQR, 5, 0, read_write>;  // 1st conversion in injected
    };
    struct IDATAR1 : PackedRegister<ADC1_pack, RegBitSize::b32, 60 * 8> // injected data register 1
    {
        using IDATA = Field<IDATAR1, 16, 0, read_only>; // Injected data
    };
    struct IDATAR2 : PackedRegister<ADC1_pack, RegBitSize::b32, 64 * 8> // injected data register 2
    {
        using IDATA = Field<IDATAR2, 16, 0, read_only>; // Injected data
    };
    struct IDATAR3 : PackedRegister<ADC1_pack, RegBitSize::b32, 68 * 8> // injected data register 3
    {
        using IDATA = Field<IDATAR3, 16, 0, read_only>; // Injected data
    };
    struct IDATAR4 : PackedRegister<ADC1_pack, RegBitSize::b32, 72 * 8> // injected data register 4
    {
        using IDATA = Field<IDATAR4, 16, 0, read_only>; // Injected data
    };
    struct RDATAR : PackedRegister<ADC1_pack, RegBitSize::b32, 76 * 8> // regular data register
    {
        using DATA = Field<RDATAR, 32, 0, read_only>; // Regular data
    };
    struct DLYR : PackedRegister<ADC1_pack, RegBitSize::b32, 80 * 8> // delay data register
    {
        using DLYVLU = Field<DLYR, 9, 0, read_write>; // External trigger data delay time configuration
        using DLYSRC = Field<DLYR, 1, 9, read_write>; // External trigger source delay selection
    };
} // namespace ADC1
namespace DBG
{
    using DBG_pack = RegisterPack<0xe000d000, 1024>;
    struct CFGR1 : PackedRegister<DBG_pack, RegBitSize::b32, 0 * 8> // DBGMCU_CFGR1
    {
        using DEG_IWDG = Field<CFGR1, 1, 0, read_write>; // DEG_IWDG
        using DEG_WWDG = Field<CFGR1, 1, 1, read_write>; // DEG_WWDG
        using DEG_I2C1 = Field<CFGR1, 1, 2, read_write>; // DEG_I2C1
        using DEG_TIM1 = Field<CFGR1, 1, 4, read_write>; // DEG_TIM1
        using DEG_TIM2 = Field<CFGR1, 1, 5, read_write>; // DEG_TIM2
    };
    struct CFGR2 : PackedRegister<DBG_pack, RegBitSize::b32, 4 * 8> // DBGMCU_CFGR2
    {
        using DBG_SLEEP = Field<CFGR2, 1, 0, read_write>;   // DBG_SLEEP
        using DBG_STOP = Field<CFGR2, 1, 1, read_write>;    // DBG_STOP
        using DBG_STANDBY = Field<CFGR2, 1, 2, read_write>; // DBG_STANDBY
    };
} // namespace DBG
namespace ESIG
{
    using ESIG_pack = RegisterPack<0x1ffff7e0, 20>;
    struct FLACAP : PackedRegister<ESIG_pack, RegBitSize::b16, 0 * 8> // Flash capacity register
    {
        using FLASHSIZE = Field<FLACAP, 16, 0, read_only>; // Flash size
    };
    struct UNIID1 : PackedRegister<ESIG_pack, RegBitSize::b32, 8 * 8> // Unique identity 1
    {
        using U_ID = Field<UNIID1, 32, 0, read_only>; // Unique identity[31:0]
    };
    struct UNIID2 : PackedRegister<ESIG_pack, RegBitSize::b32, 12 * 8> // Unique identity 2
    {
        using U_ID = Field<UNIID2, 32, 0, read_only>; // Unique identity[63:32]
    };
    struct UNIID3 : PackedRegister<ESIG_pack, RegBitSize::b32, 16 * 8> // Unique identity 3
    {
        using U_ID = Field<UNIID3, 32, 0, read_only>; // Unique identity[95:64]
    };
} // namespace ESIG
namespace FLASH
{
    using FLASH_pack = RegisterPack<0x40022000, 1024>;
    struct ACTLR : PackedRegister<FLASH_pack, RegBitSize::b32, 0 * 8> // Flash key register
    {
        using LATENCY = Field<ACTLR, 1, 0, read_write>; // Number of FLASH wait states
    };
    struct KEYR : PackedRegister<FLASH_pack, RegBitSize::b32, 4 * 8> // Flash key register
    {
        using KEYRfield = Field<KEYR, 32, 0, write_only>; // FPEC key
    };
    struct OBKEYR : PackedRegister<FLASH_pack, RegBitSize::b32, 8 * 8> // Flash option key register
    {
        using OPTKEY = Field<OBKEYR, 32, 0, write_only>; // Option byte key
    };
    struct STATR : PackedRegister<FLASH_pack, RegBitSize::b32, 12 * 8> // Status register
    {
        using BOOT_LOCK = Field<STATR, 1, 15, read_write>; // BOOT lock
        using BOOT_MODE = Field<STATR, 1, 14, read_write>; // BOOT mode
        using EOP = Field<STATR, 1, 5, read_write>;        // End of operation
        using WRPRTERR = Field<STATR, 1, 4, read_write>;   // Write protection error
        using BSY = Field<STATR, 1, 0, read_only>;         // Busy
    };
    struct CTLR : PackedRegister<FLASH_pack, RegBitSize::b32, 16 * 8> // Control register
    {
        using PG = Field<CTLR, 1, 0, read_write>;       // Programming
        using PER = Field<CTLR, 1, 1, read_write>;      // Page Erase
        using MER = Field<CTLR, 1, 2, read_write>;      // Mass Erase
        using OBPG = Field<CTLR, 1, 4, read_write>;     // Option byte programming
        using OBER = Field<CTLR, 1, 5, read_write>;     // Option byte erase
        using STRT = Field<CTLR, 1, 6, read_write>;     // Start
        using LOCK = Field<CTLR, 1, 7, read_write>;     // Lock
        using OBWRE = Field<CTLR, 1, 9, read_write>;    // Option bytes write enable
        using ERRIE = Field<CTLR, 1, 10, read_write>;   // Error interrupt enable
        using EOPIE = Field<CTLR, 1, 12, read_write>;   // End of operation interrupt
        using FLOCK = Field<CTLR, 1, 15, read_write>;   // Fast programmable lock
        using PAGE_PG = Field<CTLR, 1, 16, read_write>; // Fast programming
        using PAGE_ER = Field<CTLR, 1, 17, read_write>; // Fast erase
        using BUFLOAD = Field<CTLR, 1, 18, read_write>; // Buffer load
        using BUFRST = Field<CTLR, 1, 19, read_write>;  // Buffer reset
    };
    struct ADDR : PackedRegister<FLASH_pack, RegBitSize::b32, 20 * 8> // Flash address register
    {
        using ADDRfield = Field<ADDR, 32, 0, write_only>; // Flash Address
    };
    struct OBR : PackedRegister<FLASH_pack, RegBitSize::b32, 28 * 8> // Option byte register
    {
        using OBERR = Field<OBR, 1, 0, read_only>;        // Option byte error
        using RDPRT = Field<OBR, 1, 1, read_only>;        // Read protection
        using IWDG_SW = Field<OBR, 1, 2, read_only>;      // IWDG_SW
        using STOP_RST = Field<OBR, 1, 3, read_only>;     // STOP_RST
        using STANDY_RST = Field<OBR, 1, 4, read_only>;   // STANDY_RST
        using CFG_RST_MODE = Field<OBR, 2, 5, read_only>; // CFG_RST_MODE
        using DATA0 = Field<OBR, 8, 10, read_only>;       // DATA0
        using DATA1 = Field<OBR, 8, 18, read_only>;       // DATA1
    };
    struct WPR : PackedRegister<FLASH_pack, RegBitSize::b32, 32 * 8> // Write protection register
    {
        using WRP = Field<WPR, 32, 0, read_only>; // Write protect
    };
    struct MODEKEYR : PackedRegister<FLASH_pack, RegBitSize::b32, 36 * 8> // Mode select register
    {
        using MODEKEYRfield = Field<MODEKEYR, 32, 0, write_only>; // Mode select
    };
    struct BOOT_MODEKEYP : PackedRegister<FLASH_pack, RegBitSize::b32, 40 * 8> // Boot mode key register
    {
        using MODEKEYR = Field<BOOT_MODEKEYP, 32, 0, write_only>; // Boot mode key
    };
} // namespace FLASH
namespace PFIC
{
    using PFIC_pack = RegisterPack<0xe000e000, 4352>;
    struct ISR1 : PackedRegister<PFIC_pack, RegBitSize::b32, 0 * 8> // Interrupt Status
    {
        using INTENSTA2_3 = Field<ISR1, 2, 2, read_only>;     // Interrupt ID Status
        using INTENSTA12_31 = Field<ISR1, 20, 12, read_only>; // Interrupt ID Status
    };
    struct ISR2 : PackedRegister<PFIC_pack, RegBitSize::b32, 4 * 8> // Interrupt Status
    {
        using INTENSTA = Field<ISR2, 32, 0, read_only>; // Interrupt ID Status
    };
    struct ISR3 : PackedRegister<PFIC_pack, RegBitSize::b32, 8 * 8> // Interrupt Status
    {
        using INTENSTA = Field<ISR3, 32, 0, read_only>; // Interrupt ID Status
    };
    struct ISR4 : PackedRegister<PFIC_pack, RegBitSize::b32, 12 * 8> // Interrupt Status
    {
        using INTENSTA = Field<ISR4, 8, 0, read_only>; // Interrupt ID Status
    };
    struct IPR1 : PackedRegister<PFIC_pack, RegBitSize::b32, 32 * 8> // Interrupt Pending Register
    {
        using PENDSTA2_3 = Field<IPR1, 2, 2, read_only>;     // PENDSTA
        using PENDSTA12_31 = Field<IPR1, 20, 12, read_only>; // PENDSTA
    };
    struct IPR2 : PackedRegister<PFIC_pack, RegBitSize::b32, 36 * 8> // Interrupt Pending Register
    {
        using PENDSTA = Field<IPR2, 32, 0, read_only>; // PENDSTA
    };
    struct IPR3 : PackedRegister<PFIC_pack, RegBitSize::b32, 40 * 8> // Interrupt Pending Register
    {
        using PENDSTA = Field<IPR3, 32, 0, read_only>; // PENDSTA
    };
    struct IPR4 : PackedRegister<PFIC_pack, RegBitSize::b32, 44 * 8> // Interrupt Pending Register
    {
        using PENDSTA = Field<IPR4, 8, 0, read_only>; // PENDSTA
    };
    struct ITHRESDR : PackedRegister<PFIC_pack, RegBitSize::b32, 64 * 8> // Interrupt Priority
    {
        using THRESHOLD = Field<ITHRESDR, 8, 0, read_write>; // THRESHOLD
    };
    struct CFGR : PackedRegister<PFIC_pack, RegBitSize::b32, 72 * 8> // Interrupt Config Register
    {
        using RESETSYS = Field<CFGR, 1, 7, write_only>;  // RESETSYS
        using KEYCODE = Field<CFGR, 16, 16, write_only>; // KEYCODE
    };
    struct GISR : PackedRegister<PFIC_pack, RegBitSize::b32, 76 * 8> // Interrupt Global Register
    {
        using NESTSTA = Field<GISR, 8, 0, read_only>;  // NESTSTA
        using GACTSTA = Field<GISR, 1, 8, read_only>;  // GACTSTA
        using GPENDSTA = Field<GISR, 1, 9, read_only>; // GPENDSTA
    };
    struct VTFIDR : PackedRegister<PFIC_pack, RegBitSize::b32, 80 * 8> // ID Config Register
    {
        using VTFID0 = Field<VTFIDR, 8, 0, read_write>;  // VTFID0
        using VTFID1 = Field<VTFIDR, 8, 8, read_write>;  // VTFID1
        using VTFID2 = Field<VTFIDR, 8, 16, read_write>; // VTFID2
        using VTFID3 = Field<VTFIDR, 8, 24, read_write>; // VTFID3
    };
    struct VTFADDRR0 : PackedRegister<PFIC_pack, RegBitSize::b32, 96 * 8> // Interrupt 0 address
    {
        using VTF0EN = Field<VTFADDRR0, 1, 0, read_write>; // VTF0EN
        using ADDR0 = Field<VTFADDRR0, 31, 1, read_write>; // ADDR0
    };
    struct VTFADDRR1 : PackedRegister<PFIC_pack, RegBitSize::b32, 100 * 8> // Interrupt 1 address
    {
        using VTF1EN = Field<VTFADDRR1, 1, 0, read_write>; // VTF1EN
        using ADDR1 = Field<VTFADDRR1, 31, 1, read_write>; // ADDR1
    };
    struct VTFADDRR2 : PackedRegister<PFIC_pack, RegBitSize::b32, 104 * 8> // Interrupt 2 address
    {
        using VTF2EN = Field<VTFADDRR2, 1, 0, read_write>; // VTF2EN
        using ADDR2 = Field<VTFADDRR2, 31, 1, read_write>; // ADDR2
    };
    struct VTFADDRR3 : PackedRegister<PFIC_pack, RegBitSize::b32, 108 * 8> // Interrupt 3 address
    {
        using VTF3EN = Field<VTFADDRR3, 1, 0, read_write>; // VTF3EN
        using ADDR3 = Field<VTFADDRR3, 31, 1, read_write>; // ADDR3
    };
    struct IENR1 : PackedRegister<PFIC_pack, RegBitSize::b32, 256 * 8> // Interrupt Setting Register
    {
        using INTEN = Field<IENR1, 20, 12, write_only>; // INTEN
    };
    struct IENR2 : PackedRegister<PFIC_pack, RegBitSize::b32, 260 * 8> // Interrupt Setting Register
    {
        using INTEN = Field<IENR2, 32, 0, write_only>; // INTEN
    };
    struct IENR3 : PackedRegister<PFIC_pack, RegBitSize::b32, 264 * 8> // Interrupt Setting Register
    {
        using INTEN = Field<IENR3, 32, 0, write_only>; // INTEN
    };
    struct IENR4 : PackedRegister<PFIC_pack, RegBitSize::b32, 268 * 8> // Interrupt Setting Register
    {
        using INTEN = Field<IENR4, 8, 0, write_only>; // INTEN
    };
    struct IRER1 : PackedRegister<PFIC_pack, RegBitSize::b32, 384 * 8> // Interrupt Clear Register
    {
        using INTRSET = Field<IRER1, 20, 12, write_only>; // INTRSET
    };
    struct IRER2 : PackedRegister<PFIC_pack, RegBitSize::b32, 388 * 8> // Interrupt Clear Register
    {
        using INTRSET = Field<IRER2, 32, 0, write_only>; // INTRSET
    };
    struct IRER3 : PackedRegister<PFIC_pack, RegBitSize::b32, 392 * 8> // Interrupt Clear Register
    {
        using INTRSET = Field<IRER3, 32, 0, write_only>; // INTRSET
    };
    struct IRER4 : PackedRegister<PFIC_pack, RegBitSize::b32, 396 * 8> // Interrupt Clear Register
    {
        using INTRSET = Field<IRER4, 8, 0, write_only>; // INTRSET
    };
    struct IPSR1 : PackedRegister<PFIC_pack, RegBitSize::b32, 512 * 8> // Interrupt Pending Register
    {
        using PENDSET2_3 = Field<IPSR1, 2, 2, write_only>;     // PENDSET
        using PENDSET12_31 = Field<IPSR1, 20, 12, write_only>; // PENDSET
    };
    struct IPSR2 : PackedRegister<PFIC_pack, RegBitSize::b32, 516 * 8> // Interrupt Pending Register
    {
        using PENDSET = Field<IPSR2, 32, 0, write_only>; // PENDSET
    };
    struct IPSR3 : PackedRegister<PFIC_pack, RegBitSize::b32, 520 * 8> // Interrupt Pending Register
    {
        using PENDSET = Field<IPSR3, 32, 0, write_only>; // PENDSET
    };
    struct IPSR4 : PackedRegister<PFIC_pack, RegBitSize::b32, 524 * 8> // Interrupt Pending Register
    {
        using PENDSET = Field<IPSR4, 8, 0, write_only>; // PENDSET
    };
    struct IPRR1 : PackedRegister<PFIC_pack, RegBitSize::b32, 640 * 8> // Interrupt Pending Clear Register
    {
        using PENDRESET2_3 = Field<IPRR1, 2, 2, write_only>;     // PENDRESET
        using PENDRESET12_31 = Field<IPRR1, 20, 12, write_only>; // PENDRESET
    };
    struct IPRR2 : PackedRegister<PFIC_pack, RegBitSize::b32, 644 * 8> // Interrupt Pending Clear Register
    {
        using PENDRESET = Field<IPRR2, 32, 0, write_only>; // PENDRESET
    };
    struct IPRR3 : PackedRegister<PFIC_pack, RegBitSize::b32, 648 * 8> // Interrupt Pending Clear Register
    {
        using PENDRESET = Field<IPRR3, 32, 0, write_only>; // PENDRESET
    };
    struct IPRR4 : PackedRegister<PFIC_pack, RegBitSize::b32, 652 * 8> // Interrupt Pending Clear Register
    {
        using PENDRESET = Field<IPRR4, 8, 0, write_only>; // PENDRESET
    };
    struct IACTR1 : PackedRegister<PFIC_pack, RegBitSize::b32, 768 * 8> // Interrupt ACTIVE Register
    {
        using IACTS2_3 = Field<IACTR1, 2, 2, write_only>;     // IACTS
        using IACTS12_31 = Field<IACTR1, 20, 12, write_only>; // IACTS
    };
    struct IACTR2 : PackedRegister<PFIC_pack, RegBitSize::b32, 772 * 8> // Interrupt ACTIVE Register
    {
        using IACTS = Field<IACTR2, 32, 0, write_only>; // IACTS
    };
    struct IACTR3 : PackedRegister<PFIC_pack, RegBitSize::b32, 776 * 8> // Interrupt ACTIVE Register
    {
        using IACTS = Field<IACTR3, 32, 0, write_only>; // IACTS
    };
    struct IACTR4 : PackedRegister<PFIC_pack, RegBitSize::b32, 780 * 8> // Interrupt ACTIVE Register
    {
        using IACTS = Field<IACTR4, 8, 0, write_only>; // IACTS
    };
    struct IPRIOR0 : PackedRegister<PFIC_pack, RegBitSize::b8, 1024 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR1 : PackedRegister<PFIC_pack, RegBitSize::b8, 1025 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR2 : PackedRegister<PFIC_pack, RegBitSize::b8, 1026 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR3 : PackedRegister<PFIC_pack, RegBitSize::b8, 1027 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR4 : PackedRegister<PFIC_pack, RegBitSize::b8, 1028 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR5 : PackedRegister<PFIC_pack, RegBitSize::b8, 1029 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR6 : PackedRegister<PFIC_pack, RegBitSize::b8, 1030 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR7 : PackedRegister<PFIC_pack, RegBitSize::b8, 1031 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR8 : PackedRegister<PFIC_pack, RegBitSize::b8, 1032 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR9 : PackedRegister<PFIC_pack, RegBitSize::b8, 1033 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR10 : PackedRegister<PFIC_pack, RegBitSize::b8, 1034 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR11 : PackedRegister<PFIC_pack, RegBitSize::b8, 1035 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR12 : PackedRegister<PFIC_pack, RegBitSize::b8, 1036 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR13 : PackedRegister<PFIC_pack, RegBitSize::b8, 1037 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR14 : PackedRegister<PFIC_pack, RegBitSize::b8, 1038 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR15 : PackedRegister<PFIC_pack, RegBitSize::b8, 1039 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR16 : PackedRegister<PFIC_pack, RegBitSize::b8, 1040 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR17 : PackedRegister<PFIC_pack, RegBitSize::b8, 1041 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR18 : PackedRegister<PFIC_pack, RegBitSize::b8, 1042 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR19 : PackedRegister<PFIC_pack, RegBitSize::b8, 1043 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR20 : PackedRegister<PFIC_pack, RegBitSize::b8, 1044 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR21 : PackedRegister<PFIC_pack, RegBitSize::b8, 1045 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR22 : PackedRegister<PFIC_pack, RegBitSize::b8, 1046 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR23 : PackedRegister<PFIC_pack, RegBitSize::b8, 1047 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR24 : PackedRegister<PFIC_pack, RegBitSize::b8, 1048 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR25 : PackedRegister<PFIC_pack, RegBitSize::b8, 1049 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR26 : PackedRegister<PFIC_pack, RegBitSize::b8, 1050 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR27 : PackedRegister<PFIC_pack, RegBitSize::b8, 1051 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR28 : PackedRegister<PFIC_pack, RegBitSize::b8, 1052 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR29 : PackedRegister<PFIC_pack, RegBitSize::b8, 1053 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR30 : PackedRegister<PFIC_pack, RegBitSize::b8, 1054 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR31 : PackedRegister<PFIC_pack, RegBitSize::b8, 1055 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR32 : PackedRegister<PFIC_pack, RegBitSize::b8, 1056 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR33 : PackedRegister<PFIC_pack, RegBitSize::b8, 1057 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR34 : PackedRegister<PFIC_pack, RegBitSize::b8, 1058 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR35 : PackedRegister<PFIC_pack, RegBitSize::b8, 1059 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR36 : PackedRegister<PFIC_pack, RegBitSize::b8, 1060 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR37 : PackedRegister<PFIC_pack, RegBitSize::b8, 1061 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR38 : PackedRegister<PFIC_pack, RegBitSize::b8, 1062 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR39 : PackedRegister<PFIC_pack, RegBitSize::b8, 1063 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR40 : PackedRegister<PFIC_pack, RegBitSize::b8, 1064 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR41 : PackedRegister<PFIC_pack, RegBitSize::b8, 1065 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR42 : PackedRegister<PFIC_pack, RegBitSize::b8, 1066 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR43 : PackedRegister<PFIC_pack, RegBitSize::b8, 1067 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR44 : PackedRegister<PFIC_pack, RegBitSize::b8, 1068 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR45 : PackedRegister<PFIC_pack, RegBitSize::b8, 1069 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR46 : PackedRegister<PFIC_pack, RegBitSize::b8, 1070 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR47 : PackedRegister<PFIC_pack, RegBitSize::b8, 1071 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR48 : PackedRegister<PFIC_pack, RegBitSize::b8, 1072 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR49 : PackedRegister<PFIC_pack, RegBitSize::b8, 1073 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR50 : PackedRegister<PFIC_pack, RegBitSize::b8, 1074 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR51 : PackedRegister<PFIC_pack, RegBitSize::b8, 1075 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR52 : PackedRegister<PFIC_pack, RegBitSize::b8, 1076 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR53 : PackedRegister<PFIC_pack, RegBitSize::b8, 1077 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR54 : PackedRegister<PFIC_pack, RegBitSize::b8, 1078 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR55 : PackedRegister<PFIC_pack, RegBitSize::b8, 1079 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR56 : PackedRegister<PFIC_pack, RegBitSize::b8, 1080 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR57 : PackedRegister<PFIC_pack, RegBitSize::b8, 1081 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR58 : PackedRegister<PFIC_pack, RegBitSize::b8, 1082 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR59 : PackedRegister<PFIC_pack, RegBitSize::b8, 1083 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR60 : PackedRegister<PFIC_pack, RegBitSize::b8, 1084 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR61 : PackedRegister<PFIC_pack, RegBitSize::b8, 1085 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR62 : PackedRegister<PFIC_pack, RegBitSize::b8, 1086 * 8> // Interrupt Priority Register
    {
    };
    struct IPRIOR63 : PackedRegister<PFIC_pack, RegBitSize::b8, 1087 * 8> // Interrupt Priority Register
    {
    };
    struct SCTLR : PackedRegister<PFIC_pack, RegBitSize::b32, 3344 * 8> // System Control Register
    {
        using SLEEPONEXIT = Field<SCTLR, 1, 1, read_write>; // SLEEPONEXIT
        using SLEEPDEEP = Field<SCTLR, 1, 2, read_write>;   // SLEEPDEEP
        using WFITOWFE = Field<SCTLR, 1, 3, read_write>;    // WFITOWFE
        using SEVONPEND = Field<SCTLR, 1, 4, read_write>;   // SEVONPEND
        using SETEVENT = Field<SCTLR, 1, 5, read_write>;    // SETEVENT
        using SYSRESET = Field<SCTLR, 1, 31, read_write>;   // SYSRESET
    };
    struct STK_CTLR : PackedRegister<PFIC_pack, RegBitSize::b32, 4096 * 8> // System counter control register
    {
        using STE = Field<STK_CTLR, 1, 0, read_write>;   // System counter enable
        using STIE = Field<STK_CTLR, 1, 1, read_write>;  // System counter interrupt enable
        using STCLK = Field<STK_CTLR, 1, 2, read_write>; // System selects the clock source
        using STRE = Field<STK_CTLR, 1, 3, read_write>;  // System reload register
        using MODE = Field<STK_CTLR, 1, 4, read_write>;  // System Mode
        using INIT = Field<STK_CTLR, 1, 5, read_write>;  // System Initialization update
        using SWIE = Field<STK_CTLR, 1, 31, read_write>; // System software triggered interrupts enable
    };
    struct STK_SR : PackedRegister<PFIC_pack, RegBitSize::b32, 4100 * 8> // System START
    {
        using CNTIF = Field<STK_SR, 1, 0, read_write>; // CNTIF
    };
    struct STK_CNTL : PackedRegister<PFIC_pack, RegBitSize::b32, 4104 * 8> // System counter low register
    {
        using CNTL = Field<STK_CNTL, 32, 0, read_write>; // CNTL
    };
    struct STK_CMPLR : PackedRegister<PFIC_pack, RegBitSize::b32, 4112 * 8> // System compare low register
    {
        using CMPL = Field<STK_CMPLR, 32, 0, read_write>; // CMPL
    };
} // namespace PFIC

namespace GPIO
{
    typedef enum
    {
        GPIO_CFGLR_IN_ANALOG = 0,
        GPIO_CFGLR_IN_FLOAT = 4,
        GPIO_CFGLR_IN_PUPD = 8,
        GPIO_CFGLR_OUT_10Mhz_PP = 1,
        GPIO_CFGLR_OUT_2Mhz_PP = 2,
        GPIO_CFGLR_OUT_50Mhz_PP = 3,
        GPIO_CFGLR_OUT_10Mhz_OD = 5,
        GPIO_CFGLR_OUT_2Mhz_OD = 6,
        GPIO_CFGLR_OUT_50Mhz_OD = 7,
        GPIO_CFGLR_OUT_10Mhz_AF_PP = 9,
        GPIO_CFGLR_OUT_2Mhz_AF_PP = 10,
        GPIO_CFGLR_OUT_50Mhz_AF_PP = 11,
        GPIO_CFGLR_OUT_10Mhz_AF_OD = 13,
        GPIO_CFGLR_OUT_2Mhz_AF_OD = 14,
        GPIO_CFGLR_OUT_50Mhz_AF_OD = 15,
    } GPIO_CFGLR_PIN_MODE_Typedef;
}

namespace SysTick
{
    static uint32_t ticksPerUs = 3;
    static inline void init(bool pll)
    {
        PFIC::STK_CTLR::merge_write<PFIC::STK_CTLR::STE, 1>().with<PFIC::STK_CTLR::STCLK, 1>().done();
        RCC::CFGR0::merge_write<RCC::CFGR0::SW, 0>().with<RCC::CFGR0::HPRE, 0>().with<RCC::CFGR0::PLLSRC, 0>().done();
        if (pll)
        {
            RCC::CTLR::merge_write<RCC::CTLR::HSION, 1>().with<RCC::CTLR::HSITRIM, 0x10>().with<RCC::CTLR::PLLON, 1>().done();
            FLASH::ACTLR::LATENCY::write<1>();
            RCC::INTR::merge_write<RCC::INTR::LSIRDYC, 1>().with<RCC::INTR::HSIRDYC, 1>().with<RCC::INTR::HSERDYC, 1>().with<RCC::INTR::PLLRDYC, 1>().with<RCC::INTR::CSSC, 1>().done();
            while (RCC::CTLR::PLLRDY::read() == 0)
                ;
            RCC::CFGR0::SW::write<0b10>();
            while (RCC::CFGR0::SWS::read() != 0b10)
                ;
            ticksPerUs = 48;
        }
        else
        {
            RCC::CTLR::merge_write<RCC::CTLR::HSION, 1>().with<RCC::CTLR::HSITRIM, 0x10>().with<RCC::CTLR::PLLON, 0>().done();
            FLASH::ACTLR::LATENCY::write<0>();
            ticksPerUs = 24;
        }
    }
    static inline uint32_t getSystick()
    {
        return PFIC::STK_CNTL::CNTL::read();
    }
    static inline void delayTicks(uint32_t n)
    {
        uint32_t targend = getSystick() + n;
        while (((int32_t)(getSystick() - targend)) < 0)
            ;
    }
    static inline void delayUntil(uint32_t *last, uint32_t diff)
    {
        *last += diff;
        while (((int32_t)(getSystick() - *last)) < 0)
            ;
    }
    static inline uint32_t msToTicks(uint32_t ms)
    {
        return ms * ticksPerUs * 1000;
    }
    static inline uint32_t usToTicks(uint32_t us)
    {
        return us * ticksPerUs;
    }
} // namespace SysTick

#endif