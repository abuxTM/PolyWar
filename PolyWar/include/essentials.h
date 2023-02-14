#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Essentials
{
    public:
        Essentials() { }

        void CreateFont(SDL_Renderer* ren, SDL_Rect rect, const char* text, int size)
        {
            // Create font
            TTF_Font* f = TTF_OpenFont("assets/fonts/font.ttf", size);
            SDL_Surface* surfaceText = TTF_RenderText_Solid(f, text, { 238, 238, 238 });
            SDL_Texture* textureText = SDL_CreateTextureFromSurface(ren, surfaceText);
            SDL_FreeSurface(surfaceText);

            SDL_RenderCopy(ren, textureText, NULL, &rect);
        }
};