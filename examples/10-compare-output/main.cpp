#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

extern "C"
{
void TIM2_IRQHandler(void) __attribute__((interrupt));
void TIM2_IRQHandler(void)
{
	TIM2::INTFR::CC2IF::clear();
	static int i = 100;
	TIM2::ATRLR::ATRLRfield::write(i++);
}
}

int main(void)
{
    Clock::init(1);
	RCC::APB2PCENR::IOPDEN::write<1>();
	GPIOD::CFGLR::MODE3::write<GPIO::GPIO_CFGLR_OUT_2Mhz_AF_PP>(); // T2CH2

	// enable and reset TIM1
	RCC::APB1PCENR::TIM2EN::set();
	RCC::APB1PRSTR::TIM2RST::set();
	RCC::APB1PRSTR::TIM2RST::clear();

	// TIM2 prescaler + autoreload
    TIM2::PSC::PSCfield::write<>(Clock::usToTicks(10));
	TIM2::ATRLR::ATRLRfield::write<100>();

	// TIM2 compare val
	TIM2::CH2CVR::CH2CVRfield::write<0>();

	// TIM2 level
	TIM2::CHCTLR1_Output::merge_write<TIM2::CHCTLR1_Output::OC2PE, 0>()
								.with<TIM2::CHCTLR1_Output::OC2M, 0b011>()
								.done();
	TIM2::CCER::CC2P::write<0>();

    // enable IRQ
	TIM2::DMAINTENR::CC2IE::set();
    PFIC::IENR2::TIM2::write<1>();

	TIM2::CTLR1::ARPE::set();

	// TIM2 enable
	TIM2::CCER::CC2E::set();
	TIM2::CTLR1::CEN::set();

    debug::WaitForDebuggerToAttach();
    printf("Hi\n");
    while (true)
    {
	}
}