
#ifndef BITREF_H
#define BITREF_H

#include <stdint.h>

#include "stdperiph/io_port.h"

namespace stdperiph
{

template<int PERIPH, int PIN>
class BitRef
{
public:
	static inline void high()
	{
		IO_PORT8(PERIPH) |= (BV(PIN));
	}

	static inline void set()
	{
		high();
	}

	static inline void low()
	{
		IO_PORT8(PERIPH) &= ~(BV(PIN));
	}

	static inline void clear()
	{
		low();
	}

	static inline void toggle()
	{
		IO_PORT8(PERIPH) ^= (BV(PIN));
	}

	static inline void set(bool val)
	{
		if(val)
			high();
		else
			low();
	}

	static inline bool value()
	{
		return IS_BIT_SET(IO_PORT8(PERIPH), PIN) != 0;
	}

	static inline bool isClear()
	{
		return !value();
	}

	static inline bool isSet()
	{
		return value();
	}

	static inline void waitUntilSet()
	{
		while(isClear());
	}

	static inline void waitUntilClear()
	{
		while(isSet());
	}
};

} // namespace stdperiph

#endif // BITREF_H
