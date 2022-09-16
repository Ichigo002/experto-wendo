#ifndef DYNAMIC_TEXT_TEST_H
#define DYNAMIC_TEXT_TEST_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

class dynamic_text
{
private:

	TTF_Font* sans;
	SDL_Texture* tex;
	SDL_Surface* surf;

public:
	dynamic_text()
	{
		TTF_Init();
		sans = TTF_OpenFont("trials/Dynamic Text Rendering/font.ttf", 32);
	}

	~dynamic_text()
	{
		TTF_CloseFont(sans);
		TTF_Quit();
	}

	int main(SDL_Event* e, SDL_Window* win, SDL_Renderer* ren)
	{


		return 0;
	}
};

#endif