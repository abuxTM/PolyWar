#pragma once

#include <SDL2/SDL.h>
#include "math.h"

class Entity
{
    public:
        Entity(SDL_Rect rect);

        void Render(SDL_Renderer* ren, SDL_Rect& rect);

        bool CheckCollision(SDL_Rect a, SDL_Rect b);

        Vector2f& getPos() { return pos; }

    private:
        Vector2f pos;
        SDL_Rect drect;
};