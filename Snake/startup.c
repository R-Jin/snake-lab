/*
 * 	startup.c
 *
 */
#include "./utils/display.h"
#include "./utils/input.h"
#include "./utils/delay.h"
#include "./structs/sprite.h"
#include "./structs/snake.h"

__attribute__((naked)) __attribute__((section (".start_section")) )
void startup ( void )
{
__asm__ volatile(" LDR R0,=0x2001C000\n");		/* set stack */
__asm__ volatile(" MOV SP,R0\n");
__asm__ volatile(" BL main\n");					/* call main */
__asm__ volatile(".L1: B .L1\n");				/* never return */
}

static GEOMETRY fruitGeo = {
  21,         // numpoints 
  8, 8,       // sizex, sizey
  {
    // px[0, 1, 2, ...]
    {5,0}, {6,0}, {4,1}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}, {6,2}, {0,3}, {7,3}, {0,4}, {7,4}, {0,5}, {7,5}, {1,6}, {6,6}, {2,7}, {3,7}, {4,7}, {5,7}
  }
};

static OBJECT fruitObj = {
  &fruitGeo,     // geometri för en boll 
  1, 1,               // initial startposition
  draw_sprite,
  clear_sprite,
};

static GEOMETRY snakeGeo = {
    64, // numpoints 
    8, 8, // sizex, sizey
    {
        // px[0, 1, 2, ...]
        {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7}, {2,0}, {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7}, {3,0}, {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7}, {4,0}, {4,1}, {4,2}, {4,3}, {4,4}, {4,5}, {4,6}, {4,7}, {5,0}, {5,1}, {5,2}, {5,3}, {5,4}, {5,5}, {5,6}, {5,7}, {6,0}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5}, {6,6}, {6,7}, {7,0}, {7,1}, {7,2}, {7,3}, {7,4}, {7,5}, {7,6}, {7,7}
    } 
};

static OBJECT snakePart = {
  &snakeGeo,
  8, 4, 
  draw_sprite,
  clear_sprite,
};

static SNAKE snakeObj = {
  0,
  {1, 0},
  1,
  {},
  draw_snake,
  clear_snake,
  move_snake,
};

void draw_grid(void) {
  for (int y = 1; y <= 64; y +=8) {
    for (int x = 1; x <= 128; x++) {
      graphic_pixel_set(x, y);
    }
  }

  for (int x = 1; x <= 128; x +=8) {
    for (int y = 1; y <= 64; y++) {
      graphic_pixel_set(x, y);
    }
  }
}

void main(void)
{
  char c;
  POBJECT fruit = &fruitObj;
  PSNAKE snake = &snakeObj;
  snake -> snakeParts[0] = &snakePart;
  input_init();
  graphic_initialize();
  graphic_clear_screen();

  while (1)
  {
    //snake -> clear(snake);  //DOES NOT WORK?!
    graphic_clear_screen();
    snake -> move(snake);
    snake -> draw(snake);
    draw_grid();
    fruit -> draw(fruit);
    //delay_milli(20);
    
    c = keyb();
    switch ( c )
    {
      case 6:
        snake -> dir[0] = 1;
        snake -> dir[1] = 0;
        break;

      case 4:
        snake -> dir[0] = -1;
        snake -> dir[1] = 0;
        break;

      case 5:
        snake -> dir[0] = 0;
        snake -> dir[1] = 1;
        break;

      case 2:
        snake -> dir[0] = 0;
        snake -> dir[1] = -1;
        break;

      default:
        break;
    }
    
  }

}