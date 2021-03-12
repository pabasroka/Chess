#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 800);
	this->window = new sf::RenderWindow(this->videoMode, "Chess");
	this->window->setFramerateLimit(60);
}

Game::Game()
{
	this->initWindow();
	this->chessboard = new Chessboard;
}

Game::~Game()
{
	delete this->chessboard;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::update()
{
	this->pollEvents();
	this->chessboard->update(*this->window);
}

void Game::render()
{
	this->window->clear();

	this->chessboard->render(*this->window);

	this->window->display();
}
