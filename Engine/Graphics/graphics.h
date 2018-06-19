#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include "../common.h"

class Graphics
{
  public:
    Graphics(SDL_Window *window);
    ~Graphics();

  private:
    void setViewport(int width, int height);
};

#include "graphics.cpp"

#endif