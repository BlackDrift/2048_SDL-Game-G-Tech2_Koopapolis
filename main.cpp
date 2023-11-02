#include <iostream>
#include <SDL.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "includes/Window.h"
#include "includes/Map.h"
#include "includes/Game.h"

int	main(int argc, char** argv)
{
	srand((unsigned int)time(0));;
	Window	window;

	while (window.running)
	{
		window.starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&window.event))
		{
			if (window.event.type == SDL_QUIT)
				window.running = false;
			if (window.event.type == SDL_KEYDOWN)
			{
				if (game::GameEvent(window.event.key.keysym.sym, window.map) == 1)
					window.running = false;
			}
			if (window.map->CheckIsDone())
			{
				std::cout << std::endl << std::endl << "Game Over" << std::endl;
				window.running = false;
			}
			window.Update();
			Sleep(100);
			break;
		}
		//std::cout << window.map->mContent.at(3).value << std::endl;
		//SDL_GetWindowPosition(window.window, &window.x, &window.y);
		//if ((1000 / window.fpsmax) > SDL_GetTicks() - window.starting_tick)
			//SDL_Delay(1000 / window.fpsmax - (SDL_GetTicks() - window.starting_tick));
		//SDL_RenderPresent(window.renderer);
		//std::cout << window.GetFps() << std::endl;

	}
	return 0;
}
