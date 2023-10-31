#include "GameObject.h"
//#include "TextureManager.h"


GameObject::GameObject(const char* texturesheet, SDL_Renderer ren)
{
	renderer = ren;
	//objTexture = TexttureManager::LoadTexture(texturesheet, ren);


}

void GameObject::Update()
{
	xpos = 0;
	ypos = 0;

	//srcRect.h = ...;
	//srcRect.w = ...;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}