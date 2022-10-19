#ifndef MOD_PIX_H
#define MOD_PIX_H

#include <SDL.h>
#include <SDL_image.h>
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
	bool loadMedia();

	/// <summary>
	/// Load pixels to buffor from file
	/// </summary>
	bool loadPixelsFromFile(std::string path);

	/// <summary>
	/// Loads texture from surface
	/// </summary>
	/// <returns></returns>
	bool loadFromPixels();

	bool loadFromFile(std::string path);

	Uint32* getPixels32();

	Uint32 getPitch32();

private:
	SDL_Event* e;
	SDL_Window* win;
	SDL_Renderer* ren;

	SDL_Rect destR;
	SDL_Texture* mTexture;
	SDL_Surface* mSurfacePixels;
	int mWidth, mHeight;
};

#endif