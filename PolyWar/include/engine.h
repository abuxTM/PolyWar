#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Engine
{
    public:
        Engine(const char* title, int w, int h);

        void Update();
        void Render();
        void Inputs();

        void CleanUp();

        bool Running() { return isRunning; }

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

        bool isRunning = true;
};