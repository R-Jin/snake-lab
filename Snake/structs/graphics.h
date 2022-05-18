#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct
{
  char x,y;
} POINT, *PPOINT;

#define MAX_POINTS 64

typedef struct
{
  int numpoints;
  int sizex;
  int sizey;
  POINT px[ MAX_POINTS ];
} GEOMETRY, *PGEOMETRY;

#endif