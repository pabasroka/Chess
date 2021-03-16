#pragma once
#include"Field.h"
#include"Chessman.h"
#include <vector>

class Chessboard : public Field
{
	sf::RectangleShape* pieces;
	std::vector<Field*> fields;
	//Field* fields;
	std::vector<Chessman*> chessmanArray;
	
	int number; 
	char x;
	int y;
	bool blackOrWhite;


	void initVariables();
	void initNewChessboard();

public:
	Chessboard();
	virtual ~Chessboard();

	void mouseHover(sf::RenderWindow& target);
	void showFreeFields();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);
};

