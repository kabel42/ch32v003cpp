#include <cppreg.h>
using namespace cppreg;

namespace RCC
{
    using RCC_pack = RegisterPack<0x40021000, 4 * 10>;

    struct CTLR : PackedRegister<RCC_pack, RegBitSize::b32, 0>
    {
        using HSION = Field<CTLR, 1, 0, read_write>;
        using HSIRDY = Field<CTLR, 1, 1, read_only>;
        using HSITRIM = Field<CTLR, 5, 3, read_write>;
        using HSICAL = Field<CTLR, 8, 8, read_only>;
        using HSEON = Field<CTLR, 1, 16, read_write>;
        using HSERDY = Field<CTLR, 1, 17, read_only>;
        using HSEBYP = Field<CTLR, 1, 18, read_write>;
        using CSSON = Field<CTLR, 1, 19, read_write>;
        using PLLON = Field<CTLR, 1, 24, read_write>;
        using PLLRDY = Field<CTLR, 1, 25, read_only>;
    };
    struct APB2PCENR : PackedRegister<RCC_pack, RegBitSize::b32, 0x18*8>
    {
        using AFIOEN = Field<APB2PCENR, 1, 0, read_write>;
        using IOPAEN = Field<APB2PCENR, 1, 2, read_write>;
        using IOPCEN = Field<APB2PCENR, 1, 4, read_write>;
        using IOPDEN = Field<APB2PCENR, 1, 5, read_write>;
        using ADC1EN = Field<APB2PCENR, 1, 9, read_write>;
        using TIM1EN = Field<APB2PCENR, 1, 11, read_write>;
        using SPI1EN = Field<APB2PCENR, 1, 12, read_write>;
        using USART1EN = Field<APB2PCENR, 1, 14, read_write>;
    };
} // namespace RCC

namespace SysTick
{
    using SysTick_pack = RegisterPack<0xE000F000, 0x14>;

    struct CTLR : PackedRegister<SysTick_pack, RegBitSize::b32, 0x0>
    {
        using STE = Field<CTLR, 1, 0, read_write>;
        using STIE = Field<CTLR, 1, 1, read_write>;
        using STCLK = Field<CTLR, 1, 2, read_write>;
        using STRE = Field<CTLR, 1, 3, read_write>;
        using SWIE = Field<CTLR, 1, 31, read_write>;
    };
    struct SR : PackedRegister<SysTick_pack, RegBitSize::b32, 0x4*8>
    {
    };
    struct CNTL : PackedRegister<SysTick_pack, RegBitSize::b32, 0x8*8>
    {
        using CNT = Field<CNTL, 32, 0, read_write>;
    };
    struct CMPLR : PackedRegister<SysTick_pack, RegBitSize::b32, 0x10*8>
    {
    };

    void DelayTicks(uint32_t n)
    {
        uint32_t targend = SysTick::CNTL::CNT::read() + n;
        while (((int32_t)(SysTick::CNTL::CNT::read() - targend)) < 0)
            ;
    }
} // namespace SysTick

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

    namespace GPIOC
    {
        using GPIO_pack = RegisterPack<0x40011000, 4 * 7>;

        struct CFGLR : PackedRegister<GPIO_pack, RegBitSize::b32, 0x0*8>
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
        struct INDR : PackedRegister<GPIO_pack, RegBitSize::b32, 0x8*8>
        {
        };
        struct OUTDR : PackedRegister<GPIO_pack, RegBitSize::b32, 0xC*8>
        {
        };
        struct BSHR : PackedRegister<GPIO_pack, RegBitSize::b32, 0x10*8>
        {
            using BS0 = Field<BSHR, 1, 0, write_only>;
            using BS1 = Field<BSHR, 1, 1, write_only>;
            using BS2 = Field<BSHR, 1, 2, write_only>;
            using BS3 = Field<BSHR, 1, 3, write_only>;
            using BS4 = Field<BSHR, 1, 4, write_only>;
            using BS5 = Field<BSHR, 1, 5, write_only>;
            using BS6 = Field<BSHR, 1, 6, write_only>;
            using BS7 = Field<BSHR, 1, 7, write_only>;
            using BR0 = Field<BSHR, 1, 16, write_only>;
            using BR1 = Field<BSHR, 1, 17, write_only>;
            using BR2 = Field<BSHR, 1, 18, write_only>;
            using BR3 = Field<BSHR, 1, 19, write_only>;
            using BR4 = Field<BSHR, 1, 20, write_only>;
            using BR5 = Field<BSHR, 1, 21, write_only>;
            using BR6 = Field<BSHR, 1, 22, write_only>;
            using BR7 = Field<BSHR, 1, 23, write_only>;
        };
        struct BCR : PackedRegister<GPIO_pack, RegBitSize::b32, 0x14*8>
        {
        };
        struct LCKR : PackedRegister<GPIO_pack, RegBitSize::b32, 0x18*8>
        {
        };
    } // namespace GPIOC
} // namespace GPIO

int main(void)
{
    // init systick
    SysTick::CTLR::merge_write<SysTick::CTLR::STE, 1>().with<SysTick::CTLR::STCLK, 1>().done();
    RCC::APB2PCENR::IOPCEN::write<1>();
    GPIO::GPIOC::CFGLR::MODE0::write<GPIO::GPIO_CFGLR_OUT_10Mhz_PP>();

    while (true)
    {
        GPIO::GPIOC::BSHR::BS0::write<1>();
        SysTick::DelayTicks(24*1000*100);
        GPIO::GPIOC::BSHR::BR0::write<1>();
        SysTick::DelayTicks(24*1000*100);
    }
}