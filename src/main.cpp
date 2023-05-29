#include "ch32v003.h"
using namespace cppreg;

int main(void)
{
    // init systick
    PFIC::STK_CTLR::merge_write<PFIC::STK_CTLR::STE, 1>().with<PFIC::STK_CTLR::STCLK, 1>().done();
    // enable GPIOC
    RCC::APB2PCENR::IOPCEN::write<1>();
    // set GPIOC0 as output
    GPIOC::CFGLR::MODE0::write<GPIO::GPIO_CFGLR_OUT_10Mhz_PP>();

    while (true)
    {
        GPIOC::BSHR::BS0::write<1>();
        SysTick::DelayTicks(24 * 1000 * 100);
        GPIOC::BSHR::BR0::write<1>();
        SysTick::DelayTicks(24 * 1000 * 100);
    }
}