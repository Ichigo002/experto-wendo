#include <iostream>
#include <SDL.h>

#include "trials/Dynamic Text Rendering/dynamic_txt_test.h"

#define WIN_W 600
#define WIN_H 400
#define WIN_X SDL_WINDOWPOS_CENTERED
#define WIN_Y SDL_WINDOWPOS_CENTERED

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    Uint32 flags = SDL_WINDOW_SHOWN;
    
    SDL_Window* win = SDL_CreateWindow("Fred's experiments", WIN_X, WIN_Y, WIN_W, WIN_H, flags);
    SDL_Event eve;
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    if (win == nullptr || ren == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
    }

    bool running = true;
    int r = 0;

    dynamic_text trial;

    while (running)
    {
        SDL_PollEvent(&eve);

        //Call Trail:

        r = trial.main(&eve, win, ren);

        //END CALL

        if (eve.type == SDL_QUIT)
            running = false;
    }

    return r;
}
