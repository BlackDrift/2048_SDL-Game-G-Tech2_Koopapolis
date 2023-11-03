#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include "../includes/GameObject.h"

#define IMG_PATH_DEFAULT	"rsrc/default.bmp"
#define IMG_PATH_2			"rsrc/2.bmp"
#define IMG_PATH_4			"rsrc/4.bmp"
#define IMG_PATH_8			"rsrc/8.bmp"
#define IMG_PATH_16			"rsrc/16.bmp"
#define IMG_PATH_32			"rsrc/32.bmp"
#define IMG_PATH_64			"rsrc/64.bmp"
#define IMG_PATH_128		"rsrc/128.bmp"
#define IMG_PATH_256		"rsrc/256.bmp"
#define IMG_PATH_512		"rsrc/512.bmp"
#define IMG_PATH_1024		"rsrc/1024.bmp"
#define IMG_PATH_2048		"rsrc/2048.bmp"

GameObject::GameObject(SDL_Renderer* ren)
{
	this->renderer = ren;
}

SDL_Surface* GameObject::GetSurface(int value)
{
	switch (value)
	{
	case (0):
		this->surface = SDL_LoadBMP(IMG_PATH_DEFAULT);
		break;
	case (2):
		this->surface = SDL_LoadBMP(IMG_PATH_2);
		break;
	case (4):
		this->surface = SDL_LoadBMP(IMG_PATH_4);
		break;
	case (8):
		this->surface = SDL_LoadBMP(IMG_PATH_8);
		break;
	case (16):
		this->surface = SDL_LoadBMP(IMG_PATH_16);
		break;
	case (32):
		this->surface = SDL_LoadBMP(IMG_PATH_32);
		break;
	case (64):
		this->surface = SDL_LoadBMP(IMG_PATH_64);
		break;
	case (128):
		this->surface = SDL_LoadBMP(IMG_PATH_128);
		break;
	case (256):
		this->surface = SDL_LoadBMP(IMG_PATH_256);
		break;
	case (512):
		this->surface = SDL_LoadBMP(IMG_PATH_512);
		break;
	case (1024):
		this->surface = SDL_LoadBMP(IMG_PATH_1024);
		break;
	case (2048):
		this->surface = SDL_LoadBMP(IMG_PATH_2048);
		break;
	}
	if (this->surface == NULL)
	{
		std::cout << "Error SDL_LoadBMP :" << SDL_GetError();
		exit(1);
	}
	return (this->surface);
}

SDL_Texture* GameObject::GetText()
{
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_FreeSurface(this->surface);
	if (this->texture == NULL)
	{
		std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
		exit(1);
	}
	return (this->texture);
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(this->texture);
}

Tile::Tile(SDL_Renderer* renderer) : GameObject(renderer)
{
	this->value = 0;
	this->renderer = renderer;
	this->surface = this->GetSurface(this->value);
	this->objTexture = this->GetText();
}

int	Tile::GetValue()
{
	return (this->value);
}

void Tile::SetValue(int value)
{
	this->value = value;
	SDL_DestroyTexture(this->objTexture);
	this->surface = this->GetSurface(value);
	this->objTexture = this->GetText();
}

void Tile::Evolve()
{
	this->SetValue(value * 2);
}

void Tile::Reset()
{
	this->SetValue(0);
}

Tile::~Tile()
{

}
