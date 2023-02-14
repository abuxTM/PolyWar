#include "engine.h"

int main()
{
    Engine window("PolyWar", 1280, 720);

    // Main gameloop
    while (window.Running())
    {
        window.Update();
        window.Render();
        window.Inputs();
    }

    window.CleanUp();

    SDL_Quit();

    return 0;
}