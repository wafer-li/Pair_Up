#ifndef PIECE_H
#define PIECE_H
#include <ctime>
#include <cstdlib>
#include <iostream>

class Piece
{
public:
	Piece(void);//initialization
	~Piece(void);
	bool operator==(Piece &p);
	int getType();
	int getSpecType();
	int getIsClear();
private:
	int type;
	int specType;//we have 6 special spieces
	//1.00.line 2.00.row 3.00.box 4.00.same color 5.00.unclear 6.00.death
	int isClear;
};

#endif