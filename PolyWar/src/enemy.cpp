#include "enemy.h"
#include <cmath>

Entity* enemyEntity = nullptr;

Enemy::Enemy(float x, float y, int w, int h)
{
    enemyEntity = new Entity(rect);

    enemyEntity->getPos().x = xPos = rect.x = x;
    enemyEntity->getPos().y = yPos = rect.y = y;
    rect.w = w;
    rect.h = h;

    enemyEntity->getPos().print();
}

void Enemy::Update(SDL_Rect playerRect)
{
    float dirx = playerRect.x - rect.x;
    float diry = playerRect.y - rect.y;

    float hyp = sqrt(dirx*dirx + diry*diry);

    dirx /= hyp;
    diry /= hyp;

    if (!enemyEntity->CheckCollision(rect, playerRect)) enemyEntity->getPos().x = rect.x = xPos += dirx * speed;
    if (!enemyEntity->CheckCollision(rect, playerRect)) enemyEntity->getPos().x = rect.y = yPos += diry * speed;
}

void Enemy::Render(SDL_Renderer* ren)
{
    SDL_SetRenderDrawColor(ren, 238, 0, 0, 1);
    enemyEntity->Render(ren, rect);
}