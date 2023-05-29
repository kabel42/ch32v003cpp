from cmsis_svd.parser import SVDParser
import json

#with open("reg.h", "w") as out:
parser = SVDParser.for_xml_file("../ch32v003.svd")

def getAccess(reg, field):
    if not field:
        field = reg
    if field == "read-write":
        return "read_write"
    if field == "write-only":
        return "write_only"
    if field == "read-only":
        return "read_only"

def fixString(string):
    return " ".join(string.split('\n')[0].split())

print("""#include <cppreg.h>
using namespace cppreg;
""")

for peripheral in parser.get_device().peripherals:
    print(f"namespace {peripheral.name}")
    print("{")
    print(f"using {peripheral.name}_pack = RegisterPack<{hex(peripheral.base_address)}, {peripheral.address_blocks[0].size}>;")
    for reg in peripheral.registers:
        print(f"struct {reg.name} : PackedRegister<{peripheral.name}_pack, RegBitSize::b{reg.size}, {reg.address_offset}*8> // {fixString(reg.description)}")
        print("{")
        for field in reg.fields:
            print(f"using {field.name if field.name != reg.name else field.name+'field'} = Field<{reg.name}, {field.bit_width}, {field.bit_offset}, {getAccess(reg.access, field.access)}>; // {fixString(field.description)}")
        print("};")
    print("}")

