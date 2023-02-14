#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Mouse
{
    public:
        SDL_Texture * tex;
        SDL_Rect rect;
        SDL_Rect point;
        
        Mouse()
        {
            rect.w = 25;
            rect.h = 25;
            point.w = 1;
            point.h = 1;
        }
        
        void Update()
        {
            SDL_GetMouseState(&rect.x, &rect.y);
            point.x = rect.x;
            point.y = rect.y;
        }
};
