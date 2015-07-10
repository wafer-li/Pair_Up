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
				}
				else if (k > 2)//之后的k每次都比2大，此时新增方块必定同色
				{
					map.maplists[i][j].setIsClear(1);
				}
				if (j == 8)//防止第8和第9块同色时，继续比较而造成越界
					break;
				if (map.maplists[i][j].getType() == map.maplists[i][j + 1].getType())//方块检查后j++调整j值
					j++;
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
				}
				else if (k > 2)
				{
					map.maplists[j][i].setIsClear(1);
				}
				if (j == 8)
					break;
				if (map.maplists[j][i].getType() == map.maplists[j + 1][i].getType())//color 的判断方法有待斟酌
					j++;
				else
					break;
			}
		}
	}
}

//NEED TO FIX: ERASE SINGLE ITEM IN ON TURN, CAUSE THE **OUT OF RANGE** EXCEPTION
//may be fixed
//RemovePiece
int removePiece(Map & map)
{
	int count = 0;

	for (int i = 0; i < map.MAX_SIZE; i++)
	{
		for (int j = 0; j < map.maplists[i].size(); j++)
		{
			std::deque<Piece>::iterator p = map.maplists[i].begin();

			for (int k = 0; k < j; k++)
			{
				p++;
			}

			if (map.maplists[i][j].getIsClear())
			{
				p = map.maplists[i].erase(p);
				count++;
			}
		}
	}
	return count;
}

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