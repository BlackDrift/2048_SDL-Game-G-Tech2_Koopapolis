#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "Map.h"

int	main(int argc, char** argv)
{
	srand(time(0));
	Window	window;

	window.content->SpawnTile();
	window.content->SpawnTile();
	while (window.running)
	{
		window.starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&window.event))
		{
			if (window.event.type == SDL_QUIT)
				window.running = false;

			break;
		}
		SDL_GetWindowPosition(window.window, &window.x, &window.y);
		//if ((1000 / window.fpsmax) > SDL_GetTicks() - starting_tick)
			//SDL_Delay(1000 / window.fpsmax - (SDL_GetTicks() - starting_tick));
		SDL_RenderPresent(window.renderer);
		//std::cout << window.GetFps() << std::endl;

	}
	return 0;
}
