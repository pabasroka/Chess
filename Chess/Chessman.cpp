#include "Chessman.h"

void Chessman::initVariables()
{
    if (!this->gameTextures.loadFromFile("Assets/sprites.png"))
        std::cout << "Could not load sprites.png";
    this->chessman.setTexture(this->gameTextures);
}

void Chessman::initChessman(bool blackOrWhite, int typeOfChessman, Field& chField)
{
    this->chessmanSrc = sf::IntRect(typeOfChessman * 16, blackOrWhite * 16, 16, 16);
    this->chessman.setTextureRect(this->chessmanSrc);
    this->chessman.setOrigin(sf::Vector2f(this->chessman.getGlobalBounds().width / 2, this->chessman.getGlobalBounds().height / 2));
    this->chessman.setScale(sf::Vector2f(6.f, 6.f));
    this->field = chField;
    
    this->chessman.setPosition(sf::Vector2f(chField.getPosX() * 100 - 50, chField.getPosY() * 100 - 50));
}

Chessman::Chessman(bool blackOrWhite, int typeOfChessman, Field& chField)
{
    this->initVariables();
    this->initChessman(blackOrWhite, typeOfChessman, chField);
}

Chessman::~Chessman(){}

Field Chessman::getChessmanField()
{
    return this->field;
}

int Chessman::getFieldId()
{
    return this->field.getId();
}

void Chessman::drag(sf::RenderWindow& target, sf::Vector2i pos, std::vector<Field*>& fields, Chessman& ch, std::vector<Chessman*>& chessmanArray)
{
    auto cord = fieldPositon(target);
    //std::cout << std::get<0>(cord) << std::get<1>(cord) << "\n";
    //this->startingPosition = newPosition(sf::Mouse::getPosition(target));

    //BUTTON PRESSED
    while (this->ev.MouseButtonPressed)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
            && this->chessman.getGlobalBounds().contains(target.mapPixelToCoords(pos)))
            this->chessman.setPosition(pos.x, pos.y);
        else break;
    }


    //BUTTON REALEASED 
    pos = newPosition(pos);
    if (this->ev.MouseButtonReleased)
    {
        this->newPositions = newPosition(sf::Mouse::getPosition(target));
        if (this->newPositions.x < 0 || this->newPositions.y < 0) //if movement is outside chessboard
            this->chessman.setPosition(pos.x, pos.y);
        else
        {
            this->chessman.setPosition(this->newPositions.x, this->newPositions.y);

            fields.at(ch.getFieldId())->setFieldStatus(0);
            ch.setFieldStatus(0);
            
            std::cout << std::get<0>(cord) << std::get<1>(cord) << "\n";
            //if()
                
        }
        cord = fieldPositon(target);
        std::cout << std::get<0>(cord) << std::get<1>(cord) << "\n";

        for (auto iter = fields.begin(); iter != fields.end(); iter++)
        {
            if ((*iter)->getPosXChar() == std::get<0>(cord) && (*iter)->getPosY() == std::get<1>(cord))
            {
                (*iter)->setFieldStatus(1);
                break;
            }
        }
        
        for (auto chArray : chessmanArray)
        {
            //delete chessman;
            /*if (chArray->getPosXChar() == std::get<0>(cord) && chArray->getPosY() == std::get<1>(cord))
            {
                chArray->setFieldStatus(0);
                delete chArray;
            }*/
            if (chArray->getPosXChar() == fields.at(chArray->getFieldId())->getPosXChar()
                && chArray->getPosY() == fields.at(chArray->getFieldId())->getPosY())
            {
                std::cout << "USUWA \n";
                chArray->setFieldStatus(0);          
                fields.erase(fields.begin() + chArray->getFieldId());
                delete chArray;
            }
        }

        fields.at(ch.getFieldId())->setFieldStatus(0);
        ch.setFieldStatus(0);
        
    }
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
