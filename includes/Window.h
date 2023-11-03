#pragma once
#include <SDL_events.h>
#include <iostream>
#include "Map.h"

struct SDL_Window;
struct SDL_Renderer;

class Window
{
private:

	int				width;
	int				height;
	const char*		title;

public:

	int					x;
	int					y;
	bool				running;
	Map*				map;

	Uint32			starting_tick;
	Uint32			frame_tick;
	float			fps;
	float			fpsmax;

	SDL_Window*		window;
	SDL_Renderer*	renderer;
	SDL_Event		event;

	Window();
	~Window();

	void	Update();
	void	Render();
//	void	Victory();

private:

	void	ClearRender();
};
