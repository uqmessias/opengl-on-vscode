#include "kernel.h"

int Kernel::start()
{
    initSDL();

    SDL_Window *window = createWindow("Text", 640, 480);
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    isRunning = true;
    while (isRunning)
    {
        update();

        render(window);
    }

    cleanUp(window, glContext);
}

int Kernel::initSDL()
{
    // SDL initialization
    if (SDL_Init(SDL_INIT_NOPARACHUTE) && SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return -1;
    }
    else
    {
        SDL_Log("SDL initialized");
    }
}

SDL_Window *Kernel::createWindow(const char *windowTitle, int width, int height)
{
    // Create a window instance
    SDL_Window *window = SDL_CreateWindow(
        windowTitle,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL);

    return window;
}
void Kernel::update()
{
}

void Kernel::render(SDL_Window *window)
{
    SDL_GL_SwapWindow(window);
}

void Kernel::cleanUp(SDL_Window *window, SDL_GLContext &glContext)
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
}
