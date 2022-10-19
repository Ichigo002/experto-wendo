#include <iostream>
#include <SDL.h>

#include "trials/Dynamic Text Rendering/dynamic_txt_test.h"
#include "trials/Modifying pixels/modify_pixel.h"

#define WIN_W 600
#define WIN_H 400
#define WIN_X SDL_WINDOWPOS_CENTERED
#define WIN_Y SDL_WINDOWPOS_CENTERED

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cout << SDL_GetError() << std::endl;

    Uint32 flags = SDL_WINDOW_SHOWN;
    
    SDL_Window* win = SDL_CreateWindow("Fred's experiments", WIN_X, WIN_Y, WIN_W, WIN_H, flags);
    SDL_Event eve;
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);

    if (win == nullptr || ren == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
    }

    bool running = true;

    //dynamic_text trial(&eve, win, ren);
    modify_pixel trial(&eve, win, ren);

    while (running)
    {
        SDL_RenderClear(ren);
        SDL_PollEvent(&eve);

        //Call Trail:

        trial.__main();

        //END CALL

        if (eve.type == SDL_QUIT)
            running = false;
        SDL_RenderPresent(ren);
    }

    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    return 0;
}
