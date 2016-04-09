
#ifndef COMBINED_REGISTER_H
#define COMBINED_REGISTER_H

#include "stdperiph/io_port.h"

namespace stdperiph
{
template<int PERIPH_H, int PERIPH_L>
class CombinedRegister
{
public:

	static void write(uint16_t value)
	{
		IO_PORT8(PERIPH_H) = (value >> 8);
		IO_PORT8(PERIPH_L) = (value & 0x00FF);
	}

private:
};
}

#endif // COMBINED_REGISTER_H
