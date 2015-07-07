#include "Map.h"

//Cont
Map::Map()
{
	//Initial the map structure
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Piece list = Piece();
		maplists[i].push_front(list);
	}
}

//De
Map::~Map()
{
	/* ... */
}


//Method

//Initial the map
void Map::initMap()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE;j++)
		{
			Piece list = Piece();
			maplists[i].push_front(list);
		}
	}
}


//Swap
void Map::Swap(Piece & piece1, Piece & piece2)
{
	if (
		piece1.x >= 0 && piece1.x < MAX_SIZE&&piece1.y >= 0 && piece1.y < MAX_SIZE
		&&piece2.x >= 0 && piece2.x < MAX_SIZE&&piece2.y >= 0 && piece2.y < MAX_SIZE)
	{

		Piece temp;
		temp = piece1;
		piece1 = piece2;
		piece2 = temp;
	}
	else
	{
		return;
	}
}

//isDead
bool Map::isDead(int x, int y)
{
	bool flag = false;
	
	//Swap right
	Swap(maplists[x][y], maplists[x + 1][y]);
	if (judge(maplists[x][y],maplists[x + 1][y]))
	{
		flag = false;
	}
	else
	{
		flag = true;
	}
	
	//Return same
	Swap(maplists[x][y], maplists[x + 1][y]);

	//Swap down
	Swap(maplists[x][y], maplists[x][y + 1]);
	if (judge(maplists[x][y], maplists[x][y + 1]))
	{
		flag = false;
	}
	else
	{
		flag = true;
	}
	
	//Return same
	Swap(maplists[x][y], maplists[x][y + 1]);
	
	return flag;
}

//isDeadMap
bool Map::isDeadMap()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (!isDead(i, j))
			{
				return false;
			}
		}
	}
	return true;
}

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

//Maplists
std::deque<Piece> * Map::getMaplists()
{
	return maplists;
}