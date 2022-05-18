#include "snake.h"
#define MAX_LENGTH 128

void push(PSNAKE snake, POBJECT temp);

static GEOMETRY snakeGeo = {
    64, // numpoints 
    8, 8, // sizex, sizey
    {
        // px[0, 1, 2, ...]
        {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7}, {2,0}, {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7}, {3,0}, {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7}, {4,0}, {4,1}, {4,2}, {4,3}, {4,4}, {4,5}, {4,6}, {4,7}, {5,0}, {5,1}, {5,2}, {5,3}, {5,4}, {5,5}, {5,6}, {5,7}, {6,0}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5}, {6,6}, {6,7}, {7,0}, {7,1}, {7,2}, {7,3}, {7,4}, {7,5}, {7,6}, {7,7}
    } 
};

void move_snake(PSNAKE snake)
{
    //skapa ett objekt pos = (head + dir)
    POBJECT head = snake -> snakeParts[0];
    int posx = head -> posx + snake -> dir[0];
    int posy = head -> posy + snake -> dir[1];
	OBJECT temp = {
        &snakeGeo,     
        posx, posy,              
        draw_sprite,
        clear_sprite,
    };   
    
    //pusha objekt in i listan
    push(snake, &temp);
}

void push(PSNAKE snake, POBJECT head)
{
    POBJECT temp[MAX_LENGTH];
    temp[0] = head;
    for (int i = 1; i <= snake -> size; i++) {
        if (i < snake -> size || snake -> onApple){
            temp[i] = snake -> snakeParts[i - 1];
        }
    }
    if (snake -> onApple) 
    {
        ++snake -> size;
    }
    for (int i = 0; i < snake -> size; i++) {
        snake -> snakeParts[i] = temp[i];
    }
}

void clear_snake(PSNAKE snake)
{
    OBJECT snakePart;
    snakePart = *(snake -> snakeParts[0]);
    snakePart.clear(&snakePart);
}

void draw_snake(PSNAKE snake) { //draw only first and last?
    OBJECT snakePart;
    for (int i = 0; i < snake -> size; i++) {
        snakePart = *(snake -> snakeParts[i]);
        snakePart.draw(&snakePart);
    }
}