#pragma once

#include <SDL2/SDL.h>
#include "entity.h"

class Player
{
    public:
        Player(float x, float y, int w, int h);

        void Update(SDL_Rect enemyRect);
        void Render(SDL_Renderer* ren);
        void Inputs(SDL_Event e);

        SDL_Rect GetRect() { return rect; }

        bool isDead;

    private:
        SDL_Rect rect;

        float speed = 0.05f;

        float xPos, yPos;
        float xVel, yVel;
};