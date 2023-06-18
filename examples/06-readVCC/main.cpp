#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

int main(void)
{
    Clock::init(0); // 3V -> 12MHz max ADC speed
	RCC::APB2PCENR::IOPDEN::write<1>();
	RCC::APB2PCENR::ADC1EN::write<1>();

	GPIOC::CFGLR::merge_write<GPIOC::CFGLR::MODE0, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE1, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE2, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE4, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE5, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE6, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOC::CFGLR::MODE7, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.done();

	RCC::APB2PRSTR::ADC1RST::write<1>();
	RCC::APB2PRSTR::ADC1RST::write<0>();

	ADC1::RSQR1::L::write<0>();
	ADC1::RSQR3::SQ1::write<8>(); // 2-7, A2-A7; A2: C4, ...; 0/1 - A2/A1: ExtOsc; 8 - Vref: 1.2V
	ADC1::SAMPTR2_CHARGE2::SMP8_TKCG8::write<ADC::SAMPL_TIME_241>();

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

    debug::WaitForDebuggerToAttach();
    printf("Hi\n");
    while (true)
    {
			//ADC1::CTLR2::ADON::write<1>();
			ADC1::CTLR2::SWSTART::write<1>();
			while(ADC1::STATR::EOC::read() == 0);
			printf("VCC: %lu mV\n", ((1200*1024)/ADC1::RDATAR::DATA::read()));
			Clock::delay_ms(100);
    }
	while(1);
}