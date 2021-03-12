#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Field
{
	char x;
	int y;
	bool isTaken;

public:
	char getPosX();
	int getPosY();
	bool getIsFieldTaken();

	Field(char x, int y, bool isTaken = false);
	virtual ~Field();
};

