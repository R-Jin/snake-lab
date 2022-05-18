#include "sprite.h"

void draw_sprite(POBJECT o)
{
  for (int i = 0; i < o -> geo -> numpoints; i++)
  {
    graphic_pixel_set(o -> geo -> px[i].x + o -> posx * 8 + 1, o -> geo -> px[i].y + o -> posy * 8 + 1);
  }
}

void clear_sprite(POBJECT o)
{
  for (int i = 0; i < o -> geo -> numpoints; i++)
  {
    graphic_pixel_clear(o -> geo -> px[i].x + o -> posx * 8 + 1, o -> geo -> px[i].y + o -> posy * 8 + 1);
  }
}