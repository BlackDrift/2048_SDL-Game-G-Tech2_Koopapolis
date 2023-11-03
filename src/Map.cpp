#include <iostream>
#include "../includes/Map.h"
#include "../includes/GameObject.h"



Map::Map(SDL_Renderer* renderer)
{
	int position = 0;

	this->SetSize();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			Tile* tile = new Tile(renderer);
			tile->x = i + 1;
			tile->y = j + 1;
			tile->pos = position;
			this->mContent.push_back(tile);
			position += 1;
		}
	}
	for (int k = 0; k < 2; k++)
		this->SpawnTile();
}

void	Map::SetSize()
{
	this->size = 4;
	this->squareSize = (this->size * this->size);
}

int Map::GetNumber()
{
	int value = (rand() % 2 + 1) * 2;
	return value;
}

void	Map::SpawnTile()
{
	int pos = rand() % this->squareSize;
	while (this->mContent.at(pos)->GetValue() != 0)
		pos = rand() % this->squareSize;
	this->mContent.at((pos))->SetValue(GetNumber());
}

// Get tile at (x, y) coords

Tile*	Map::TileAt(int x, int y)
{
	return (this->mContent.at(4 * x + y));
}

//CheckIsDone checks CanMove and CanEvolve in all the directions but first checks if there is no empty tile.

bool	Map::CheckIsDone()
{
	for (int i = 0; i < this->squareSize; ++i)
	{
		if (this->mContent.at(i)->GetValue() == 0)
			return false;
		else if (this->mContent.at(i)->GetValue() == 2048 && !this->isWon)
		{
			this->isWon = true;
			return (true);
		}
	}
	for (int i = 0; i < this->squareSize; ++i)
	{
		if (this->CanMove('0', this->mContent.at(i)))
			return false;
		if (this->CanEvolve('0', this->mContent.at(i)))
			return false;
	}
	this->isLost = true;
	return true;
}

//MoveTiles calls the other move functions but for every single tile of the tab

void Map::MoveTiles(char direction)
{
	switch (direction)
	{
	case ('u'):
		for (int i = 0; i < this->squareSize; ++i)
			this->MoveUp(this->mContent.at(i));
		break;

	case ('d'):
		for (int i = this->squareSize - 1; i >= 0; --i)
			this->MoveDown(this->mContent.at(i));
		break;

	case ('l'):
		for (int i = 0; i < this->size; ++i)
			for (int j = 0; j < this->size; j++)
				this->MoveLeft(this->mContent.at(i + (this->size * j)));
		break;

	case ('r'):
		for (int i = this->size - 1; i >= 0; --i)
			for (int j = this->size - 1; j >= 0; --j)
				this->MoveRight(this->mContent.at(i + (this->size * j)));
		break;
	default:
		break;
	}
	this->SpawnTile();
}

bool Map::CanEvolve(char direction, Tile *tile)
{
	int tileX = tile->x;
	int tileY = tile->y;

	switch (direction)
	{
	case('u'):
		if (tile->x > 1 && tile->GetValue() == this->TileAt(tileX - 2, tileY - 1)->GetValue() && tile->GetValue() != 0)
			return true;
		break;
	case('d'):
		if (tile->x < 4 && tile->GetValue() == this->TileAt(tileX, tileY - 1)->GetValue() && tile->GetValue() != 0)
			return true;
		break;
	case('l'):
		if (tile->y > 1 && tile->GetValue() == this->TileAt(tileX - 1, tileY - 2)->GetValue() && tile->GetValue() != 0)
			return true;
		break;
	case('r'):
		if (tile->y < 4 && tile->GetValue() == this->TileAt(tileX - 1, tileY)->GetValue() && tile->GetValue() != 0)
			return true;
		break;
// case ('0') is used for CheckIsDone and does all the cases together
	case('0'):
		if (tile->x > 1 && tile->GetValue() == this->TileAt(tileX - 2, tileY - 1)->GetValue() && tile->GetValue() != 0)
			return true;
		else if (tile->x < 4 && tile->GetValue() == this->TileAt(tileX, tileY - 1)->GetValue() && tile->GetValue() != 0)
			return true;
		else if (tile->y > 1 && tile->GetValue() == this->TileAt(tileX - 1, tileY - 2)->GetValue() && tile->GetValue() != 0)
			return true;
		else if (tile->y < 4 && tile->GetValue() == this->TileAt(tileX - 1, tileY)->GetValue() && tile->GetValue() != 0)
			return true;
		else
			return false;
	default:
		break;
	}
	return false;
}

