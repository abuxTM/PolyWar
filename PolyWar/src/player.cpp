#include "player.h"

Entity* playerEntity = nullptr;

Player::Player(float x, float y, int w, int h)
{
    playerEntity = new Entity(rect);

    playerEntity->getPos().x = xPos = rect.x = x;
    playerEntity->getPos().y = yPos = rect.y = y;
    rect.w = w;
    rect.h = h;

    playerEntity->getPos().print();
}

void Player::Update(SDL_Rect enemyRect)
{
    playerEntity->getPos().x = rect.x = xPos += xVel;
    playerEntity->getPos().x = rect.y = yPos += yVel;

    if (playerEntity->CheckCollision(rect, enemyRect)) isDead = true;
}

void Player::Render(SDL_Renderer* ren)
{
    SDL_SetRenderDrawColor(ren, 238, 238, 238, 1);
    playerEntity->Render(ren, rect);
}

void Player::Inputs(SDL_Event e)
{
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_w: yVel -= speed; break;
            case SDLK_s: yVel += speed; break;
            case SDLK_a: xVel -= speed; break;
            case SDLK_d: xVel += speed; break;
        }
    }
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_w: yVel += speed; break;
            case SDLK_s: yVel -= speed; break;
            case SDLK_a: xVel += speed; break;
            case SDLK_d: xVel -= speed; break;
        }
    }
}