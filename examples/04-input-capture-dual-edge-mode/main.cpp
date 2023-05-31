#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

#define queuelen 16
volatile uint32_t captureVals[queuelen];
volatile size_t read = 0;
volatile size_t write = 0;
volatile uint16_t cnt = 0;

extern "C"
{
void TIM1_CC_IRQHandler(void) __attribute__((interrupt));
void TIM1_CC_IRQHandler(void)
{
	// capture
    if(TIM1::INTFR::CC1IF::read())
	{
		// get capture
		captureVals[write++] = TIM1::CH1CVR::value::read() | (cnt<<16) | ((uint64_t)TIM1::CH1CVR::level::read())<<31; // capture value
		if (write == queuelen)
		{
			write = 0;
		}
		// overflow
        if(TIM1::INTFR::CC1OF::read())
		{
			// clear
            //TIM1::INTFR::CC1OF::write<0>();
			TIM1::INTFR::rw_mem_device() = ~(TIM1::INTFR::CC1OF::mask);
			printf("OF\n");
		}
	}
	else
	{
		printf("badtrigger\n");
	}
}
void TIM1_UP_IRQHandler(void) __attribute__((interrupt));
void TIM1_UP_IRQHandler(void)
{
	if(TIM1::INTFR::UIF::read())
	{
		cnt++;
		cnt &= 0x7FFF;
		TIM1::INTFR::rw_mem_device() = ~(TIM1::INTFR::UIF::mask);
	}
}
}

int main(void)
{
    Clock::init(1);
    // enable GPIOC and D
    RCC::APB2PCENR::IOPCEN::write<1>();
	RCC::APB2PCENR::IOPDEN::write<1>();

	// set GPIOC[0,1] as output
    GPIOC::CFGLR::merge_write<GPIOC::CFGLR::MODE0, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>()
		                .with<GPIOC::CFGLR::MODE1, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>()
						.done();

	// enable and reset TIM1
    RCC::APB2PCENR::TIM1EN::write<1>();
    RCC::APB2PRSTR::TIM1RST::write<1>();
    RCC::APB2PRSTR::TIM1RST::write<0>();

	// D2 input floating
	GPIOD::CFGLR::MODE2::write<GPIO::GPIO_CFGLR_IN_FLOAT>();

	// TIM1 overflow
    TIM1::ATRLR::ATRLRfield::write<0xFFFF>();
	// TIM1 prescaler
    TIM1::PSC::PSCfield::write<47>(); // 48MHz/(47+1) -> 1µs resolution

	// CC1 -> D2
    TIM1::CHCTLR1_Input::merge_write<TIM1::CHCTLR1_Input::IC1F, 3>() // only generate interrupt after 8 consecutive samples?
	                           .with<TIM1::CHCTLR1_Input::CC1S, 3>() // IC1 mapped to TRC
							   .done();

    TIM1::CCER::merge_write<TIM1::CCER::CC1E, 1>() // enable channel
					  .with<TIM1::CCER::CC1P, 0>() // invert polarity
					  .done();

	TIM1::SMCFGR::TS::write<4>(); // Edge detector of TI1

    TIM1::CTLR1::merge_write<TIM1::CTLR1::CEN, 1>()
					   .with<TIM1::CTLR1::TMR_CAP_LVL_EN, 1>() // CAPLVL: indicate double-edge
			           .done();

    // enable IRQ
	TIM1::DMAINTENR::merge_write<TIM1::DMAINTENR::CC1IE, 1>()
						   .with<TIM1::DMAINTENR::UIE, 1>()
						   .done();
	PFIC::IENR2::merge_write<PFIC::IENR2::TIM1_CC, 1>()
					   .with<PFIC::IENR2::TIM1_UP, 1>()
					   .done();
	
    debug::WaitForDebuggerToAttach();
    printf("Hi\n");
    while (true)
    {
		if (read != write)
		{
			auto val = captureVals[read++];
			printf("capture %lu %lu\n", val >> 31, val & 0x7FFFFFFF);
			if (read == queuelen)
			{
				read = 0;
			}
		}
    }
}