#include "Chessman.h"

void Chessman::initVariables()
{
    if (!this->gameTextures.loadFromFile("Assets/sprites.png"))
        std::cout << "Could not load sprites.png";
    this->chessman.setTexture(this->gameTextures);
}

void Chessman::initChessman(bool blackOrWhite, int typeOfChessman, int posX, int posY, Field* chField)
{
    this->chessmanSrc = sf::IntRect(blackOrWhite * 16, typeOfChessman * 16, 16, 16);
    this->chessman.setTextureRect(this->chessmanSrc);
    this->chessman.setOrigin(sf::Vector2f(this->chessman.getGlobalBounds().width / 2, this->chessman.getGlobalBounds().height / 2));
    this->chessman.setScale(sf::Vector2f(6.2f, 6.2f));
    
    this->chessman.setPosition(sf::Vector2f(20, chField->getPosY()));
}

Chessman::Chessman(bool blackOrWhite, int typeOfChessman, int posX, int posY, Field* chField)
{
    this->initVariables();
    this->initChessman(blackOrWhite, typeOfChessman, posX, posY, chField);
}

Chessman::~Chessman()
{
}

void Chessman::drag(sf::RenderWindow& target, sf::Vector2i pos)
{
    /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //&& sf::Mouse::getPosition().x >= 400)
    {
        auto cord = Field::fieldPositon(target);
        //std::cout << std::get<0>(notation) << std::get<1>(notation) << "\n";
        this->chessman.setPosition(target.getPosition().x, target.getPosition().y);
    }*/
    bool isPickUp = true;

    if (ev.MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && this->chessman.getGlobalBounds().contains(target.mapPixelToCoords(pos)))
    {
        this->chessman.setPosition(pos.x, pos.y);
        isPickUp = false;
    }

    if (ev.MouseButtonReleased && isPickUp == false)
    {
        this->chessman.setPosition(pos.x + 10, pos.y);
    }

    //&& pos.x > this->chessman.getGlobalBounds().left
    //&& pos.x < this->chessman.getGlobalBounds().left - 16)
    //&& pos.y < this->chessman.getGlobalBounds().top
    //&& pos.y > this->chessman.getGlobalBounds().top + 16)
}

void Chessman::update(sf::RenderWindow& target)
{
}

void Chessman::render(sf::RenderTarget& target)
{
    target.draw(this->chessman);
}
