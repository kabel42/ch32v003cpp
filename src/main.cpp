#include "ch32v003.h"
using namespace cppreg;

int main(void)
{
    SysTick::init(0);
    // enable GPIOC
    RCC::APB2PCENR::IOPCEN::write<1>();
    // set GPIOC0 as output
    GPIOC::CFGLR::MODE0::write<GPIO::GPIO_CFGLR_OUT_10Mhz_PP>();
    uint32_t time = SysTick::getSystick();
    while (true)
    {
        GPIOC::BSHR::BS0::write<1>();
        SysTick::delayUntil(&time, SysTick::msToTicks(500));
        GPIOC::BSHR::BR0::write<1>();
        SysTick::delayUntil(&time, SysTick::msToTicks(500));
    }
}