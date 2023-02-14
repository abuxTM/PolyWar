#include "engine.h"
#include "essentials.h"
#include "mouse.h"
#include "button.h"
#include "player.h"
#include "enemy.h"

struct SceneManager
{
    bool MainMenu = true;
    bool MapOne = false;
}SceneManager;

Essentials* essentials = nullptr;
Mouse* mouse = nullptr;
Button* button = nullptr;
Player* player = nullptr;
Enemy* enemy = nullptr;

Engine::Engine(const char* title, int w, int h)
{
    // Initialize sdl libulary
    SDL_Init(SDL_INIT_VIDEO);
    // Initialize sdl font libulary
    TTF_Init();

    // Create window to display graphics
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);

    // Create renderer to create & display graphics
    renderer = SDL_CreateRenderer(window, -1, 0);

    essentials = new Essentials();
    mouse = new Mouse();
    button = new Button(renderer);

    button->srect.y = 0;
    button->drect.x = 1280/2 - button->drect.w/2;
    button->drect.y = 200;

    player = new Player(1280/2 - 25/2, 720/2 - 25/2, 25, 25);
    enemy = new Enemy(0, 0, 25, 25);
}

void Engine::Update()
{
    mouse->Update();

    // Draw mainmenu
    if (SceneManager.MainMenu)
    {
        button->Update(*mouse);
    }
    
    // On load map update players and enemys position
    if (SceneManager.MapOne == true) { player->Update(enemy->GetRect()); enemy->Update(player->GetRect()); }

    // If player is dead then reset map
    if (player->isDead == true && SceneManager.MapOne == true) SceneManager.MapOne = false;
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(renderer, 38, 38, 38, 1);

    SDL_RenderClear(renderer);

    // Draw mainmenu
    if (SceneManager.MainMenu)
    {
        button->Render(renderer);
    }

    if (SceneManager.MapOne == true)
    {
        SDL_Rect font;
        font.w = 130;
        font.h = 30;
        font.x = 1280/2 - font.w/2;
        font.y = 40;
        
        // Display wave
        essentials->CreateFont(renderer, font, "Wave: 0", 16);

        player->Render(renderer);
        enemy->Render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Engine::Inputs()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        // Check if user wonts to quit from game
        if (e.type == SDL_QUIT) isRunning = false;

        if (SceneManager.MainMenu == true)
        {
            switch (e.type)
            {
            case SDL_MOUSEBUTTONUP:
                if (e.button.button == SDL_BUTTON_LEFT) { if (button->isSellected) { SceneManager.MainMenu = false; SceneManager.MapOne = true; } }
                break;
            
            default:
                break;
            }
        }

        if (SceneManager.MapOne == true)
        {
            // Player inputs
            player->Inputs(e);
        }
    }
}

void Engine::CleanUp()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}