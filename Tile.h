#pragma once
#include <iostream>

class Tile
{
public:
	//Attributes
	int	value;
	int pos;
	int x;
	int y;

	//Constructor
	Tile();

	//Method
	int GetNumber();
	void Evolve();
	void Reset();


	//Destructor
	~Tile();
};

