#include "Piece.h"
#include <ctime>

//create a normal type or special type
Piece::Piece(void)
{
	specType = 0;//initialize it as a normal piece
	int flag = rand() % 1500 + 1;
	if (flag >= 1490)
	{
		//1490-1500   p:3 3 1 1 1 1
		if (flag >= 1491 && flag <= 1493)
			specType = 1;//line
		if (flag >= 1494 && flag <= 1496)
			specType = 2;//row
		if (flag == 1497)
			specType = 3;//box
		if (flag == 1498)
			specType = 4;//same color
		if (flag == 1499)
			specType = 5;//unclear
		if (flag == 1500)
			specType = 6;//death
	}
	else
		type = flag % 6 + 1;
}


Piece::~Piece(void)
{
}


bool Piece::operator==(Piece &p)
{
	if (type == p.type || specType == p.specType)
	{
		return true;
	}
	else
		return false;
}
int Piece::getType()
{
	return this->type;
}
int Piece::getSpecType()
{
	return this->specType;
}