bool Map::CanMove(char direction, Tile *tile)
{
	int	tileX = tile->x;
	int tileY = tile->y;
	int position = tile->pos;

	switch (direction)
	{

	case('u'):
		if (tile->GetValue() != 0 && tile->x > 1 && TileAt(tileX - 2, tileY - 1)->GetValue() == 0)
			return true;
		break;
	case ('d'):
		if (tile->GetValue() != 0 && tile->x < 4 && TileAt(tileX, tileY - 1)->GetValue() == 0)
			return true;
		break;
	case ('l'):
		if (tile->GetValue() != 0 && tile->y > 1 && TileAt(tileX - 1, tileY - 2)->GetValue() == 0)
			return true;
		break;
	case ('r'):
		if (tile->GetValue() != 0 && tile->y < 4 && TileAt(tileX - 1, tileY)->GetValue() == 0)
			return true;
		break;
	case('0'):
// case ('0') is used for CheckIsDone and does all the cases together
		if (tile->GetValue() != 0 && tile->x > 1 && TileAt(tileX - 2, tileY - 1)->GetValue() == 0)
			return true;
		else if (tile->GetValue() != 0 && tile->x < 4 && TileAt(tileX, tileY - 1)->GetValue() == 0)
			return true;
		else if (tile->GetValue() != 0 && tile->y > 1 && TileAt(tileX - 1, tileY - 2)->GetValue() == 0)
			return true;
		else if (tile->GetValue() != 0 && tile->y < 4 && TileAt(tileX - 1, tileY)->GetValue() == 0)
			return true;
		else
			return false;
	}
	return false;
}

void Map::Swap(char direction, Tile *tile)
{
	switch (direction)
	{
	case('u'):
		this->mContent.at(tile->pos - 4)->SetValue(tile->GetValue());
		this->mContent.at(tile->pos)->Reset();
		break;
	case('d'):
		this->mContent.at(tile->pos + 4)->SetValue(tile->GetValue());
		this->mContent.at(tile->pos)->Reset();
		break;
	case('l'):
		this->mContent.at(tile->pos - 1)->SetValue(tile->GetValue());
		this->mContent.at(tile->pos)->Reset();
		break;
	case('r'):
		this->mContent.at(tile->pos + 1)->SetValue(tile->GetValue());
		this->mContent.at(tile->pos)->Reset();
		break;
	}
}


// Move in direction functions


void Map::MoveUp(Tile* tile)
{
	bool	hasEvolved = false;
	for (int i = 0; i < tile->x + 1; ++i)
	{
		if (CanEvolve('u', tile) && !hasEvolved)
		{
			this->mContent.at(tile->pos - 4)->Evolve();
			this->mContent.at(tile->pos)->Reset();
			hasEvolved = true;
		}
		else if (CanMove('u', tile))
		{
			this->Swap('u', tile);
			tile = this->mContent.at(tile->pos - 4);
		}
		else
			i = tile->x;
	}
}

void Map::MoveDown(Tile* tile)
{
	bool	hasEvolved = false;
	for (int i = tile->x + 1; i >= 0; --i)
	{
		if (CanEvolve('d', tile) && !hasEvolved)
		{
			this->mContent.at(tile->pos + 4)->Evolve();
			this->mContent.at(tile->pos)->Reset();
			hasEvolved = true;
		}
		else if (CanMove('d', tile))
		{
			this->Swap('d', tile);
			tile = this->mContent.at(tile->pos + 4);
		}
		else
			i = 0;
	}
}

void Map::MoveLeft(Tile* tile)
{
	bool	hasEvolved = false;
	for (int i = 0; i < tile->y + 1; ++i)
	{
		if (CanEvolve('l', tile) && !hasEvolved)
		{
			this->mContent.at(tile->pos - 1)->Evolve();
			this->mContent.at(tile->pos)->Reset();
			hasEvolved = true;
		}
		else if (CanMove('l', tile))
		{
			this->Swap('l', tile);
			tile = this->mContent.at(tile->pos - 1);
		}
		else
			i = tile->y;
	}
}

void Map::MoveRight(Tile* tile)
{
	bool	hasEvolved = false;
	for (int i = tile->y + 1; i >= 0; --i)
	{
		if (CanEvolve('r', tile) && !hasEvolved)
		{
			this->mContent.at(tile->pos + 1)->Evolve();
			this->mContent.at(tile->pos)->Reset();
			hasEvolved = true;
		}
		else if (CanMove('r', tile))
		{
			this->Swap('r', tile);
			tile = this->mContent.at(tile->pos + 1);
		}
		else
			i = 0;
	}
}
