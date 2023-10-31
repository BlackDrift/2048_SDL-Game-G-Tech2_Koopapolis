#pragma once
#include <SDL_events.h>

struct SDL_Window;
struct SDL_Renderer;

class Window
{
public:

	//Attributes
	int				width;
	int				height;
	int				x;
	int				y;


	Uint32			starting_tick;
	Uint32			frame_tick;
	float			fps;
	float			fpsmax;


	bool			running;
	const char*		title;
	SDL_Window*		window;
	SDL_Renderer*	renderer;


	SDL_Event		event;


	//Constructor
	Window();

	//Method
	float GetFps();

	//Destuctor
};