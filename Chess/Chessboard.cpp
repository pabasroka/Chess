#include "Chessboard.h"

void Chessboard::initVariables()
{
	this->pieces = new sf::RectangleShape[64];
	this->number = 0;
    this->x = 'a';
    this->y = 8;
    this->blackOrWhite = 1;
}

void Chessboard::initNewChessboard() // view(pieces) and logic(Field)
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            std::cout << this->x << " ";
            //Field - logic
            if (this->y == 2) 
            {
                this->fields.push_back(new Field(this->x, this->y, true));
                this->chessmanArray.push_back(new Chessman(1, 0, *this->fields.back()));
            }
            else if (this->y == 1)
            {
                this->fields.push_back(new Field(this->x, this->y, true));
                this->chessmanArray.push_back(new Chessman(1, 0, *this->fields.back()));
            }
            else if (this->y == 7)
            {
                this->fields.push_back(new Field(this->x, this->y, true));
                this->chessmanArray.push_back(new Chessman(0, 0, *this->fields.back()));
            }
            else if (this->y == 8)
            {
                this->fields.push_back(new Field(this->x, this->y, true));
                switch (this->x)
                {
                case 'a': case 'h':
                    this->chessmanArray.push_back(new Chessman(0, 1, *this->fields.back()));
                    break;
                }       
            }
            else
                this->fields.push_back(new Field(this->x, this->y, false));

            //Pieces - view 
            this->pieces[this->number].setSize(sf::Vector2f(100, 100));
            this->pieces[this->number].setPosition(sf::Vector2f(j * 100, i * 100));

            if (i % 2 == 0)
                (this->number % 2 == 0) ? this->pieces[this->number].setFillColor(sf::Color::White) : this->pieces[this->number].setFillColor(sf::Color::Blue);
            else
                (this->number % 2 == 0) ? this->pieces[this->number].setFillColor(sf::Color::Blue) : this->pieces[this->number].setFillColor(sf::Color::White);


            this->x++;
            this->number++;
        }
        this->x = 'a'; 
        this->y--;
    }

}

void Chessboard::mouseHover(sf::RenderWindow& target)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        auto notation = Field::fieldPositon(target);
        std::cout << std::get<0>(notation) << std::get<1>(notation) << "\n";
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        this->showFreeFields();

    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        this->chessmanArray[0]->newPosition()
    }*/

    for (auto& ch : chessmanArray)
    {
        if (ch->isActive(target, sf::Mouse::getPosition(target), *ch))
        {
            ch->drag(target, sf::Mouse::getPosition(target));
            break;
        }
    }
    
    //this->chessmanArray[0]->drag(target, sf::Mouse::getPosition(target));
    //this->chessmanArray[1]->drag(target, sf::Mouse::getPosition(target));

}

void Chessboard::showFreeFields()
{
    std::cout << "\n==================================================================\n";
    for (size_t i = 0; i < fields.size(); i++)
    {
        if (i % 8 == 0)
            std::cout << "\n";
        std::cout << this->fields[i]->getPosXChar() << this->fields[i]->getPosY()
            << " [" << this->fields[i]->getIsFieldTaken() << "] ";
        
    }
    std::cout << "\n==================================================================\n\n";
}

Chessboard::Chessboard()
{
	this->initVariables();
	this->initNewChessboard();
}

Chessboard::~Chessboard()
{
    delete[] this->pieces;
}

void Chessboard::update(sf::RenderWindow& target)
{
    this->mouseHover(target);
}

void Chessboard::render(sf::RenderTarget& target)
{
	for (size_t i = 0; i < 64; i++)
		target.draw(this->pieces[i]);

    for (size_t i = 0; i < this->chessmanArray.size(); i++)
        this->chessmanArray[i]->render(target);
        
}
