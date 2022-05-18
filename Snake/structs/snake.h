#ifndef SNAKE_H
#define SNAKE_H
#define MAX_LENGTH  128

#include "sprite.h"

typedef struct tSnake{
  int onApple;
  int dir[2];
  int size;
  POBJECT snakeParts[MAX_LENGTH];
  void (* draw) (struct tSnake *);
  void (* clear) (struct SNAKE *);
  void (* move) (struct tSnake *);
} SNAKE, *PSNAKE;

void draw_snake (PSNAKE snake);
void move_snake(PSNAKE snake);
void clear_snake (PSNAKE snake);

#endif