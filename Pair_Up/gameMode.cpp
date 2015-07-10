#include "gameMode.h"
#include "optionMode.h"
#include "leaderboardMode.h"
//gameMode entrance
void g_game()
{
	//partial variable
	//Piece.type means basic elements of piece
	//Piece.specType means special piece 
	int restOfLive = 6; //初始生命值
	int score = 0;
	bool isDeadMap = false;
	bool isExpMax = false;
	bool pauseGame = false;

	Map newMap = g_makeMap();
	isDeadMap = newMap.g_isDeadMap();
	
	//NEED TO FIX: THE INFINITY LOOP!!!
	while (restOfLive){
		//if(pair_Up)
		//+if(button.exit_inGame())
		if (pauseGame){}
		else{
			g_checkMap(newMap);
			if (removePiece(newMap) == 0)
			{
				if (isDeadMap)
				{
					g_deleteMap(newMap);
					Map newmap = g_makeMap();
				}
				else
				{
					g_playerMove(newMap);//g_playerMove()->Lds -> Lc //"="need of operator overlording
					/*
					1.用户点下去
					2.拖动-播放动画
					|-不合法
					|-合法-Map 交换数据(int,int,int,int,Map&)-bool g_checkMap(Map)-
					|-不可消除-换回数据-播放动画
					|-可消除-g-P-S-R-
					*/

					g_checkMap(newMap);//Lc

					g_P_S_R(newMap);
					//+isExpMax();
					//nedOPT:in loops,this function"g_isDeadMap"will carry out twice with one loop
					//Update7-7:slove
					isDeadMap = newMap.g_isDeadMap();
					if (isDeadMap)
					{
						--restOfLive;
					}
				}
			}
			else
			{
				g_P_S_R(newMap);
				//+isExpMax();
			}
		}
	}
	l_inRanking(score);//record Game score,if the score is at the top 10 of leaderboard, congratulations and refresh the learboard
}

//swap two Piece
void swapPiece(int x1, int y1, int x2, int y2, Map& map)
{
	map.swap(x1, y1, x2, y2);
}

//judeg the Map for clearable
//this function is not efficient, it would be more quickly if I can get the changed Pieces' index
bool g_checkMap(Map & map)
{
	//行检查
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)//k = 2意味着出现三个一块
				{
					return true;
				}
				if (j == 8)//防止第8和第9块同色时，继续比较而造成越界
					break;
				if (map.getMaplists()[i][j].getType() == map.getMaplists()[i][j + 1].getType())//方块检查后j++调整j值
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
					return true;
				}
				if (j == 8)
					break;
				if (map.getMaplists()[j][i].getType() == map.getMaplists()[j + 1][i].getType())
					j++;
				else
					break;
			}
		}
	}
	return false;
}

//judege the Map for clearable(more effeciently but you need to tell me the Pieces' index which are changed)
bool g_checkMap(int index_x1, int index_y1, int index_x2, int index_y2, Map & theMap)
{
	return (theMap.isPieceClearable(index_x1, index_y1) || theMap.isPieceClearable(index_x2, index_y2));
}

void g_P_S_R(Map& oriMap)
{
	//newMap[g_game] -> oriMap[g_P_S_R]

	g_PairUp(oriMap);
	//g_setMap();

	g_replenishMap(oriMap);//Push_back//Tgf//book
}
Map g_makeMap()
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