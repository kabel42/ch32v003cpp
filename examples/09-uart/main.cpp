#include <ch32v003.h>
#include <cstdio>
using namespace cppreg;

int main(void)
{
    Clock::init(0); // 3V -> 12MHz max ADC speed
	RCC::APB2PCENR::IOPDEN::set();
	GPIOD::CFGLR::merge_write<GPIOD::CFGLR::MODE0, GPIO::GPIO_CFGLR_OUT_2Mhz_PP>()
						.with<GPIOD::CFGLR::MODE1, GPIO::GPIO_CFGLR_IN_FLOAT>()
						.with<GPIOD::CFGLR::MODE2, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE3, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE4, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE5, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE6, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.with<GPIOD::CFGLR::MODE7, GPIO::GPIO_CFGLR_IN_ANALOG>()
						.done();

	UART::init(115200);

	const char str[] = "Hello World\n";

    while (true)
    {
		GPIOD::BCR::BR0::write<1>();
		for(size_t i = 0; i<sizeof(str); i++)
		{
			UART::putc(str[i]);
		}
		GPIOD::BSHR::BS0::write<1>();

		Clock::delay_ms(100);
    }
	while(1);
}