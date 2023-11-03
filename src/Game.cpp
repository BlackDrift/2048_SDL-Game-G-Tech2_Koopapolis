#include <SDL.h>
#include "../includes/Map.h"
#include "../includes/Game.h"

#define KEY_UP SDLK_UP
#define KEY_DOWN SDLK_DOWN
#define KEY_LEFT SDLK_LEFT
#define KEY_RIGHT SDLK_RIGHT
#define KEY_ESC SDLK_ESCAPE

int	game::GameEvent(int	key, Map *map)
{
	switch (key)
		{
			case (KEY_UP):
				map->MoveTiles('u');
				return 0;
				break;
			case (KEY_DOWN):
				map->MoveTiles('d');
				return 0;
				break;
			case (KEY_LEFT):
				map->MoveTiles('l');
				return 0;
				break;
			case (KEY_RIGHT):
				map->MoveTiles('r');
				return 0;
				break;
			case (KEY_ESC):
				return 1;
			default:
				return 0;
				break;
		}
	return (0);
}
