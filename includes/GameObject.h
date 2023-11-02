#pragma once
#include "SDL_Rect.h"
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Surface;

class GameObject {

public:

	SDL_Renderer*	renderer;
	SDL_Surface*	surface;

	GameObject(SDL_Renderer* ren);


	~GameObject();

	SDL_Surface*	GetSurface(int value);
	SDL_Texture*	GetText();

private:
	SDL_Texture*		texture;
};

class Tile : GameObject
{
public:
	//Attributes
	int				value;
	int				pos;
	int				x;
	int				y;
	SDL_Texture*	objTexture;
	SDL_Rect		tRect;
	SDL_Renderer*	renderer;

	//Constructor
	Tile(SDL_Renderer* renderer);

	//Method
	int				GetNumber();
	void			Evolve();
	void			Reset();
	void			Swap(Tile* tile);


	//Destructor
	~Tile();
};
