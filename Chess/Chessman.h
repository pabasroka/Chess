#pragma once
#include<SFML/Graphics.hpp>
#include"Field.h"
#include<iostream>

class Chessman : public Field
{
	sf::Texture gameTextures;
	sf::Sprite chessman;
	sf::IntRect chessmanSrc;
	sf::Vector2i newPositions;

	sf::Event ev;

	void initVariables();
	void initChessman(bool blackOrWhite, int typeOfChessman, Field* chField);

public:
	Chessman(bool blackOrWhite, int typeOfChessman, Field* chField);
	virtual ~Chessman();

	void drag(sf::RenderWindow& target, sf::Vector2i pos);
	bool isActive(sf::RenderWindow& target, sf::Vector2i pos, Chessman& ch);

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);

};

