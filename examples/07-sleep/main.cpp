#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

int main(void)
{
    Clock::init(0); // 3V -> 12MHz max ADC speed
	RCC::APB2PCENR::IOPAEN::set();
	RCC::APB2PCENR::IOPCEN::set();
	RCC::APB2PCENR::IOPDEN::set();
	GPIOA::CFGLR::merge_write<GPIOA::CFGLR::MODE0, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOA::CFGLR::MODE1, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOA::CFGLR::MODE2, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOA::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOA::CFGLR::MODE4, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOA::CFGLR::MODE5, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOA::CFGLR::MODE6, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOA::CFGLR::MODE7, GPIO::GPIO_CFGLR_IN_PUPD>()
						.done();
	GPIOC::CFGLR::merge_write<GPIOC::CFGLR::MODE0, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>()
						.with<GPIOC::CFGLR::MODE1, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOC::CFGLR::MODE2, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOC::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOC::CFGLR::MODE4, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOC::CFGLR::MODE5, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOC::CFGLR::MODE6, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOC::CFGLR::MODE7, GPIO::GPIO_CFGLR_IN_PUPD>()
						.done();
	GPIOD::CFGLR::merge_write<GPIOD::CFGLR::MODE0, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOD::CFGLR::MODE1, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOD::CFGLR::MODE2, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOD::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOD::CFGLR::MODE4, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOD::CFGLR::MODE5, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOD::CFGLR::MODE6, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOD::CFGLR::MODE7, GPIO::GPIO_CFGLR_IN_PUPD>()
						.done();
	RCC::APB1PCENR::PWREN::write<1>(); // enable power control

	RCC::RSTSCKR::LSION::set(); // enable LSI
	while(RCC::RSTSCKR::LSIRDY::read() == 0) {} // wait for LSI

	EXTI::EVENR::MR9::set(); // enable events from auto-wareup events
	EXTI::RTENR::TR9::set(); // enable event on falling edge

	PWR::AWUPSC::AWUPSCfield::write<PWR::DIV10240>(); // prescale 128 kHz / 10240 = 12.5 Hz
	PWR::AWUAPR::AWUAPRfield::write<13>(); // autowakeup ~1 Hz
	PWR::AWUCSR::AWUEN::set();

	PWR::CTLR::PDDS::set();
	PFIC::SCTLR::SLEEPDEEP::set();

    while (true)
    {
		GPIOC::BCR::BR0::write<1>();
		Clock::delayTicks(Clock::msToTicks(10));
		GPIOC::BSHR::BS0::write<1>();
		__WFE();
    }
	while(1);
}