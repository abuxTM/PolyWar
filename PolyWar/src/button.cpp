#include "button.h"

Button::Button(SDL_Renderer* ren)
{
    static SDL_Texture * t = IMG_LoadTexture(ren, "assets/mainmenu/1.png");
    tex = t;

    srect.x = 0;
    srect.w = 400;
    srect.h = 100;

    drect.w = 300;
    drect.h = 75;
}

void Button::Update(Mouse& mouse)
{
    if (SDL_HasIntersection(&drect, &mouse.point))
    {
        isSellected = true;
        srect.x = 400;
    }
    else
    {
        isSellected = false;
        srect.x = 0;
    }
}

void Button::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, tex, &srect, &drect);
}