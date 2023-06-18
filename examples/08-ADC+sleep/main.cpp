#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

int main(void)
{
    Clock::init(0); // 3V -> 12MHz max ADC speed
	RCC::APB2PCENR::IOPAEN::set();
	RCC::APB2PCENR::IOPCEN::set();
	RCC::APB2PCENR::IOPDEN::set();
	RCC::APB2PCENR::ADC1EN::set();
	GPIOA::CFGLR::merge_write<GPIOA::CFGLR::MODE0, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOA::CFGLR::MODE1, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOA::CFGLR::MODE2, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOA::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOA::CFGLR::MODE4, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOA::CFGLR::MODE5, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOA::CFGLR::MODE6, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOA::CFGLR::MODE7, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.done();
	GPIOC::CFGLR::merge_write<GPIOC::CFGLR::MODE0, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE1, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE2, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE4, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE5, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE6, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE7, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.done();
	GPIOD::CFGLR::merge_write<GPIOD::CFGLR::MODE0, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>()
						.with<GPIOD::CFGLR::MODE1, GPIO::GPIO_CFGLR_IN_PUPD>()
						.with<GPIOD::CFGLR::MODE2, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE4, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE5, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE6, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE7, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.done();
	RCC::APB1PCENR::PWREN::write<1>(); // enable power control

	// rest ADC
	RCC::APB2PRSTR::ADC1RST::write<1>();
	RCC::APB2PRSTR::ADC1RST::write<0>();

	ADC1::RSQR1::L::write<0>();   // converson chain length
	ADC1::RSQR3::SQ1::write<8>(); // channel 2-7, A2-A7; A2: C4, ...; 0/1 - A2/A1: ExtOsc; 8 - Vref: 1.2V
	ADC1::SAMPTR2_CHARGE2::SMP8_TKCG8::write<ADC::SAMPL_TIME_241>(); // sample time

	ADC1::CTLR2::EXTSEL::write<ADC::EXTSEL_SWSTART>();
	ADC1::CTLR2::ADON::write<1>();
	while(ADC1::CTLR2::ADON::read() == 0)
		printf(".");
	Clock::delayTicks(Clock::msToTicks(1));

	ADC1::CTLR2::RSTCAL::write<1>();
	while(ADC1::CTLR2::RSTCAL::read() == 1);

	ADC1::CTLR2::CAL::write<1>();
	while(ADC1::CTLR2::CAL::read() == 1);
	printf("cal: %lu\n", ADC1::RDATAR::DATA::read());
    printf("ADC up\n");

	RCC::RSTSCKR::LSION::set(); // enable LSI
	while(RCC::RSTSCKR::LSIRDY::read() == 0) {} // wait for LSI

	EXTI::EVENR::MR9::set(); // enable events from auto-wareup events
	EXTI::RTENR::TR9::set(); // enable event on falling edge

	PWR::AWUPSC::AWUPSCfield::write<PWR::DIV10240>(); // prescale to 64 Hz
	PWR::AWUAPR::AWUAPRfield::write<13>(); // autowakeup ~1 Hz
	PWR::AWUCSR::AWUEN::set();

    while (true)
    {
		// signal start of cycle
		GPIOD::BCR::BR0::write<1>();

		// enable ADC
		ADC1::CTLR2::ADON::set();
		while(ADC1::CTLR2::ADON::is_clear());

		// start conversion
		ADC1::CTLR2::SWSTART::write<1>();
		while(ADC1::STATR::EOC::read() == 0);

		// read value
		uint32_t Vref = ((1200*1024)/ADC1::RDATAR::DATA::read());
		//printf("VCC: %lu mV\n", Vref);

		// put adc to sleep, ADC seems to not be clock gated
		ADC1::CTLR2::ADON::clear();

		// end of cycle
		GPIOD::BSHR::BS0::write<1>();

		// sleep
		sleep_deep_wfe();
    }
	while(1);
}