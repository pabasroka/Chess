#include "Chessboard.h"

void Chessboard::initVariables()
{
	this->pieces = new sf::RectangleShape[64];
	this->number = 0;
    this->x = 'a';
    this->y = 1;
}

void Chessboard::createNewChessboard() // view(pieces) and logic(Field)
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            this->pieces[this->number].setSize(sf::Vector2f(100, 100));
            this->pieces[this->number].setPosition(sf::Vector2f(j * 100, i * 100));

            if(this->y == 1|| this->y == 2 || this->y == 7 || this->y == 8)
                this->fields.push_back(new Field(this->x, this->y, true));
            else
                this->fields.push_back(new Field(this->x, this->y));

            if (i % 2 == 0)
                (this->number % 2 == 0) ? this->pieces[this->number].setFillColor(sf::Color::White) : this->pieces[this->number].setFillColor(sf::Color::Blue);
            else
                (this->number % 2 == 0) ? this->pieces[this->number].setFillColor(sf::Color::Blue) : this->pieces[this->number].setFillColor(sf::Color::White);

            std::cout << this->x << " " << this->y << " " << this->fields.back()->getIsFieldTaken() << "\n";

            this->x++;
            this->number++;
        }
        this->x = 'a'; 
        this->y++;
    }
}

void Chessboard::mouseHover(sf::RenderWindow& target)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        std::cout << fields[3]->getPosX() << " " << fields[3]->getPosY() << fields[3]->getIsFieldTaken() << "\n";

    //if (sf::Mouse::getPosition())
       /* std::cout << typeid(sf::Mouse::getPosition(target).x).name() << " " 
            << sf::Mouse::getPosition(target).x << " "
            << typeid(sf::Mouse::getPosition(target).y).name() << " "
            << sf::Mouse::getPosition(target).y << "\n";*/

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        auto notation = fieldPositon(target);
        std::cout << std::get<0>(notation) << std::get<1>(notation) << "\n";
    }


}

std::tuple<char, int> Chessboard::fieldPositon(sf::RenderWindow& target)
{
    char x{};
    int y{};
    int posX = sf::Mouse::getPosition(target).x;
    int posY = sf::Mouse::getPosition(target).y;

    if (posX >= 0 && posX < 100)
        x = 'a';
    else if (posX >= 100 && posX < 200)
        x = 'b';
    else if (posX >= 200 && posX < 300)
        x = 'c';
    else if (posX >= 300 && posX < 400)
        x = 'd';
    else if (posX >= 400 && posX < 500)
        x = 'e';
    else if (posX >= 500 && posX < 600)
        x = 'f';
    else if (posX >= 600 && posX < 700)
        x = 'g';
    else if(posX >= 700 && posX < 800)
        x = 'h';

    if (posY >= 0 && posY < 100)
        y = 8;
    else if (posY >= 100 && posY < 200)
        y = 7;
    else if (posY >= 200 && posY < 300)
        y = 6;
    else if (posY >= 300 && posY < 400)
        y = 5;
    else if (posY >= 400 && posY < 500)
        y = 4;
    else if (posY >= 500 && posY < 600)
        y = 3;
    else if (posY >= 600 && posY < 700)
        y = 2;
    else if (posY >= 700 && posY < 800)
        y = 1;

    return { x, y };
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

void Chessboard::update(sf::RenderWindow& target)
{
    this->mouseHover(target);
}

void Chessboard::render(sf::RenderTarget& target)
{
	for (size_t i = 0; i < 64; i++)
		target.draw(this->pieces[i]);
}
