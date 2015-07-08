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
		for (int j = 0; j < MAX_SIZE;j++)
		{
			Piece list = Piece();
			maplists[i].push_front(list);
		}
	}
}


//Swap
void Map::Swap(int x1,int y1,int x2,int y2)
{
	if (
		x1 >= 0 && x1 < MAX_SIZE && y1 >= 0 && y1 < MAX_SIZE
		&& x2 >= 0 && x2 < MAX_SIZE && y2 >= 0 && y2 < MAX_SIZE)
	{

		Piece temp;
		temp = maplists[x1][y1];
		maplists[x1][y1]= maplists[x2][y2];
		maplists[x2][y2]= temp;
	}
	else
	{
		return;
	}
}

//isPieceClearable
bool Map::isPieceClearable(int x, int y)
{
	bool flag = false;

	//right
	if (x + 2 < MAX_SIZE)
	{
		if (maplists[x][y] == maplists[x + 1][y] && maplists[x][y] == maplists[x + 2][y])
		{
			flag = true;
		}
	}

	//left
	if (x - 2 > 0)
	{
		if (maplists[x][y] == maplists[x - 1][y] && maplists[x][y] == maplists[x - 2][y])
		{
			flag = true;
		}
	}

	//top
	if (y - 2 > 0)
	{
		if (maplists[x][y] == maplists[x][y - 1] && maplists[x][y] == maplists[x][y - 2])
		{
			flag = true;
		}
	}

	//bottom
	if (y + 2 < MAX_SIZE)
	{
		if (maplists[x][y] == maplists[x][y + 1] && maplists[x][y] == maplists[x][y + 2])
		{
			flag = true;
		}
	}
	
	return flag;
}

