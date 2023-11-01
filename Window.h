#pragma once
#include <SDL_events.h>
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

	int				x;
	int				y;
	bool			running;
	Map*			content;

	Uint32			starting_tick;
	Uint32			frame_tick;
	float			fps;
	float			fpsmax;

	SDL_Window*		window;
	SDL_Renderer*	renderer;
	SDL_Event		event;

	Window();
	~Window();

	float	GetFps();
	void	Update();

private:

	void	ClearRender();
	void	Render();
};