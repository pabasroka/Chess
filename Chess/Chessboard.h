#pragma once
#include"Field.h"
#include <vector>
#include <tuple>

class Chessboard
{
	sf::RectangleShape* pieces;
	std::vector<Field*> fields;
	int number; 
	char x;
	int y;

	void initVariables();
	void createNewChessboard();
	void mouseHover(sf::RenderWindow& target);
	std::tuple<char, int> fieldPositon(sf::RenderWindow& target);

public:
	Chessboard();
	virtual ~Chessboard();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);
};

