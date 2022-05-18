#ifndef SPRITE_H
#define SPRITE_H

#include "graphics.h"

typedef struct tObj {
  PGEOMETRY geo;
  int posx, posy;
  void (* draw) (struct tObj *);
  void (* clear) (struct tObj *);
} OBJECT, *POBJECT;

void draw_sprite(POBJECT o);

void clear_sprite(POBJECT o);

#endif 