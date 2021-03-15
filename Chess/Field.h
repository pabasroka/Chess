#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include <tuple>

class Field
{
	char x;
	int y;
	bool isTaken;

public:
	Field();
	Field(char x, int y, bool isTaken = false);
	virtual ~Field();

	std::tuple<char, int> fieldPositon(sf::RenderWindow& target);
	sf::Vector2i newPosition(sf::Vector2i pos);

	char getPosXChar();
	char getPosX();
	int getPosY();
	bool getIsFieldTaken();
};

