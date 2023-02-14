#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "mouse.h"

class Button
{
    public:
        Button(SDL_Renderer* ren);

        void Update(Mouse&);
        void Render(SDL_Renderer* ren);

        SDL_Texture* tex;
        SDL_Rect srect, drect;

        bool isSellected = false;
};