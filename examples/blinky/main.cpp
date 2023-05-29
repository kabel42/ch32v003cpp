#include <ch32v003.h>
using namespace cppreg;

int main(void)
{
    SysTick::init(0);
    // enable GPIOC
    RCC::APB2PCENR::IOPCEN::write<1>();
    // set GPIOC[0,1] as output
    GPIOC::CFGLR::merge_write<GPIOC::CFGLR::MODE0, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>().with<GPIOC::CFGLR::MODE1, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>().done();
    uint32_t time = SysTick::getSystick();
    while (true)
    {
        GPIOC::BSHR::merge_write<GPIOC::BSHR::BS0, 1>().with<GPIOC::BSHR::BR1, 1>().done();;
        SysTick::delayUntil(&time, SysTick::msToTicks(500));
        GPIOC::BSHR::merge_write<GPIOC::BSHR::BR0, 1>().with<GPIOC::BSHR::BS1, 1>().done();;
        SysTick::delayUntil(&time, SysTick::msToTicks(500));
    }
}