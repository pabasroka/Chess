#pragma once
#include"Chessboard.h"

class Game
{
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;

	Chessboard* chessboard;

	void initWindow();

public:
	Game();
	virtual ~Game();

	void pollEvents();
	const bool running() const;

	void update();
	void render();
};

