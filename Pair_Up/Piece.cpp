#include "Piece.h"
#include <ctime>


//create a normal type or special type
Piece::Piece(void)
{
	isClear = 0;
	specType = 0;//initialize it as a normal piece
	int flag = rand() % 1500 + 1;
	if (flag >= 1400)
	{
		//1490-1500   p:3 3 1 1 1 1
		if (flag >= 1400 && flag < 1430)
			specType = 1;//line
		if (flag >= 1430 && flag < 1460)
			specType = 2;//row
		if (flag >= 1460 && flag < 1480)
			specType = 3;//box
		if (flag >= 1480 && flag < 1495)
			specType = 4;//same color
		if (flag >= 1495 && flag < 1501)
			specType = 5;//unclear
	}
	type = flag % 6 + 1;
	//Update7-7:tgf:特殊方块也是有基本属性的
}

Piece::~Piece(void)
{
}


bool Piece::operator==(Piece &p)
{
	//Update by wafer:Fix bug
	if (type == p.type )	//when the basic type are equeal, it means the object are equal
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

int Piece::getIsClear()
{
	return this->isClear;
}

void Piece::setIsClear(int flag)
{
	this->isClear = flag;
}

int Piece::getMovePoint()
{
	return this->movePoint;
}

void Piece::setMovePoint(int temp)
{
	this->movePoint = temp;
}