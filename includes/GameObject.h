#pragma once
#include "SDL_Rect.h"
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Surface;

class GameObject {

public:

	SDL_Renderer*	renderer;
	SDL_Surface*	surface;
	SDL_Texture*	texture;
	SDL_Rect		tRect;

	GameObject(SDL_Renderer* ren);


	~GameObject();

	SDL_Surface*	GetSurface(int value);
	SDL_Texture*	GetText();
};

class Tile : GameObject
{
private:
	int				value;
public:
	//Attributes
	int				pos;
	int				x;
	int				y;
	SDL_Texture*	objTexture;
	SDL_Rect		tRect;
	SDL_Renderer*	renderer;

	//Constructor
	Tile(SDL_Renderer* renderer);

	//Method
	void			Evolve();
	void			Reset();
	void			Swap(Tile* tile);
	int				GetValue();
	void			SetValue(int value);


	//Destructor
	~Tile();
};
