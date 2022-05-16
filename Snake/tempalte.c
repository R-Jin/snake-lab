/*
 * 	startup.c
 *
 */

#include "./utils/display.h"
#include "./utils/input.h"

__attribute__((naked)) __attribute__((section (".start_section")) )
void startup ( void )
{
__asm__ volatile(" LDR R0,=0x2001C000\n");		/* set stack */
__asm__ volatile(" MOV SP,R0\n");
__asm__ volatile(" BL main\n");					/* call main */
__asm__ volatile(".L1: B .L1\n");				/* never return */
}

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

typedef struct
{
  char x,y;
} POINT, *PPOINT;

#define MAX_POINTS 30
typedef struct
{
  int numpoints;
  int sizex;
  int sizey;
  POINT px[ MAX_POINTS ];
} GEOMETRY, *PGEOMETRY;

typedef struct tObj {
  PGEOMETRY geo;
  int dirx, diry;
  int posx, posy;
  void (* draw) (struct tObj *);
  void (* clear) (struct tObj *);
  void (* move) (struct tObj *);
  void (* set_speed) (struct tObj *, int, int);
} OBJECT, *POBJECT;

void draw_ballobject(POBJECT o)
{
  for (int i = 0; i < o -> geo -> numpoints; i++)
  {
    graphic_pixel_set(o -> geo -> px[i].x + o -> posx, o -> geo -> px[i].y + o -> posy);
  }
}

void clear_ballobject(POBJECT o)
{
  for (int i = 0; i < o -> geo -> numpoints; i++)
  {
    graphic_pixel_clear(o -> geo -> px[i].x + o -> posx, o -> geo -> px[i].y + o -> posy);
  }
}

void move_ballobject(POBJECT o)
{
  clear_ballobject(o);

  if (o -> posx < 3 && o -> dirx < 0)
  {
    o -> posx = 0;
    o -> dirx = 3;
  }
  else if (o -> posx > 125 && o -> dirx > 0)
  {
    o -> posx = 128;
    o -> dirx = -3;
  }
  else
    o -> posx += o -> dirx;

  if (o -> posy < 3 && o -> diry < 0)
  {
    o -> posy = 0;
    o -> diry = 3;
  }
  else if (o -> posy > 64 && o -> diry > 0)
  {
    o -> posy = 64;
    o -> diry = -3;
  }
  else
    o -> posy += o -> diry;

  draw_ballobject(o);
}

void set_ballobject_speed(POBJECT o, int speedx, int speedy)
{
  o -> dirx = speedx;
  o -> diry = speedy;
}

static GEOMETRY ball_geometry = {
  12,         // numpoints 
  4, 4,       // sizex, sizey
  {
    // px[0, 1, 2, ...]
    {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {1,3}, {2,0}, {2,1}, {2,2}, {2,3}, {3,1}, {3,2}
  }
};

static OBJECT ballobject = {
  &ball_geometry,     // geometri för en boll 
  0, 0,               // initiala riktningskoordinater
  1, 1,               // initial startposition
  draw_ballobject,
  clear_ballobject,
  move_ballobject,
  set_ballobject_speed
};

void main(void)
{
  char c;
  POBJECT p = &ballobject;
  input_init();
  graphic_initialize();
  graphic_clear_screen();
  while (1)
  {
    p -> move( p );
    delay_milli(20);
    c = keyb();
    switch ( c )
    {
      case 6:
        if ( p -> dirx != -3)
          p -> set_speed( p, 3, 0 );
        break;

      case 4:
        if ( p -> dirx != 3 )
          p -> set_speed( p, -3, 0 );
        break;

      case 5:
        p -> set_speed( p, 0, 0 );
        break;

      case 2:
        if ( p -> diry != 3)
          p -> set_speed( p, 0, -3 );
        break;

      case 8:
        if ( p -> diry != -3 )
          p -> set_speed( p, 0, 3 );
        break;
    }
  }

}