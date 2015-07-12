//The FRIEND function of Map
#include "Map.h"

//clearPiece
void clearPiece(Map & map){
	//行检查
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)//k = 2意味着首次出现三个一块
				{
					map.maplists[i][j].setIsClear(1);
					map.maplists[i][j - 1].setIsClear(1);
					map.maplists[i][j - 2].setIsClear(1);
					deal_SpecPiece(i, j, map);
					deal_SpecPiece(i, j - 1, map);
					deal_SpecPiece(i, j - 2, map);
				}
				else if (k > 2)//之后的k每次都比2大，此时新增方块必定同色
				{
					map.maplists[i][j].setIsClear(1);
					deal_SpecPiece(i, j, map);
				}
				if (j == 8)//防止第8和第9块同色时，继续比较而造成越界
					break;
				if (map.maplists[i][j].getType() == map.maplists[i][j + 1].getType())//方块检查后j++调整j值
				{
					j++;
					if (map.maplists[i][j].getSpecType() == 5)
					{
						break;
					}
				}
				else
					break;//若方块颜色不对，那么不进行上述的状态调整过程
			}
		}
	}
	//列检查：方式相同
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)
				{
					map.maplists[j][i].setIsClear(1);
					map.maplists[j - 1][i].setIsClear(1);
					map.maplists[j - 2][i].setIsClear(1);
					deal_SpecPiece(j, i, map);
					deal_SpecPiece(j - 1, i, map);
					deal_SpecPiece(j - 2, i, map);
				}
				else if (k > 2)
				{
					map.maplists[j][i].setIsClear(1);
					deal_SpecPiece(j, i, map);
				}
				if (j == 8)
					break;
				if (map.maplists[j][i].getType() == map.maplists[j + 1][i].getType())//color 的判断方法有待斟酌
				{
					j++;
					if (map.maplists[j][i].getSpecType() == 5)
					{
						break;
					}
				}
				else
					break;
			}
		}
	}
}

//RemovePiece
int removePiece(Map & map)
{
	int count = 0;

	for (int i = 0; i < map.MAX_SIZE; i++)
	{
		for (unsigned int j = 0; j < map.maplists[i].size(); j++)
		{
			std::deque<Piece>::iterator p = map.maplists[i].begin();

			for (unsigned int k = 0; k < j; k++)
			{
				p++;
			}

			if (map.maplists[i][j].getIsClear())
			{
				p = map.maplists[i].erase(p);
				j--;
				count++;
			}
		}
	}
	return count;
}

//WARNING:
//Please ensure to DELETE the repairNum in the stage
//RepairPiece
void repairPiece(Map & map)
{
	for (int i = 0; i < map.MAX_SIZE; i++)
	{
		while (map.maplists[i].size() < map.MAX_SIZE)
		{
			Piece piece = Piece();
			map.maplists[i].push_back(piece);
		}
	}
}

