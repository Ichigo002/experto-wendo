#ifndef DYNAMIC_TEXT_TEST_H
#define DYNAMIC_TEXT_TEST_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

/// <summary>
/// NOT WORK
/// Last experiment 1/3
/// </summary>
class dynamic_text
{
private:

	TTF_Font* sans;
	SDL_Texture* tex;
	SDL_Surface* surf;
	SDL_Color color = { 252, 100, 0 };
	SDL_Rect dest;
	int n = 0;

public:
	dynamic_text(SDL_Event* e, SDL_Window* win, SDL_Renderer* ren)
	{
		this->e = e;
		this->win = win;
		this->ren = ren;

		TTF_Init();
		sans = TTF_OpenFont("trials/Dynamic Text Rendering/font.ttf", 32);



		tex = SDL_CreateTextureFromSurface(ren, surf);
	}

	~dynamic_text()
	{
		TTF_CloseFont(sans);
		TTF_Quit();
	}

	int main()
	{
		//surf = TTF_RenderText_Solid(sans, (std::to_string(n) + "frames").c_str(), color);
		//tex = SDL_CreateTextureFromSurface(ren, surf);
		//SDL_FreeSurface(surf);

		//SDL_QueryTexture(tex, nullptr, nullptr, &dest.w, &dest.h);
		
		SDL_RenderCopy(ren, tex, NULL, &dest);

		//n++;
		return 0;
	}

private:
	SDL_Event* e;
	SDL_Window* win;
	SDL_Renderer* ren;
};

#endif