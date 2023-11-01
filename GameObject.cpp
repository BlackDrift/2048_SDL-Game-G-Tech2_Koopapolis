#include "GameObject.h"
#include "TextureManager.h"
#include <SDL.h>

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren)
{
	renderer = ren;
	//objTexture = TextureManager::LoadTexture(texturesheet, ren);
	//TextureManager a();
	//a.f();

}

void GameObject::Update()
{
	xpos = 0;
	ypos = 0;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
}

void GameObject::Render()
{
	//SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}