//special Piece
void deal_SpecPiece(int i, int n, Map& map)
{
	if (map.maplists[i][n].getSpecType() == 5)
	{
		map.maplists[i][n].setIsClear(0);
		return;
	}
	else if (map.maplists[i][n].getSpecType() == 1)
	{
		for (int m = 0; m < 9; m++)
		{
			if (map.maplists[m][n].getSpecType() == 5)
			{
				map.maplists[m][n].setIsClear(0);
			}
			else
			{
				if (map.maplists[m][n].getIsClear() == 1)// don not need to judge itself
				{
					continue;
				}
				else
				{
					map.maplists[m][n].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(m, n, map);
				}
			}
		}
	}
	else if (map.maplists[i][n].getSpecType() == 2)
	{
		for (int m = 0; m < 9; m++)
		{
			if (map.maplists[i][m].getSpecType() == 5)
			{
				map.maplists[i][m].setIsClear(0);
			}
			else
			{
				if (map.maplists[i][m].getIsClear() == 1)// don not need to judge itself
				{
					continue;
				}
				else
				{
					map.maplists[i][m].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i, m, map);
				}
			}
		}
	}
	else if (map.maplists[i][n].getSpecType() == 3)
	//don't need to pass a boom,because it can't back to itself;
	{
		if (i > 0)
			if (map.maplists[i - 1][n].getSpecType() == 5)
			{
				map.maplists[i - 1][n].setIsClear(0);
			}
			else
			{
				if (map.maplists[i - 1][n].getIsClear() == 1)// don not need to judge itself
				{
					// because there is no loop, so just exit the judge
				}
				else
				{
					map.maplists[i - 1][n].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i - 1, n, map);
				}
			}
		if (i < 8)
			if (map.maplists[i + 1][n].getSpecType() == 5)
			{
				map.maplists[i + 1][n].setIsClear(0);
			}
			else
			{
				if (map.maplists[i + 1][n].getIsClear() == 1)// don not need to judge itself
				{
				}
				else
				{
					map.maplists[i + 1][n].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i + 1, n, map);
				}
			}
		if (n > 0)
			if (map.maplists[i][n - 1].getSpecType() == 5)
			{
				map.maplists[i][n - 1].setIsClear(0);
			}
			else
			{
				if (map.maplists[i][n - 1].getIsClear() == 1)// don not need to judge itself
				{
				}
				else
				{
					map.maplists[i][n - 1].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i, n - 1, map);
				}
			}
		if (n < 8)
			if (map.maplists[i][n + 1].getSpecType() == 5)
			{
				map.maplists[i][n + 1].setIsClear(0);
			}
			else
			{
				if (map.maplists[i][n + 1].getIsClear() == 1)// don not need to judge itself
				{
				}
				else
				{
					map.maplists[i][n + 1].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i, n + 1, map);
				}
			}
		if ((i > 0) && (n > 0))
			if (map.maplists[i - 1][n].getSpecType() == 5)
			{
				map.maplists[i - 1][n].setIsClear(0);
			}
			else
			{
				if (map.maplists[i - 1][n].getIsClear() == 1)// don not need to judge itself
				{
				}
				else
				{
					map.maplists[i - 1][n - 1].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i - 1, n - 1, map);
				}
			}
		if ((i > 0) && (n < 8))
			if (map.maplists[i - 1][n + 1].getSpecType() == 5)
			{
				map.maplists[i - 1][n + 1].setIsClear(0);
			}
			else
			{
				if (map.maplists[i - 1][n + 1].getIsClear() == 1)// don not need to judge itself
				{
				}
				else
				{
					map.maplists[i - 1][n + 1].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i - 1, n + 1, map);
				}
			}
		if ((i < 8) && (n > 0))
			if (map.maplists[i + 1][n - 1].getSpecType() == 5)
			{
				map.maplists[i + 1][n - 1].setIsClear(0);
			}
			else
			{
				if (map.maplists[i + 1][n - 1].getIsClear() == 1)// don not need to judge itself
				{
				}
				else
				{
					map.maplists[i + 1][n - 1].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i + 1, n - 1, map);
				}
			}
		if ((i < 8) && (n < 8))
			if (map.maplists[i + 1][n + 1].getSpecType() == 5)
			{
				map.maplists[i + 1][n + 1].setIsClear(0);
			}
			else
			{
				if (map.maplists[i + 1][n + 1].getIsClear() == 1)// don not need to judge itself
				{
				}
				else
				{
					map.maplists[i + 1][n + 1].setIsClear(1);
					//if it's the special Piece
					deal_SpecPiece(i + 1, n + 1, map);
				}
			}
	}
	else if (map.maplists[i][n].getSpecType() == 4)
	{
		for (int index_x = 0; index_x < 9; index_x++)
		{
			for (int index_y = 0; index_y < 9; index_y++)
			{
				if (map.maplists[index_x][index_y].getType() == map.maplists[i][n].getType())
				{
					if (map.maplists[index_x][index_y].getSpecType() == 5)
					{
						map.maplists[index_x][index_y].setIsClear(0);
					}
					else
					{
						if (map.maplists[index_x][index_y].getIsClear() == 1)// don not need to judge itself
						{
							continue;
						}
						else
						{
							map.maplists[index_x][index_y].setIsClear(1);
							//if it's the special Piece
							deal_SpecPiece(index_x, index_y, map);
						}
					}
				}
			}
		}
	}
}


//caculate the movePoint for each Piece
void movePoint(Map& map)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (map.maplists[i][j].getIsClear() == 1)
			{
				for (int n = j - 1; n != 0; n--)
				{
					map.maplists[i][n].setMovePoint(map.maplists[i][n].getMovePoint() + 1);
				}
			}
		}
	}
	return;
}

//initialize the movePoint
void init_movePoint(Map& map)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			map.maplists[i][j].setMovePoint(0);
		}
	}
}