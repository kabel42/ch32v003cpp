#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

static const uint32_t vcc = 3300;
static const uint32_t vref = 1200;

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
	ADC1::SAMPTR2_CHARGE2::SMP8_TKCG8::write<ADC::SAMPL_TIME_3>();

	ADC1::CTLR2::EXTSEL::write<ADC::EXTSEL_SWSTART>();
	ADC1::CTLR2::ADON::write<1>();
	Clock::delay_us(7);
	while(ADC1::CTLR2::ADON::read() == 0)
		printf(".");
	Clock::delayTicks(Clock::msToTicks(1));

	ADC1::CTLR2::RSTCAL::write<1>();
	while(ADC1::CTLR2::RSTCAL::read() == 1);
	ADC1::CTLR2::CAL::write<1>();
	while(ADC1::CTLR2::CAL::read() == 1);
	auto cal = ADC1::RDATAR::DATA::read();
	printf("raw cal: %lu\n", cal);
	printf("Vcal: %lu\n", cal*vcc/1024); // Vcc/2

    debug::WaitForDebuggerToAttach();
    printf("Hi\n");
    while (true)
    {
			ADC1::CTLR2::SWSTART::write<1>();
			while(ADC1::STATR::EOC::read() == 0);
			auto val = ADC1::RDATAR::DATA::read();
			printf("raw val: %lu\n", val);
			printf("Vref: %lu mV\n", (val*vcc)/1024);
			printf("Vcc:  %lu mV\n", ((vref*1024)/val));
			Clock::delay_ms(1000);
    }
	while(1);
}