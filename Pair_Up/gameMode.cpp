#include "gameMode.h"

//gameMode entrance
void g_game()
{	
	//initialize font
	setfont(-40, -20, "Cute");
	setbkmode(TRANSPARENT);
	setcolor(EGERGB(255,255,255));
	//partial variable
	//Piece.type means basic elements of piece
	//Piece.specType means special piece 
	int restOfLive = 6; //初始生命值
	int exit_sign = 0;
	bool isDeadMap = false;
	bool isExpMax = false;
	bool pauseGame = false;

	Option option;
	Map & newMap = g_makeMap();
	Animation* newAnimation = new Animation(option, newMap);
	PIMAGE p_button_back = newimage();
	PIMAGE p_button_stop = newimage();
	getimage(p_button_back,"resource\\g_ctn.png" , 0, 0);
	getimage(p_button_stop, "resource\\g_Exit.png", 0, 0);
	Button* button_stop = new Button(150, 700, 100, 100, 1, p_button_stop);
	Button* button_back = new Button(300, 700, 100, 100, 2, p_button_back);

	Button::setbutton(0, 650, 520, 200);


	newAnimation->animation_add();


	Score score;
	Time time;

	while (restOfLive)
	{
		isDeadMap = newMap.g_isDeadMap();
		//+if(button.exit_inGame())

			if (isDeadMap)
			{
				if (!time.isStop())
				{
					time.pauseTime();
				}
				g_deleteMap(newMap);
				Map & newMap = g_makeMap();
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


				//Judge and Disappear loop
				for (int combo = 1; g_checkMap(newMap) == 1; combo++)
				{
					int removeNum = 0;

					clearPiece(newMap);

					newAnimation->animation_disappear(newMap);
					removeNum = g_P_S_R(newMap);

					//Change score & level and add time
					score.changeScore(removeNum, combo);
					while (score.levelUp())
					{
						time.addTime(score);
						continue;
					}

					newAnimation->animation_fall_add(newMap, score, combo);
				}

				isDeadMap = newMap.g_isDeadMap();
				if (!isDeadMap)
				{
					if (time.isStop())
					{
						time.resumeTime();
					}
					exit_sign = newAnimation->puanimation(519, 52, 519 + 900, 52 + 900, newMap, time);
					time.pauseTime();
					if (exit_sign)
					{
						break;
					}
				}
				else
				{
					restOfLive--;
				}

				//+isExpMax();
			}
		}
	l_inRanking(score.getScore());//Record score, disaplay in leaderboard if the top five
	delete button_stop;
	delete button_back;

}

//swap two Piece
void swapPiece(int x1, int y1, int x2, int y2, Map& map)
{
	map.swap(x1, y1, x2, y2);
}

//Judge the Map for clearable
//Judge the whole map
//Do NOT change the Piece.isClearable
//Origin editor: Jushe
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

int g_P_S_R(Map& oriMap)
{
	int removeNum = 0;

	removeNum = g_PairUp(oriMap);
	g_replenishMap(oriMap);//Push_back//Tgf//book

	return removeNum;
}
Map & g_makeMap()
{
	Map *myMap = new Map();
	Map &newMap = *myMap;
	//Map newmap;
	return newMap;
}
int g_PairUp(Map& oriMap)
{
	return(removePiece(oriMap));
}

void g_replenishMap(Map& oriMap)
{
	repairPiece(oriMap);
}

void g_deleteMap(Map& deadMap)
{
	delete &deadMap;
}
