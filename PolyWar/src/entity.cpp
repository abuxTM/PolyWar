#include "entity.h"

Entity::Entity(SDL_Rect rect)
{
    drect.x = rect.x;
    drect.y = rect.y;
    drect.w = rect.w;
    drect.h = rect.h;
}

void Entity::Render(SDL_Renderer* ren, SDL_Rect& rect)
{
    SDL_RenderDrawRect(ren, &rect);
}

bool Entity::CheckCollision(SDL_Rect a, SDL_Rect b)
{
    // The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    // Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    // Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    // If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    // If none of the sides from A are outside B
    return true;
}