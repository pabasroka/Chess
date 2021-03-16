#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include <tuple>

class Field
{
	char x;
	int y;
	bool isTaken;
	int id;

public:
	Field();
	Field(int id, char x, int y, bool isTaken);
	virtual ~Field();

	std::tuple<char, int> fieldPositon(sf::RenderWindow& target);
	sf::Vector2i newPosition(sf::Vector2i pos);
	sf::Vector2i positionToXY(sf::Vector2i pos);

	int getId();
	char getPosXChar();
	int getPosX();
	int getPosY();
	bool getIsFieldTaken();

	void setFieldStatus(bool yesOrNo);
};

