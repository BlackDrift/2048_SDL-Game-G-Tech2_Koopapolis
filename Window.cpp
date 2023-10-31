#include "window.h"
#include <SDL.h>

Window::Window()
{
	this->height = 720;
	this->width = 1280;
	this->title = "2048 Koopapolis";
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_SHOWN);
	this->renderer = SDL_CreateRenderer(this->window, -1, 0);
	SDL_GetWindowPosition(this->window, &this->x, &this->y);
	this->running = true;
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