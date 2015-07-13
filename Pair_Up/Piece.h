#ifndef PIECE_H
#define PIECE_H
#include <ctime>
#include <cstdlib>
#include <iostream>

class Piece
{
private:
	int type;
	int specType;//we have 6 special spieces
	//0 ori 1.line 2.row 3.box 4.same color 5.unclear 6.death
	int isClear;
	int movePoint;

public:
	/* Ctor & Dtor */
	Piece(void);//initialization
	~Piece(void);

	/* Method */

	//Type
	int getType();
	int getSpecType();

	//isClear
	int getIsClear();
	void setIsClear(int flag);

	//movePoint
	int getMovePoint();
	void setMovePoint(int temp);

	//Override operator
	bool operator==(Piece &p);
};

#endif