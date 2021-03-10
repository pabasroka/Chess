#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Chessboard
{
	sf::RectangleShape* pieces;
	int number; 

	void initVariables();
	void createNewChessboard();
	void mouseHover();

public:
	Chessboard();
	virtual ~Chessboard();

	void update();
	void render(sf::RenderTarget& target);
};

