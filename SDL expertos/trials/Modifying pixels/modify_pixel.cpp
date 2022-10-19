#include "modify_pixel.h"

modify_pixel::modify_pixel(SDL_Event* e, SDL_Window* win, SDL_Renderer* ren)
{
	this->e = e;
	this->win = win;
	this->ren = ren;
}

modify_pixel::~modify_pixel()
{

}

int modify_pixel::__main()
{
	return 0;
}