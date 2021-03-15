#include "Chessman.h"

void Chessman::initVariables()
{
    if (!this->gameTextures.loadFromFile("Assets/sprites.png"))
        std::cout << "Could not load sprites.png";
    this->chessman.setTexture(this->gameTextures);
}

void Chessman::initChessman(bool blackOrWhite, int typeOfChessman, Field* chField)
{
    this->chessmanSrc = sf::IntRect(blackOrWhite * 16, typeOfChessman * 16, 16, 16);
    this->chessman.setTextureRect(this->chessmanSrc);
    this->chessman.setOrigin(sf::Vector2f(this->chessman.getGlobalBounds().width / 2, this->chessman.getGlobalBounds().height / 2));
    this->chessman.setScale(sf::Vector2f(6.f, 6.f));
    
    this->chessman.setPosition(sf::Vector2f(chField->getPosX() * 100 - 50, chField->getPosY() * 100 - 50));
}

Chessman::Chessman(bool blackOrWhite, int typeOfChessman, Field* chField)
{
    this->initVariables();
    this->initChessman(blackOrWhite, typeOfChessman, chField);
}

Chessman::~Chessman()
{
}

void Chessman::drag(sf::RenderWindow& target, sf::Vector2i pos)
{
    auto cord = fieldPositon(target);
    std::cout << std::get<0>(cord) << std::get<1>(cord) << "\n";

    //BUTTON PRESSED
    while (this->ev.MouseButtonPressed)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
            && this->chessman.getGlobalBounds().contains(target.mapPixelToCoords(pos)))
            this->chessman.setPosition(pos.x, pos.y);
        else break;
    }

    
    //BUTTON REALEASED 
    if (this->ev.MouseButtonReleased)
    {
        this->newPositions = newPosition(sf::Mouse::getPosition(target));
        this->chessman.setPosition(this->newPositions.x, this->newPositions.y);
//this->
    }

    std::cout << this->newPositions.x << " " << this->newPositions.y << "\n";
}

bool Chessman::isActive(sf::RenderWindow& target, sf::Vector2i pos, Chessman& ch)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && this->chessman.getGlobalBounds().contains(target.mapPixelToCoords(pos)))
        return true;
    else
        return false;
}

void Chessman::update(sf::RenderWindow& target)
{
}

void Chessman::render(sf::RenderTarget& target)
{
    target.draw(this->chessman);
}




/*=================    DRAG METHOD     ====================*/
/*while (target.pollEvent(this->ev))
    {

    }*/

    /*switch (this->ev.type)
    {
    case sf::Event::MouseButtonPressed:

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
            && this->chessman.getGlobalBounds().contains(target.mapPixelToCoords(pos)))
            this->chessman.setPosition(pos.x, pos.y);

        break;

    case sf::Event::MouseButtonReleased:
        this->chessman.setPosition(newPosition(pos).x, newPosition(pos).y);
        break;
    }*/
    /*if (e == true && this->ev.MouseButtonReleased)
    {

        this->newPositions = newPosition(sf::Mouse::getPosition(target));

        std::cout << newPosition(sf::Mouse::getPosition(target)).x << " " << newPosition(sf::Mouse::getPosition(target)).y << "\n";
        //this->chessman.setPosition(newPosition(sf::Mouse::getPosition(target)).x, newPosition(sf::Mouse::getPosition(target)).y);
        //this->chessman.setPosition(newPosition(pos).x, newPosition(pos).y);
        this->chessman.setPosition(this->newPositions.x, this->newPositions.y);
        e = false;
    }*/




    /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //&& sf::Mouse::getPosition( l).x >= 400)
{
    auto cord = Field::fieldPositon(target);
    //std::cout << std::get<0>(notation) << std::get<1>(notation) << "\n";
    this->chessman.setPosition(target.getPosition().x, target.getPosition().y);
}*/