#pragma once

#include <SDL2/SDL.h>
#include "entity.h"

class Enemy
{
    public:
        Enemy(float x, float y, int w, int h);

        void Update(SDL_Rect playerRect);
        void Render(SDL_Renderer* ren);

        SDL_Rect GetRect() { return rect; }

    private:
        SDL_Rect rect;

        float speed = 0.03f;

        float xPos, yPos;
        float xVel, yVel;
};