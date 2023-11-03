#include <iostream>
#include <SDL.h>
#include <vector>
#include "../includes/Window.h"
#include "../includes/Map.h"

#define VICTORY_SCREEN_PATH "rsrc/victory.bmp"

Window::Window()
{
	this->height = 900;
	this->width = 900;
	this->title = "2048 Koopapolis";
	int	iError = SDL_Init(SDL_INIT_VIDEO);
	if (iError != 0)
	{
		std::cout << "Error SDL_Init :" << SDL_GetError() << std::endl;
		exit(1);
	}
	this->window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_SHOWN);
	if (this->window == NULL)
	{
		std::cout << "Erreur SDL_CreateWindow :" << SDL_GetError() << std::endl;
		exit(1);
	}
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (this->renderer == NULL)
	{
		std::cout << "Erreur SDL_CreateRenderer :" << SDL_GetError() << std::endl;
		exit(1);
	}
	this->running = true;
	this->map = new Map(this->renderer);
	this->event;
	this->fpsmax = 60.0;
}

void	Window::Update()
{
	this->ClearRender();
	this->Render();
	SDL_RenderPresent(this->renderer);
}
/*
void	Window::Victory()
{
	GameObject* victoryscreen = new GameObject(this->renderer);
	victoryscreen->surface = SDL_LoadBMP(VICTORY_SCREEN_PATH);
	victoryscreen->texture
	this->ClearRender();
	SDL_RenderCopy(this->renderer, this->, NULL, &this->map->mContent.at(i)->tRect);
}
*/
void	Window::Render()
{
	for (int i = 0; i < this->map->squareSize; ++i)
	{
		this->map->mContent.at(i)->tRect.w = 225;
		this->map->mContent.at(i)->tRect.h = 225;
		this->map->mContent.at(i)->tRect.x = 225 * (this->map->mContent.at(i)->y - 1);
		this->map->mContent.at(i)->tRect.y = 225 * (this->map->mContent.at(i)->x - 1);
		SDL_RenderCopy(this->renderer, this->map->mContent.at(i)->objTexture, NULL, &this->map->mContent.at(i)->tRect);
	}
}

void	Window::ClearRender()
{
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->renderer);
}

Window::~Window()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}
