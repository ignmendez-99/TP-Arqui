#ifndef VIDEO_DRIVER_H
#define VIDEO_DRIVER_H

void init_VM_Driver();
void drawPixel(unsigned int x, unsigned int y, int color);
void pintarPantalla();
void drawChar(int x, int y, char character, int fontSize, int fontColor, int backgroundColor);

#endif