#include <iostream>
#include <SDL.h>
#include "window.h"
#include "Map.h"

Window::Window()
{
	this->height = 720;
	this->width = 1280;
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
	SDL_GetWindowPosition(this->window, &this->x, &this->y);
	this->running = true;
	this->content = new Map;
	this->event;
	this->fpsmax = 60.0;
}

float	Window::GetFps()
{
	this->frame_tick = SDL_GetTicks() - this->starting_tick;
	if (frame_tick > 0)
		this->fps = 1000.0f / this->frame_tick;
	else
		this->fps = 0.0f;
	return fps;
}

void	Window::Update()
{
	SDL_RenderPresent(this->renderer);
	this->ClearRender();
}

void	Window::Render()
{
	//Draw the game
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