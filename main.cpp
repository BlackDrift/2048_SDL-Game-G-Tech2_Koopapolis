#include <iostream>
#include <SDL.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <sdl_mixer.h>
#include "includes/Window.h"
#include "includes/Map.h"
#include "includes/Game.h"

int	main(int argc, char** argv)
{
	srand((unsigned int)time(0));;
	Window	window;
	window.map->isWon = false;
	int init = Mix_Init(0);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	Mix_Chunk* music = Mix_LoadWAV("rsrc/music.wav");
	if (!music)
	{
		std::cout << "Music Error: " << Mix_GetError() << std::endl;
	}
	Mix_PlayChannel(-1, music ,-1);
	while (window.running)
	{
		window.starting_tick = SDL_GetTicks();
		while (SDL_PollEvent(&window.event))
		{
			if (window.event.type == SDL_QUIT)
				window.running = false;
			if (window.event.type == SDL_KEYDOWN)
				if (game::GameEvent(window.event.key.keysym.sym, window.map) == 1)
					window.running = false;
			if (window.map->CheckIsDone())
				window.running = false;
			break;
		}
		window.Update();
		if ((1000 / window.fpsmax) > SDL_GetTicks() - window.starting_tick)
			SDL_Delay(1000 / window.fpsmax - (SDL_GetTicks() - window.starting_tick));
	}
	if (window.map->isWon)
		window.Victory();
	else if (window.map->isLost)
		window.Lost();
	return 0;
}
