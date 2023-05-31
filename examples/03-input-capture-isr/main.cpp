#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

#define queuelen 16
volatile uint32_t captureVals[queuelen];
volatile size_t read = 0;
volatile size_t write = 0;

extern "C"
{
void TIM1_CC_IRQHandler(void) __attribute__((interrupt));
void TIM1_CC_IRQHandler(void)
{
	// capture
    if(TIM1::INTFR::CC1IF::read())
	{
		// get capture
		captureVals[write++] = 0x00010000 | TIM1::CH1CVR::CH1CVRfield::read(); // capture valur
		if (write == queuelen)
		{
			write = 0;
		}
		// overflow
        if(TIM1::INTFR::CC1OF::read())
		{
			// clear
            TIM1::INTFR::CC1OF::write<0>();
			printf("OF1\n");
		}
	}
	//else if (TIM1->INTFR & TIM_CC2IF)
    else if(TIM1::INTFR::CC2IF::read())
	{
		// get capture
		captureVals[write++] = TIM1::CH2CVR::CH2CVRfield::read(); // capture valur
		if (write == queuelen)
		{
			write = 0;
		}
		// overflow
        if(TIM1::INTFR::CC2OF::read())
		{
			// clear
            TIM1::INTFR::CC2OF::write<0>();
			printf("OF0\n");
		}
	}
	else
	{
		printf("badtrigger\n");
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
		                .with<GPIOC::CFGLR::MODE1, GPIO::GPIO_CFGLR_OUT_10Mhz_PP>().done();

	// enable and reset TIM1
    RCC::APB2PCENR::TIM1EN::write<1>();
    RCC::APB2PRSTR::TIM1RST::write<1>();
    RCC::APB2PRSTR::TIM1RST::write<0>();

	GPIOD::CFGLR::MODE2::write<GPIO::GPIO_CFGLR_IN_FLOAT>();

	// TIM1 overflow
    TIM1::ATRLR::ATRLRfield::write<0xFFFF>();
	// TIM1 prescaler
    TIM1::PSC::PSCfield::write<47>(); // 48MHz/(47+1) -> 1µs resolution

	// CC1 -> D2, CC2 -> D2
    TIM1::CHCTLR1_Input::merge_write<TIM1::CHCTLR1_Input::IC1F, 3>() // only generate interrupt after 8 consecutive samples?
	                           .with<TIM1::CHCTLR1_Input::CC1S, 1>()
							   .with<TIM1::CHCTLR1_Input::IC2F, 3>()
							   .with<TIM1::CHCTLR1_Input::CC2S, 2>()
							   .done();

    TIM1::CCER::merge_write<TIM1::CCER::CC1E, 0>() // ignored if input
					  .with<TIM1::CCER::CC1P, 0>()
	                  .with<TIM1::CCER::CC2E, 0>() // ignored if input
					  .with<TIM1::CCER::CC2P, 1>().done();

    TIM1::CTLR1::merge_write<TIM1::CTLR1::CEN, 1>().done(); // CAPLVL: indicate double-edge

    // enable IRQ
    PFIC::IENR2::TIM1_CC::write<1>();
	TIM1::DMAINTENR::merge_write<TIM1::DMAINTENR::CC1IE, 1>()
	                       .with<TIM1::DMAINTENR::CC2IE, 1>().done();
	
    debug::WaitForDebuggerToAttach();
    printf("Hi\n");
    while (true)
    {
		if (read != write)
		{
			uint32_t val = captureVals[read++];
			printf("capture %ld %lu\n", val >> 16, val & 0xFFFF);
			if (read == queuelen)
			{
				read = 0;
			}
		}
    }
}