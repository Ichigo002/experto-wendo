#ifndef MOD_PIX_H
#define MOD_PIX_H

#include <SDL.h>
#include <string>
#include <iostream>

/// <summary>
/// Modify singles pixels.
/// Last experiment 2/1
/// </summary>
class modify_pixel
{
public:
	modify_pixel(SDL_Event* e, SDL_Window* win, SDL_Renderer* ren);
	~modify_pixel();

	int __main();

private:
	

private:
	SDL_Event* e;
	SDL_Window* win;
	SDL_Renderer* ren;
};

#endif