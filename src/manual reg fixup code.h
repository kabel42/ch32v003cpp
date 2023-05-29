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
    void DelayTicks(uint32_t n)
    {
        uint32_t targend = PFIC::STK_CNTL::CNTL::read() + n;
        while (((int32_t)(PFIC::STK_CNTL::CNTL::read() - targend)) < 0)
            ;
    }
} // namespace SysTick

