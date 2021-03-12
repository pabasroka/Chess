#include "Field.h"

Field::Field()
{
}

Field::Field(char x, int y, bool isTaken)
{
    this->x = x;
    this->y = y;
    this->isTaken = isTaken;
}

Field::~Field()
{
}

char Field::getPosX()
{
    switch (this->x)
    {
    case 'a':
        return 1;
        break;
    case 'b':
        return 2;
        break;
    case 'c':
        return 3;
        break;
    case 'd':
        return 4;
        break;
    case 'e':
        return 5;
        break;
    case 'f':
        return 6;
        break;
    case 'g':
        return 7;
        break;
    case 'h':
        return 8;
        break;
    }
}


char Field::getPosXChar()
{
	return this->x;
}

int Field::getPosY()
{
	return this->y;
}

bool Field::getIsFieldTaken()
{
	return this->isTaken;
}

std::tuple<char, int> Field::fieldPositon(sf::RenderWindow& target)
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
    else if (posX >= 700 && posX < 800)
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

