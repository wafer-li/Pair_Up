#include "Map.h"
#include "Global.h"

//Ctor
Map::Map()
{
	//Initial the map
	//The Ctor of deque will automatially fill
	//the deque using the default object 
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

//swap
bool Map::swap(int x1,int y1,int x2,int y2)
{
	if (
		x1 >= 0 && x1 < MAX_SIZE && y1 >= 0 && y1 < MAX_SIZE
		&& x2 >= 0 && x2 < MAX_SIZE && y2 >= 0 && y2 < MAX_SIZE)
	{

		Piece temp;
		temp = maplists[x1][y1];
		maplists[x1][y1]= maplists[x2][y2];
		maplists[x2][y2]= temp;
		return true;
	}
	else
	{
		return false;
	}
}

//isPieceClearable
bool Map::isPieceClearable(int x, int y)
{
	bool flag = false;

	if (maplists[x][y].getSpecType() != Global::SpecType::unclearable)
	{

		//right & left
		if (x - 1 >= 0 && x + 1 < MAX_SIZE)	//The Piece is not at the border
		{
			//middle
			if (maplists[x][y] == maplists[x - 1][y] && maplists[x][y] == maplists[x + 1][y] &&
				maplists[x + 1][y].getSpecType() != Global::SpecType::unclearable &&
				maplists[x - 1][y].getSpecType() !=Global::SpecType::unclearable)
			{
				flag = true;
			}

			//left
			if (x - 2 >= 0)
			{
				if (maplists[x][y] == maplists[x - 1][y] && maplists[x][y] == maplists[x - 2][y] &&
					maplists[x - 1][y].getSpecType() != Global::SpecType::unclearable &&
					maplists[x - 2][y].getSpecType() != Global::SpecType::unclearable)
				{
					flag = true;
				}
			}

			//right
			if (x + 2 < MAX_SIZE)
			{
				if (maplists[x][y] == maplists[x + 1][y] && maplists[x][y] == maplists[x + 2][y] &&
					maplists[x + 1][y].getSpecType() != Global::SpecType::unclearable &&
					maplists[x + 2][y].getSpecType() != Global::SpecType::unclearable)
				{
					flag = true;
				}
			}
		}
		else if (x == 0 || x + 1 == MAX_SIZE)	//The Piece is at the border
		{
			//left
			if (x - 2 >= 0)
			{
				if (maplists[x][y] == maplists[x - 1][y] && maplists[x][y] == maplists[x - 2][y] &&
					maplists[x - 1][y].getSpecType() !=Global::SpecType::unclearable &&
					maplists[x - 2][y].getSpecType() !=Global::SpecType::unclearable)
				{
					flag = true;
				}
			}

			//right
			if (x + 2 < MAX_SIZE)
			{
				if (maplists[x][y] == maplists[x + 1][y] && maplists[x][y] == maplists[x + 2][y] &&
					maplists[x + 1][y].getSpecType() !=Global::SpecType::unclearable &&
					maplists[x + 2][y].getSpecType() != Global::SpecType::unclearable)
				{
					flag = true;
				}
			}

		}

		//up & down
		if (y - 1 >= 0 && y + 1 < MAX_SIZE)
		{
			//middle
			if (maplists[x][y] == maplists[x][y + 1] && maplists[x][y] == maplists[x][y - 1] &&
				maplists[x][y + 1].getSpecType() != Global::SpecType::unclearable &&
				maplists[x][y - 1].getSpecType() !=Global::SpecType::unclearable)
			{
				flag = true;
			}

			//up
			if (y + 2 < MAX_SIZE)
			{
				if (maplists[x][y] == maplists[x][y + 1] && maplists[x][y] == maplists[x][y + 2] &&
					maplists[x][y + 1].getSpecType() !=Global::SpecType::unclearable &&
					maplists[x][y + 2].getSpecType() != Global::SpecType::unclearable)
				{
					flag = true;
				}
			}

			//down
			if (y - 2 >= 0)
			{
				if (maplists[x][y] == maplists[x][y - 1] && maplists[x][y] == maplists[x][y - 2] &&
					maplists[x][y - 1].getSpecType() != Global::SpecType::unclearable &&
					maplists[x][y - 2].getSpecType() != Global::SpecType::unclearable)

				{
					flag = true;
				}
			}
		}
		else if (y == 0 || y + 1 == MAX_SIZE)
		{
			//up
			if (y + 2 < MAX_SIZE)
			{
				if (maplists[x][y] == maplists[x][y + 1] && maplists[x][y] == maplists[x][y + 2] &&
					maplists[x][y + 1].getSpecType() !=Global::SpecType::unclearable &&
					maplists[x][y + 2].getSpecType() !=Global::SpecType::unclearable)
				{
					flag = true;
				}
			}

			//down
			if (y - 2 >= 0)
			{
				if (maplists[x][y] == maplists[x][y - 1] && maplists[x][y] == maplists[x][y - 2] &&
					maplists[x][y - 1].getSpecType() !=Global::SpecType::unclearable &&
					maplists[x][y - 2].getSpecType() !=Global::SpecType::unclearable )
				{
					flag = true;
				}
			}

		}

	}
	return flag;
}

//isDead
bool Map::isDead(int x, int y)
{
	bool flag = false;
	if (maplists[x][y].getSpecType() != Global::SpecType::unclearable)
	{
		//swap right
		if (swap(x, y, x + 1, y))
		{
			if (isPieceClearable(x + 1, y) || isPieceClearable(x, y))
			{
				flag = false;
			}
			else
			{
				flag = true;
			}
			//recover
			swap(x, y, x + 1, y);
		}

		//swap up 
		if (swap(x, y, x, y + 1))
		{
			if (isPieceClearable(x, y + 1) || isPieceClearable(x, y))
			{
				flag = false;
			}
			else
			{
				flag = true;
			}
			//recover
			swap(x, y, x, y + 1);
		}
	}
	else
	{
		flag = true;
	}
	return flag;
}


//g_isDeadMap
bool Map::g_isDeadMap()
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
bool Map::g_isDeadMap_()
{
	//from the second line(the border will be judged by another way)
	for (int i = 1; i < 8; i++){
		for (int j = 0; j < 9; j++)
		{
			//if there were any the same color Piece at the next line.
			if (getMaplists()[i][j].getType() == getMaplists()[i][j + 1].getType()){
				if ((getMaplists()[i][j].getType() == getMaplists()[i - 1][j - 1].getType()) || (getMaplists()[i][j].getType() == getMaplists()[i + 1][j - 1].getType()) ||//对相邻行检查
					(getMaplists()[i][j].getType() == getMaplists()[i - 1][j + 2].getType()) || (getMaplists()[i][j].getType() == getMaplists()[i + 1][j + 2].getType()))
				{		 
					return false;
				}
				if (j >= 2)
				{
					if (getMaplists()[i][j].getType() == getMaplists()[i][j - 2].getType())//向前检查
						return false;
				}
				if (j <= 6)
				{
					if (getMaplists()[i][j].getType() == getMaplists()[i][j + 3].getType())//向后检查
						return false;
				}
				j++;
			}
			//if there were any the same color Piece between another color
			if (j <= 6)
			{
				if (getMaplists()[i][j].getType() == getMaplists()[i][j + 2].getType())//对相邻行检查
				{
					if ((getMaplists()[i][j].getType() == getMaplists()[i - 1][j + 1].getType()) || (getMaplists()[i][j].getType() == getMaplists()[i + 1][j + 1].getType()))
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
			if (getMaplists()[j][i].getType() == getMaplists()[j + 1][i].getType())
			{
				if ((getMaplists()[j][i].getType() == getMaplists()[j - 1][i - 1].getType()) || (getMaplists()[j][i].getType() == getMaplists()[j - 1][i + 1].getType()) ||//对相邻列检查
					(getMaplists()[j][i].getType() == getMaplists()[j + 2][i - 1].getType()) || (getMaplists()[j][i].getType() == getMaplists()[j + 2][i + 1].getType()))
				{
					return false;
				}
				if (j >= 2)
				{
					if (getMaplists()[j][i].getType() == getMaplists()[j - 2][i].getType())//向上检查
						return false;
				}
				if (j <= 6){
					if (getMaplists()[j][i].getType() == getMaplists()[j + 3][i].getType())//向下检查
						return false;
				}
				j++;
			}
			//if there were any the same color Piece between another color
			if (j <= 6)
			{
				if (getMaplists()[j][i].getType() == getMaplists()[j + 2][i].getType())//对相邻列检查
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
			if (getMaplists()[0][j].getType() == getMaplists()[0][j + 1].getType())
			{
				if ((getMaplists()[0][j].getType() == getMaplists()[0][j + 3].getType()) || (getMaplists()[0][j].getType() == getMaplists()[1][j + 2].getType()))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[0][j] == getMaplists()[1][j - 1])
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[0][j].getType() == getMaplists()[0][j - 2].getType()) || (getMaplists()[0][j].getType() == getMaplists()[0][j + 3].getType()) ||
						(getMaplists()[0][j].getType() == getMaplists()[1][j - 1].getType()) || (getMaplists()[0][j].getType() == getMaplists()[1][j + 2].getType()))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[0][j].getType() == getMaplists()[0][j + 1].getType())
			{
				if ((getMaplists()[0][j].getType() == getMaplists()[0][j - 2].getType()) || (getMaplists()[0][j].getType() == getMaplists()[1][j - 1].getType()))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[0][j].getType() == getMaplists()[1][j + 3].getType())
						return false;
				}
			}
		}
		//last line
		if (j >= 0 && j <= 5)
		{
			if (getMaplists()[8][j].getType() == getMaplists()[8][j + 1].getType())
			{
				if ((getMaplists()[8][j].getType() == getMaplists()[8][j + 3].getType()) || (getMaplists()[8][j].getType() == getMaplists()[7][j + 2].getType()))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[8][j].getType() == getMaplists()[7][j - 1].getType())
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[8][j].getType() == getMaplists()[8][j - 2].getType()) || (getMaplists()[8][j].getType() == getMaplists()[8][j + 3].getType()) ||
						(getMaplists()[8][j].getType() == getMaplists()[7][j - 1].getType()) || (getMaplists()[8][j].getType() == getMaplists()[7][j + 2].getType()))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[8][j].getType() == getMaplists()[8][j + 1].getType())
			{
				if ((getMaplists()[8][j].getType() == getMaplists()[8][j - 2].getType()) || (getMaplists()[8][j].getType() == getMaplists()[7][j - 1].getType()))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[8][j].getType() == getMaplists()[7][j + 3].getType())
						return false;
				}
			}
		}
		//if there is a Piece between two Pieces which are the same color
		//下面用中文好了，便于叙述
		if (j <= 6)//加保险，防越界
		{
			if (getMaplists()[0][j].getType() == getMaplists()[0][j + 2].getType())
			{
				if (getMaplists()[0][j].getType() == getMaplists()[1][j + 1].getType())
					return false;
			}
			if (getMaplists()[8][j].getType() == getMaplists()[8][j + 2].getType())
			{
				if (getMaplists()[8][j].getType() == getMaplists()[7][j + 1].getType())
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
			if (getMaplists()[j][0].getType() == getMaplists()[j + 1][0].getType())
			{
				if ((getMaplists()[j][0].getType() == getMaplists()[j + 3][0].getType()) || (getMaplists()[j][0].getType() == getMaplists()[j + 2][1].getType()))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[j][0].getType() == getMaplists()[j - 1][1].getType())
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[j][0].getType() == getMaplists()[j - 2][0].getType()) || (getMaplists()[j][0].getType() == getMaplists()[j + 3][0].getType()) ||
						(getMaplists()[j][0].getType() == getMaplists()[j - 1][1].getType()) || (getMaplists()[j][0].getType() == getMaplists()[j + 2][1].getType()))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[j][0].getType() == getMaplists()[0][j + 1].getType())
			{
				if ((getMaplists()[j][0].getType() == getMaplists()[j - 2][0].getType()) || (getMaplists()[j][0].getType() == getMaplists()[j - 1][1].getType()))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[j][0].getType() == getMaplists()[j + 3][1].getType())
						return false;
				}
			}
		}
		//last list
		if (j >= 0 && j <= 5)
		{
			if (getMaplists()[j][8].getType() == getMaplists()[j + 1][8].getType())
			{
				if ((getMaplists()[j][8].getType() == getMaplists()[j + 3][8].getType()) || (getMaplists()[j][8].getType() == getMaplists()[j + 2][7].getType()))
					return false;
				else if (j == 1)
				{
					if (getMaplists()[j][8].getType() == getMaplists()[j - 1][7].getType())
						return false;
				}
				else if (j > 1)//normal suition
				{
					if ((getMaplists()[j][8].getType() == getMaplists()[j - 2][8].getType()) || (getMaplists()[j][8].getType() == getMaplists()[j + 3][8].getType()) ||
						(getMaplists()[j][8].getType() == getMaplists()[j - 1][7].getType()) || (getMaplists()[j][8].getType() == getMaplists()[j + 2][7].getType()))
						return false;
				}
			}
		}
		else if (j == 6 || j == 7)
		{
			if (getMaplists()[j][8].getType() == getMaplists()[j + 1][8].getType())
			{
				if ((getMaplists()[j][8].getType() == getMaplists()[j - 2][8].getType()) || (getMaplists()[j][8].getType() == getMaplists()[j - 1][7].getType()))
					return false;
				else if (j == 6)
				{
					if (getMaplists()[j][8].getType() == getMaplists()[j + 3][7].getType())
						return false;
				}
			}
		}
		//if there is a Piece between two Pieces which are the same color
		//下面用中文好了，便于叙述
		if (j <= 6)//加保险，防越界
		{
			if (getMaplists()[j][0].getType() == getMaplists()[j + 2][0].getType())
			{
				if (getMaplists()[j][0].getType() == getMaplists()[j + 1][1].getType())
					return false;
			}
			if (getMaplists()[j][8].getType() == getMaplists()[j + 2][8].getType())
			{
				if (getMaplists()[j][8].getType() == getMaplists()[j + 1][7].getType())
					return false;
			}
		}
	}
	return true;
}

//Maplists
std::deque<Piece> * Map::getMaplists()
{
	return maplists;
}