//isDead
bool Map::isDead(int x, int y)
{
	//Swap right
	Swap(x, y, x + 1, y);
	if (isPieceClearable(x + 1,y))
	{
		return false;
	}
	//recover
	Swap(x, y, x + 1, y);

	//Swap down
	Swap(x, y, x, y + 1);
	if (isPieceClearable(x,y + 1))
	{
		return false;
	}
	//recover
	Swap(x, y, x, y + 1);
	return true;
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

//Set this version as default,by wafer
//another way to judge DeadMap
// means a number instead a color
bool Map::isDeadMap_()
{
	//from the second line(the border will be judged by another way)
	for (int i = 1; i < 8; i++){
		for (int j = 0; j < 9; j++)
		{
			//if there were any the same color Piece at the next line.
			if (getMaplists()[i][j]== getMaplists()[i][j + 1]){
				if ((getMaplists()[i][j]== getMaplists()[i - 1][j - 1]) || (getMaplists()[i][j]== getMaplists()[i + 1][j - 1]) ||//对相邻行检查
					(getMaplists()[i][j]== getMaplists()[i - 1][j + 2]) || (getMaplists()[i][j]== getMaplists()[i + 1][j + 2]))
				{
					return false;
				}
				if (j >= 2)
				{
					if (getMaplists()[i][j]== getMaplists()[i][j - 2])//向前检查
						return false;
				}
				if (j <= 6)
				{
					if (getMaplists()[i][j]== getMaplists()[i][j + 3])//向后检查
						return false;
				}
				j++;
			}
			//if there were any the same color Piece between another color
			if (j <= 6)
			{
				if (getMaplists()[i][j]== getMaplists()[i][j + 2])//对相邻行检查
				{
					if ((getMaplists()[i][j]== getMaplists()[i - 1][j + 1]) || (getMaplists()[i][j] == getMaplists()[i + 1][j + 1]))
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
			//if there were any the same color Piece at the next list.
			if (getMaplists()[j][i] == getMaplists()[j + 1][i])
			{
				if ((getMaplists()[j][i] == getMaplists()[j - 1][i - 1]) || (getMaplists()[j][i] == getMaplists()[j - 1][i + 1]) ||//对相邻列检查
					(getMaplists()[j][i] == getMaplists()[j + 2][i - 1]) || (getMaplists()[j][i] == getMaplists()[j + 2][i + 1]))
				{
					return false;
				}
				if (j >= 2)
				{
					if (getMaplists()[j][i] == getMaplists()[j - 2][i])//向上检查
						return false;
				}
				if (j <= 6){
					if (getMaplists()[j][i] == getMaplists()[j + 3][i])//向下检查
						return false;
				}
				j++;
			}
			//if there were any the same color Piece between another color
			if (j <= 6)
			{
				if (getMaplists()[j][i] == getMaplists()[j + 2][i])//对相邻列检查
				{
					if ((getMaplists()[j][i] == getMaplists()[j + 1][i - 1]) || (getMaplists()[j][i] == getMaplists()[j + 1][i + 1]))
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
			if (getMaplists()[0][j] == getMaplists()[0][j + 1])
			{
				if ((getMaplists()[0][j] == getMaplists()[0][j + 3]) || (getMaplists()[0][j] == getMaplists()[1][j + 2]))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[0][j] == getMaplists()[1][j - 1])
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[0][j] == getMaplists()[0][j - 2]) || (getMaplists()[0][j] == getMaplists()[0][j + 3]) ||
						(getMaplists()[0][j] == getMaplists()[1][j - 1]) || (getMaplists()[0][j] == getMaplists()[1][j + 2]))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[0][j] == getMaplists()[0][j + 1])
			{
				if ((getMaplists()[0][j] == getMaplists()[0][j - 2]) || (getMaplists()[0][j] == getMaplists()[1][j - 1]))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[0][j] == getMaplists()[1][j + 3])
						return false;
				}
			}
		}
		//last line
		if (j >= 0 && j <= 5)
		{
			if (getMaplists()[8][j] == getMaplists()[8][j + 1])
			{
				if ((getMaplists()[8][j] == getMaplists()[8][j + 3]) || (getMaplists()[8][j] == getMaplists()[7][j + 2]))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[8][j] == getMaplists()[7][j - 1])
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[8][j] == getMaplists()[8][j - 2]) || (getMaplists()[8][j] == getMaplists()[8][j + 3]) ||
						(getMaplists()[8][j] == getMaplists()[7][j - 1]) || (getMaplists()[8][j] == getMaplists()[7][j + 2]))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[8][j] == getMaplists()[8][j + 1])
			{
				if ((getMaplists()[8][j] == getMaplists()[8][j - 2]) || (getMaplists()[8][j] == getMaplists()[7][j - 1]))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[8][j] == getMaplists()[7][j + 3])
						return false;
				}
			}
		}
		//if there is a Piece between two Pieces which are the same color
		//下面用中文好了，便于叙述
		if (j <= 6)//加保险，防越界
		{
			if (getMaplists()[0][j] == getMaplists()[0][j + 2])
			{
				if (getMaplists()[0][j] == getMaplists()[1][j + 1])
					return false;
			}
			if (getMaplists()[8][j] == getMaplists()[8][j + 2])
			{
				if (getMaplists()[8][j] == getMaplists()[7][j + 1])
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
			if (getMaplists()[j][0] == getMaplists()[j + 1][0])
			{
				if ((getMaplists()[j][0] == getMaplists()[j + 3][0]) || (getMaplists()[j][0] == getMaplists()[j + 2][1]))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[j][0] == getMaplists()[j - 1][1])
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[j][0] == getMaplists()[j - 2][0]) || (getMaplists()[j][0] == getMaplists()[j + 3][0]) ||
						(getMaplists()[j][0] == getMaplists()[j - 1][1]) || (getMaplists()[j][0] == getMaplists()[j + 2][1]))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[j][0] == getMaplists()[0][j + 1])
			{
				if ((getMaplists()[j][0] == getMaplists()[j - 2][0]) || (getMaplists()[j][0] == getMaplists()[j - 1][1]))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[j][0] == getMaplists()[j + 3][1])
						return false;
				}
			}
		}
		//last list
		if (j >= 0 && j <= 5)
		{
			if (getMaplists()[j][8] == getMaplists()[j + 1][8])
			{
				if ((getMaplists()[j][8] == getMaplists()[j + 3][8]) || (getMaplists()[j][8] == getMaplists()[j + 2][7]))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[j][8] == getMaplists()[j - 1][7])
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[j][8] == getMaplists()[j - 2][8]) || (getMaplists()[j][8] == getMaplists()[j + 3][8]) ||
						(getMaplists()[j][8] == getMaplists()[j - 1][7]) || (getMaplists()[j][8] == getMaplists()[j + 2][7]))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[j][8] == getMaplists()[j + 1][8])
			{
				if ((getMaplists()[j][8] == getMaplists()[j - 2][8]) || (getMaplists()[j][8] == getMaplists()[j - 1][7]))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[j][8] == getMaplists()[j + 3][7])
						return false;
				}
			}
		}
		//if there is a Piece between two Pieces which are the same color
		//下面用中文好了，便于叙述
		if (j <= 6)//加保险，防越界
		{
			if (getMaplists()[j][0] == getMaplists()[j + 2][0])
			{
				if (getMaplists()[j][0] == getMaplists()[j + 1][1])
					return false;
			}
			if (getMaplists()[j][8] == getMaplists()[j + 2][8])
			{
				if (getMaplists()[j][8] == getMaplists()[j + 1][7])
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

