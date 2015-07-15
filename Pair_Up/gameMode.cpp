#include "gameMode.h"

//gameMode entrance
void g_game()
{
	//partial variable
	//Piece.type means basic elements of piece
	//Piece.specType means special piece 
	int restOfLive = 6; //初始生命值
	int score = 0;
	int exit_sign = 0;
	bool isDeadMap = false;
	bool isExpMax = false;
	bool pauseGame = false;
	Option option;
	Map & newMap = g_makeMap();
	isDeadMap = newMap.g_isDeadMap();
	Animation* newAnimation = new Animation(option, newMap);
	
	newAnimation->animation_add();
	while (restOfLive){
		//+if(button.exit_inGame())
		isDeadMap = newMap.g_isDeadMap();
		if (pauseGame){}
		else{
			if (isDeadMap)
			{
				restOfLive--;
				g_deleteMap(newMap);
				Map newmap = g_makeMap();
				newAnimation->animation_newmap(newMap);
			}
			else
			{
				/*
					1.用户点下去
					2.拖动-播放动画
					|-不合法
					|-合法-Map 交换数据(int,int,int,int,Map&)-bool g_checkMap(Map)-
					|-不可消除-换回数据-播放动画
					|-可消除-g-P-S-R-
					*/

				
				for (; g_checkMap(newMap) == 1;)
				{

					clearPiece(newMap);

					newAnimation->animation_disappear(newMap);


					g_P_S_R(newMap);
					newAnimation->animation_fall_add(newMap);
				}

				isDeadMap = newMap.g_isDeadMap();
				if (!isDeadMap)
				{
					exit_sign = newAnimation->puanimation(0, 0, Global::x_scr, Global::y_scr, newMap);

				}

				//+isExpMax();
			}
		}
	}
	l_inRanking(score);//Record score, disaplay in leaderboard if the top five
}

//swap two Piece
void swapPiece(int x1, int y1, int x2, int y2, Map& map)
{
	map.swap(x1, y1, x2, y2);
}

//Judge the Map for clearable
//Judge the whole map
//Do NOT change the Piece.isClearable

//bool g_checkMap(Map & map)
//{
//	//行检查
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			for (int k = 0;; k++)
//			{
//				if (k == 2)//k = 2意味着出现三个一块
//				{
//					return true;
//				}
//				if (j == 8)//防止第8和第9块同色时，继续比较而造成越界
//					break;
//				if (map.getMaplists()[i][j].getType() == map.getMaplists()[i][j + 1].getType())//方块检查后j++调整j值
//				{
//					j++;
//					if (map.getMaplists()[i][j].getSpecType() == 5)//这里也进行了特殊方块检查
//					{
//						break;
//					}
//				}
//				else
//					break;//若方块颜色不对，那么不进行上述的状态调整过程
//			}
//		}
//	}
//	//列检查：方式相同
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			for (int k = 0;; k++)
//			{
//				if (k == 2)
//				{
//					return true;
//				}
//				if (j == 8)
//					break;
//				if (map.getMaplists()[j][i].getType() == map.getMaplists()[j + 1][i].getType())
//				{
//					j++;
//					if (map.getMaplists()[i][j].getSpecType() == 5)//这里也进行了特殊方块检查
//					{
//						break;
//					}
//				}
//				else
//					break;
//			}
//		}
//	}
//	return false;
//}

//GMT+9 2015/7/13 14:30
//Rewrite by Wafer
bool g_checkMap(Map & map)
{
	for (int i = 0; i < Global::MAX_SIZE; i++)
	{
		for (int j = 0; j < Global::MAX_SIZE; j++)
		{
			if (map.isPieceClearable(i, j))
			{
				return true;
			}
		}
	}
	return false;
}

//Judgee the Map for clearable(more effeciently but you need to tell me the Pieces' index which are changed)
//GMT+9 2015/7/13 12:04, Update by Wafer
//Swap the two Piece, judge isClearable
//TRUE for Something Clearable, and do NOT Swap back
//FALSE for Something Unclearable, and Swap back
bool g_checkMap(int index_x1, int index_y1, int index_x2, int index_y2, Map & theMap)
{
	theMap.swap(index_x1, index_y1, index_x2, index_y2);
	if (theMap.isPieceClearable(index_x1, index_y1) || theMap.isPieceClearable(index_x2, index_y2))
	{
		return true;
	}
	else
	{
		theMap.swap(index_x1, index_y1, index_x2, index_y2);
		return false;
	}
}

void g_P_S_R(Map& oriMap)
{
	//newMap[g_game] -> oriMap[g_P_S_R]

	g_PairUp(oriMap);
	//g_setMap();

	g_replenishMap(oriMap);//Push_back//Tgf//book
}
Map & g_makeMap()
{	
	Map *myMap = new Map();
	Map &newMap = *myMap;
	//Map newmap;
	return newMap;
}
void g_PairUp(Map& oriMap)
{
	removePiece(oriMap);
}

void g_replenishMap(Map& oriMap)
{
	repairPiece(oriMap);
}

void g_deleteMap(Map& deadMap)
{
	delete &deadMap;
}

//return the score by the cleared number and the combo number
int g_score(int num, int com)
{
	if (num >= 3)
	{
		return int(30.0 * pow(1.5, num - 3) * com);
	}
	else
		//it is possible that just clear 2 Piece even 1 piece
		return 30;
}
