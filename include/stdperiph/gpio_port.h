
#ifndef GPIO_PORT_H
#define GPIO_PORT_H

#include "stdperiph/io_port.h"
#include "stdperiph/bitref.h"

#define GPIO(PERIPH, DDR, NAME) typedef stdperiph::Gpio<PERIPH, DDR> NAME

namespace stdperiph
{

template<int PERIPH_ADDR, int DDR_ADDR>
struct Gpio
{
	enum
	{
		PERIPH = PERIPH_ADDR,
		DDR    = DDR_ADDR
	};
};

} // namespace stdperiph

#endif // GPIO_PORT_H
