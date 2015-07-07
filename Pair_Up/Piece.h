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
	void setIsClear(int flag);
private:
	int type;
	int specType;//we have 6 special spieces
	//0 ori 1.line 2.row 3.box 4.same color 5.unclear 6.death
	int isClear;
};

#endif