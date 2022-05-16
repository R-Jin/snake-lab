#ifndef DISPLAY_H
#define DISPLAY_H

__attribute__((naked))
void graphic_initialize(void);

__attribute__((naked))
void graphic_clear_screen(void);

__attribute__((naked))
void graphic_pixel_set(int x, int y);

__attribute__((naked))
void graphic_pixel_clear(int x, int y);

#endif