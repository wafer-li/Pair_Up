#include "Map.h"


//Cont
Map::Map()
{
	//Initial the map structure
	for (int i = 0; i < MAX_SIZE; i++)
	{
		maplists[i] = std::list<Piece>(MAX_SIZE);
	}
}

//De
Map::~Map()
{
	/* ... */
}


//Method

//isPass
bool Map::getIsPass()
{
	return isPass;
}

void Map::setIsPass(int flag)
{
	isPass = flag;
}


//PassScore
int Map::getPassScore()
{
	return passScore;
}

void Map::setPassScore(int score)
{
	passScore = score;
}