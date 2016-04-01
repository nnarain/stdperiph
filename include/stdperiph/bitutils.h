

/**
*
*	Collection of nifty bit twiddlely macros
*
*	\author Natesh Narain
*/

#ifndef BIT_UTIL_H
#define BIT_UTIL_H

//! Bit value
#define BV(b) (1 << b)

//! set mask y in x
#define SET(x, y) ((x) |= (y))
//! clear mask y in x
#define CLR(x, y) ((x) &= (~y))
//! toggle mask y in x
#define TGL(x, y) ((x) ^= (y))

//! set bit y in x
#define SET_BIT(x, y) ( SET( x, BV(y) ) )
//! clear bit y in x
#define CLR_BIT(x, y) ( CLR( x, BV(y) ) )
//! toggle bit y in x
#define TGL_BIT(x, y) ( TGL( x, BV(y) ) )

//!
#define LOW(x) ( (x) & 0x0F)

//!
#define FORCE(port, mask, value) ( (port) = ( (port) & (~(mask))) | ( (value) & (mask) ) )
//!
#define FORCE_WORD(port, mask, value) ( (port) = ( (port) & (~(mask) & 0xFFFF) | ( (value) & (mask) ) ) )

//! check if mask y is set in x
#define IS_SET(x, y) ( x & y )
//! check if mask y is clear in x
#define IS_CLR(x, y) !( x & y )
//! check if bit y is set in x
#define IS_BIT_SET(x,y) ( IS_SET(x, BV(y)) )
//! check if bit y is clear in x
#define IS_BIT_CLR(x,y) ( IS_CLR(x, BV(y)) )

//!
#define LOW_NYB(x) ((x) & 0x0F)
//!
#define HIGH_NYB(x) ( LOW_NYB((x) >> 4) )

/* Bit pattern concatenation macros  */

#define BIT_CAT(x, y, bits) ((x<<bits) + y)
#define NYB_CAT(x, y)       ( BIT_CAT(x, y, 4) )
#define BYTE_CAT(x,y)       ( BIT_CAT(x, y, 8) )
#define WORD_CAT(x,y)       ( BIT_CAT(x, y, 16) )

//!
#define EXPAND_PORT(port)( *(volatile word * const) &(port) )

#endif // BIT_UTIL_H

