#pragma once

struct SDL_Renderer;

#include <vector>
#include "GameObject.h"

class Map
{
public:

	//Attributes
	int					size;
	int					squareSize;
	bool				isWon;
	bool				isLost;
	std::vector<Tile*>	mContent;

	//Constructor
	Map(SDL_Renderer* renderer);

	//Method
	void				SetSize();
	void				SpawnTile();
	int					GetNumber();
	bool				CanMove(char direction, Tile *tile);
	bool				CheckIsDone();
	Tile*				TileAt(int x, int y);
	void				MoveTiles(char direction);
	bool				CanEvolve(char direction, Tile *tile);
	void				Swap(char direction, Tile *tile);
	void				MoveUp(Tile *tile);
	void				MoveDown(Tile *tile);
	void				MoveLeft(Tile *tile);
	void				MoveRight(Tile *tile);

	//Destructor
};
