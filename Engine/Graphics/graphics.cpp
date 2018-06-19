#include "graphics.h"

Graphics::Graphics(SDL_Window *window)
{
    // Specify shading technique used during rasteriation stage
    glShadeModel(GL_SMOOTH); // Interpolation of vertex colors

    // Controls the quality of the interpolation we have specified
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // When the color buffer is cleared, define the color we would like to display
    glClearColor(0.0f /*red*/, 0.0f /*green*/, 0.0f /*blue*/, 0.0f /*alpha*/);

    // Try to initialize Glew and check if it was successful
    GLenum error = glewInit();
    if (error != GLEW_OK)
    {
        SDL_Log("Error: %s\n", glewGetErrorString(error));
    }
    else
    {
        SDL_Log("GLEW initialized");
        setViewport(SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h);
    }
}

Graphics::~Graphics()
{
}

void Graphics::setViewport(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}