#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

int main(void)
{
    Clock::init(0); // 3V -> 12MHz max ADC speed
	RCC::APB2PCENR::IOPCEN::write<1>();
	RCC::APB2PCENR::IOPDEN::write<1>();
	RCC::APB2PCENR::ADC1EN::write<1>();

	// set GPIOC[0,1] as output
    GPIOC::CFGLR::merge_write<GPIOC::CFGLR::MODE0, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>()
		                .with<GPIOC::CFGLR::MODE1, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>()
						.with<GPIOC::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.done();

	RCC::APB2PRSTR::ADC1RST::write<1>();
	RCC::APB2PRSTR::ADC1RST::write<0>();

	ADC1::RSQR1::L::write<0>();
	ADC1::RSQR3::SQ1::write<2>(); // 2-7, 2 - A2: C4; 0/1 - A2/A1: ExtOsc

	ADC1::SAMPTR2_CHARGE2::SMP2_TKCG2::write<7>();

	ADC1::CTLR2::EXTSEL::write<0b111>();
	ADC1::CTLR2::ADON::write<1>();
	while(ADC1::CTLR2::ADON::read() == 0)
		printf(".");
	Clock::delayTicks(Clock::msToTicks(1));

	ADC1::CTLR2::RSTCAL::write<1>();
	while(ADC1::CTLR2::RSTCAL::read() == 1);

	ADC1::CTLR2::CAL::write<1>();
	while(ADC1::CTLR2::CAL::read() == 1);
	printf("cal: %lu\n", ADC1::RDATAR::DATA::read());

    debug::WaitForDebuggerToAttach();
    printf("Hi\n");
    while (true)
    {
			//ADC1::CTLR2::ADON::write<1>();
			ADC1::CTLR2::SWSTART::write<1>();
			while(ADC1::STATR::EOC::read() == 0);
			printf("ADC: %lu\n", (ADC1::RDATAR::DATA::read()*3300)/1024);
    }
	while(1);
}