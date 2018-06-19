#include "common.h"

int main()
{
    // SDL initialization
    if (SDL_Init(SDL_INIT_NOPARACHUTE) && SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
    else
    {
        SDL_Log("SDL initialized");
    }

    // Create a window instance
    SDL_Window *window = SDL_CreateWindow(
        "Text",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_OPENGL);

    // Generate an opengl context and map it to the window instance
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    // Main game loop
    bool isRunning = true;
    while (isRunning)
    {
        SDL_GL_SwapWindow(window);
    }

    // ready buffers and switch

    // Clean up
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);

    return 0;
}