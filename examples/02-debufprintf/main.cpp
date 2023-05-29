#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

int main(void)
{
    Clock::init(0);
    // enable GPIOC
    RCC::APB2PCENR::IOPCEN::write<1>();
    // set GPIOC[0,1] as output
    GPIOC::CFGLR::merge_write<GPIOC::CFGLR::MODE0, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>().with<GPIOC::CFGLR::MODE1, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>().done();
    uint32_t time = Clock::getSystick();

    debug::WaitForDebuggerToAttach();
    printf("Hi\n");
    uint32_t secs = 0;
    while (true)
    {
        printf("% 8lX\n", secs++);
        GPIOC::BSHR::merge_write<GPIOC::BSHR::BS0, 1>().with<GPIOC::BSHR::BR1, 1>().done();;
        Clock::delayUntil(&time, Clock::msToTicks(500));
        GPIOC::BSHR::merge_write<GPIOC::BSHR::BR0, 1>().with<GPIOC::BSHR::BS1, 1>().done();;
        Clock::delayUntil(&time, Clock::msToTicks(500));
    }
}