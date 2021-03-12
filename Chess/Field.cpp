#include "Field.h"

char Field::getPosX()
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

Field::Field(char x, int y, bool isTaken)
{
	this->x = x;
	this->y = y;
	this->isTaken = isTaken;
}

Field::~Field()
{
}
