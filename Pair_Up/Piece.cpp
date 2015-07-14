#include "Piece.h"
#include <ctime>


//create a normal type or special type
Piece::Piece(void)
{
	isClear = 0;
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
			specType = 6;//addTime
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