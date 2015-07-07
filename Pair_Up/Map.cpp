#include "Map.h"

//Ctor
Map::Map()
{
	//Initial the map structure
	for (int i = 0; i < MAX_SIZE; i++)
	{
		maplists[i] = std::deque<Piece>(MAX_SIZE);
	}
}

//Dtor
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
			Piece list = Piece(i,j);
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

//another way to judge DeadMap
//colorNum means a number instead a color
bool Map::isDeadMap_()
{
	//from the second line(the border will be judged by another way)
	for (int i = 1; i < 8; i++){
		for (int j = 0; j < 9; j++)
		{
			//if there were any the same color Piece at the next line.
			if (getMaplists()[i][j].colorNum == getMaplists()[i][j + 1].colorNum){
				if ((getMaplists()[i][j].colorNum == getMaplists()[i - 1][j - 1].colorNum) || (getMaplists()[i][j].colorNum == getMaplists()[i + 1][j - 1]) || (getMaplists()[i][j].colorNum == getMaplists()[i - 1][j + 2]) || (getMaplists()[i][j].colorNum == getMaplists()[i + 1][j + 2]))
				{
					return false;
				}
				else if (j >= 2)
				{
					if (getMaplists()[i][j].colorNum == getMaplists()[i][j - 2])
						return false;
				}
				else if (j <= 6)
				{
					if (getMaplists()[i][j].colorNum == getMaplists()[i][j + 2])
						return false;
				}
				j++;
			}
			//if there were any the same color Piece between another color
			if (j <= 6)
			{
				if (getMaplists()[i][j].colorNum == getMaplists()[i][j + 2].colorNum)
				{
					if ((getMaplists()[i][j].colorNum == getMaplists()[i - 1][j + 1].colorNum) || (getMaplists()[i][j].colorNum == getMaplists()[i + 1][j + 1].colorNum))
						return false;
				}
			}
		}
	}
	//from the second list to the eighth list(do not need to 
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			//if there were any the same color Piece at the next line.
			if (getMaplists()[j][i].colorNum == getMaplists()[j + 1][i].colorNum)
			{
				if ((getMaplists()[j][i].colorNum == getMaplists()[j - 1][i - 1].colorNum) || (getMaplists()[j][i].colorNum == getMaplists()[j - 1][i + 1]) || (getMaplists()[j][i].colorNum == getMaplists()[j + 2][i - 1]) || (getMaplists()[j][i].colorNum == getMaplists()[j + 2][i + 1]))
				{
					return false;
				}
				else if (j >= 2)
				{
					if (getMaplists()[j][i].colorNum == getMaplists()[j - 2][i])
						return false;
				}
				else if (j <= 6){
					if (getMaplists()[j][i].colorNum == getMaplists()[j + 2][i])
						return false;
				}
				j++;
			}
			//if there were any the same color Piece between another color
			if (j <= 6)
			{
				if (getMaplists()[j][i].colorNum == getMaplists()[j + 2][i].colorNum)
				{
					if ((getMaplists()[j][i].colorNum == getMaplists()[j + 1][i - 1].colorNum) || (getMaplists()[j][i].colorNum == getMaplists()[j + 1][i + 1].colorNum))
						return false;
				}
			}
		}
	}
	//the first line and the last line
	for (int j = 0; j < 8; j++)
	{
		//first line
		if (j >= 0 && j <= 5)
		{
			if (getMaplists()[0][j].colorNum == getMaplists()[0][j + 1])
			{
				if ((getMaplists()[0][j].colorNum == getMaplists()[0][j + 3].colorNum) || (getMaplists()[0][j].colorNum == getMaplists()[1][j + 2]))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[0][j].colorNum == getMaplists()[1][j - 1].colorNum)
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[0][j].colorNum == getMaplists()[0][j - 2].colorNum) || (getMaplists()[0][j].colorNum == getMaplists()[0][j + 3].colorNum) || (getMaplists()[0][j].colorNum == getMaplists()[1][j - 1].colorNum) || (getMaplists()[0][j].colorNum == getMaplists()[1][j + 2].colorNum))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[0][j].colorNum == getMaplists()[0][j + 1])
			{
				if ((getMaplists()[0][j].colorNum == getMaplists()[0][j - 2].colorNum) || (getMaplists()[0][j].colorNum == getMaplists()[1][j - 1]))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[0][j].colorNum == getMaplists()[1][j + 3].colorNum)
						return false;
				}
			}
		}
		//last line
		if (j >= 0 && j <= 5)
		{
			if (getMaplists()[8][j].colorNum == getMaplists()[8][j + 1])
			{
				if ((getMaplists()[8][j].colorNum == getMaplists()[8][j + 3].colorNum) || (getMaplists()[8][j].colorNum == getMaplists()[7][j + 2]))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[8][j].colorNum == getMaplists()[7][j - 1].colorNum)
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[8][j].colorNum == getMaplists()[8][j - 2].colorNum) || (getMaplists()[8][j].colorNum == getMaplists()[8][j + 3].colorNum) || (getMaplists()[8][j].colorNum == getMaplists()[7][j - 1].colorNum) || (getMaplists()[8][j].colorNum == getMaplists()[7][j + 2].colorNum))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[8][j].colorNum == getMaplists()[8][j + 1])
			{
				if ((getMaplists()[8][j].colorNum == getMaplists()[8][j - 2].colorNum) || (getMaplists()[8][j].colorNum == getMaplists()[7][j - 1].colorNum))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[8][j].colorNum == getMaplists()[7][j + 3].colorNum)
						return false;
				}
			}
		}
		//if there is a Piece between two Pieces which are the same color
		//下面用中文好了，便于叙述
		if (j <= 6)//加保险，防越界
		{
			if (getMaplists()[0][j].colorNum == getMaplists()[0][j + 2].colorNum)
			{
				if (getMaplists()[0][j].colorNum == getMaplists()[1][j + 1].colorNum)
					return false;
			}
			if (getMaplists()[8][j].colorNum == getMaplists()[8][j + 2].colorNum)
			{
				if (getMaplists()[8][j].colorNum == getMaplists()[7][j + 1].colorNum)
					return false;
			}
		}
	}

	//the first list and the last list
	for (int j = 0; j < 8; j++)
	{
		//first list
		if (j >= 0 && j <= 5)
		{
			if (getMaplists()[j][0].colorNum == getMaplists()[j + 1][0])
			{
				if ((getMaplists()[j][0].colorNum == getMaplists()[j + 3][0].colorNum) || (getMaplists()[j][0].colorNum == getMaplists()[j + 2][1]))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[j][0].colorNum == getMaplists()[j - 1][1])
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[j][0].colorNum == getMaplists()[j - 2][0].colorNum) || (getMaplists()[j][0].colorNum == getMaplists()[j + 3][0].colorNum) || (getMaplists()[j][0].colorNum == getMaplists()[j - 1][1].colorNum) || (getMaplists()[j][0].colorNum == getMaplists()[j + 2][1].colorNum))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[j][0].colorNum == getMaplists()[0][j + 1])
			{
				if ((getMaplists()[j][0].colorNum == getMaplists()[j - 2][0].colorNum) || (getMaplists()[j][0].colorNum == getMaplists()[j - 1][1]))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[j][0].colorNum == getMaplists()[j + 3][1].colorNum)
						return false;
				}
			}
		}
		//last list
		if (j >= 0 && j <= 5)
		{
			if (getMaplists()[j][8].colorNum == getMaplists()[j + 1][8])
			{
				if ((getMaplists()[j][8].colorNum == getMaplists()[j + 3][8].colorNum) || (getMaplists()[j][8].colorNum == getMaplists()[j + 2][7]))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[j][8].colorNum == getMaplists()[j - 1][7].colorNum)
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[j][8].colorNum == getMaplists()[j - 2][8].colorNum) || (getMaplists()[j][8].colorNum == getMaplists()[j + 3][8].colorNum) || (getMaplists()[j][8].colorNum == getMaplists()[j - 1][7].colorNum) || (getMaplists()[j][8].colorNum == getMaplists()[j + 2][7].colorNum))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[j][8].colorNum == getMaplists()[j + 1][8])
			{
				if ((getMaplists()[j][8].colorNum == getMaplists()[j - 2][8].colorNum) || (getMaplists()[j][8].colorNum == getMaplists()[j - 1][7].colorNum))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[j][8].colorNum == getMaplists()[j + 3][7].colorNum)
						return false;
				}
			}
		}
		//if there is a Piece between two Pieces which are the same color
		//下面用中文好了，便于叙述
		if (j <= 6)//加保险，防越界
		{
			if (getMaplists()[j][0].colorNum == getMaplists()[j + 2][0].colorNum)
			{
				if (getMaplists()[j][0].colorNum == getMaplists()[j + 1][1].colorNum)
					return false;
			}
			if (getMaplists()[j][8].colorNum == getMaplists()[j + 2][8].colorNum)
			{
				if (getMaplists()[j][8].colorNum == getMaplists()[j + 1][7].colorNum)
					return false;
			}
		}
	}
	return true;
}