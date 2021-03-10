#include "Chessboard.h"

void Chessboard::initVariables()
{
	this->pieces = new sf::RectangleShape[64];
	this->number = 0;
}

void Chessboard::createNewChessboard()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            pieces[number].setSize(sf::Vector2f(100, 100));
            pieces[number].setPosition(sf::Vector2f(j * 100, i * 100));

            if (i % 2 == 0)
                (number % 2 == 0) ? pieces[number].setFillColor(sf::Color::White) : pieces[number].setFillColor(sf::Color::Blue);
            else
                (number % 2 == 0) ? pieces[number].setFillColor(sf::Color::Blue) : pieces[number].setFillColor(sf::Color::White);

            number++;
        }
    }
}

void Chessboard::mouseHover()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        std::cout << "dzia³o";

    //if(sf::Mouse::getPosition)
}

Chessboard::Chessboard()
{
	this->initVariables();
	this->createNewChessboard();
}

Chessboard::~Chessboard()
{
    delete[] pieces;
}

void Chessboard::update()
{
    this->mouseHover();
}

void Chessboard::render(sf::RenderTarget& target)
{
	for (size_t i = 0; i < 64; i++)
		target.draw(this->pieces[i]);
}




