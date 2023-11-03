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
	window.map->isWon = false;

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
			Sleep(100);
			break;
		}
		window.Update();
		if ((1000 / window.fpsmax) > SDL_GetTicks() - window.starting_tick)
			SDL_Delay(1000 / window.fpsmax - (SDL_GetTicks() - window.starting_tick));
	}
	//if (window.map->isWon)
		//window.Victory();
	return 0;
}
