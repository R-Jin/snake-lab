#include "delay.h"

#define SIMULATOR
#define STK_BASE        0xE000E010
#define STK_CTRL        ((unsigned long *) (STK_BASE))
#define STK_LOAD        ((unsigned long *) (STK_BASE + 4))
#define STK_VAL         ((unsigned long *) (STK_BASE + 8))

void delay_250ns( void )
{
  *STK_CTRL = 0;
  *STK_LOAD = ((168 / 4) - 1);
  *STK_VAL = 0;
  *STK_CTRL = 5;
  while ((*STK_CTRL & 0x10000) == 0);
  *STK_CTRL = 0;
}

void delay_mikro( unsigned int us )
{
#ifdef SIMULATOR
  us = us / 1000;
  us++;
#endif
  while (us > 0)
  {
    delay_250ns();
    delay_250ns();
    delay_250ns();
    delay_250ns();
    us--;
  }
}

void delay_milli(unsigned int ms )
{
  while (ms > 0)
  {
    delay_mikro(1000);
    ms--;
  }
}