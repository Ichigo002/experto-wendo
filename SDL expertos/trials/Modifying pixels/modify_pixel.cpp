#include "modify_pixel.h"
#include <iostream>

modify_pixel::modify_pixel(SDL_Event* e, SDL_Window* win, SDL_Renderer* ren)
{
	this->e = e;
	this->win = win;
	this->ren = ren;

	loadMedia();
	destR = { 100, 100, 220, 191 };
}

modify_pixel::~modify_pixel()
{
	
}

int modify_pixel::__main()
{
	SDL_RenderCopy(ren, mTexture, NULL, &destR);
	return 0;
}

bool modify_pixel::loadMedia()
{
	if (!loadPixelsFromFile("trials/Modifying pixels/pix.png"))
	{
		printf("Unable to load Foo' texture!\n");
		return false;
	}
	Uint32* pixels = getPixels32();
	int pixelCount = getPitch32() * mHeight;

	Uint32 colorKey = SDL_MapRGB(SDL_GetWindowSurface(win)->format, 255, 255, 255);
	Uint32 transparent = SDL_MapRGBA(SDL_GetWindowSurface(win)->format, 0, 255, 0, 0);

	//Color key pixels
	//for (int i = 0; i < pixelCount; ++i)
	//{
	//	if (pixels[i] == colorKey)
	//	{
	//		pixels[i] = transparent;
	//	}
	//}

	pixels[120] = transparent;
	pixels[121] = transparent;
	pixels[122] = transparent;
	pixels[123] = transparent;
	pixels[124] = transparent;
	pixels[120 + mWidth] = transparent;
	pixels[121 + mWidth] = transparent;
	pixels[122 + mWidth] = transparent;
	pixels[123 + mWidth] = transparent;
	pixels[124 + mWidth] = transparent;
	std::cout << pixelCount;

	//Create texture from manually color keyed pixels
	if (!loadFromPixels())
	{
		printf("Unable to load Foo' texture from surface!\n");
		return false;
	}

	return true;
}

bool modify_pixel::loadPixelsFromFile(std::string path)
{
	// Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		return false;
	}

	//Convert surface to display format
	mSurfacePixels = SDL_ConvertSurfaceFormat(loadedSurface, SDL_GetWindowPixelFormat(win), 0);

	if (mSurfacePixels == NULL)
	{
		printf("Unable to convert loaded surface to display format! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	//Get image dimensions
	mWidth = mSurfacePixels->w;
	mHeight = mSurfacePixels->h;

	SDL_FreeSurface(loadedSurface);

	return true;
}

bool modify_pixel::loadFromPixels()
{
	//Only load if pixels exist
	if (mSurfacePixels == NULL)
	{
		printf("No pixels loaded!");
		return false;
	}

	//set what color is transparent
	SDL_SetColorKey(mSurfacePixels, SDL_TRUE, SDL_MapRGB(mSurfacePixels->format, 0, 0xFF, 0xFF));

	//Create texture from surface pixels
	mTexture = SDL_CreateTextureFromSurface(ren, mSurfacePixels);
	if (mTexture == NULL)
	{
		printf("Unable to create texture from loaded pixels! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Get image dimensions
	mWidth = mSurfacePixels->w;
	mHeight = mSurfacePixels->h;

	//Get rid of old loaded surface
	SDL_FreeSurface(mSurfacePixels);

	return true;
}

bool modify_pixel::loadFromFile(std::string path)
{
	//Load pixels
	if (!loadPixelsFromFile(path))
	{
		printf("Failed to load pixels for %s!\n", path.c_str());
	}
	else
	{
		//Load texture from pixels
		if (!loadFromPixels())
		{
			printf("Failed to texture from pixels from %s!\n", path.c_str());
		}
	}
	//Return success
	return mTexture != NULL;

}

Uint32* modify_pixel::getPixels32()
{
	Uint32* pixels = NULL;

	if (mSurfacePixels != NULL)
	{
		pixels = static_cast<Uint32*>(mSurfacePixels->pixels);
	}

	return pixels;
}

Uint32 modify_pixel::getPitch32()
{
	Uint32 pitch = 0;

	if (mSurfacePixels != NULL)
	{
		pitch = mSurfacePixels->pitch / 4;
	}

	return pitch;
}