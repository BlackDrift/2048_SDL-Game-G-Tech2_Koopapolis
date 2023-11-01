#include "TextureManager.h"
#include <SDL.h>


void TextureManager::f()
{
	std::cout, "Texture manager is linked wtf ?", std::endl;
}

/*SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}*/