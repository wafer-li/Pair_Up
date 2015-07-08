//------------READ-ME--------------------------------------------
//标记nedOPT的地方意味着需要优化
//标记+的地方意味着需要添加
//Update7-7: 现已确定方块的属性是 Piece.type		(0，6]    match to six different piece basic type
//			 特殊方块：			Piece.specType	[0，6]	  match to seven different piece addition type
//			specType:			0.ori	1.line	2.row	3.box	4.same_color	5.unclear	6.death
//Update7-7:Please add getter and setter for your class :D
//Update7-7:Please change your function name to match main function as possible~ 
//Update7-8:对Map类请求：增添一个数据域读取消除方块的总数
//Update7-8:Map在中间删除元素后 其中的迭代器会失效，请注意在循环里重建新迭代器
//Update7-8:Map队列使用左上角为坐标原点
#include <iostream>
#include <ctime>
#include "yage.h"
#include "Map.h"
#include "Piece.h"
#include "Button.h"
//接口函数列表
//g_makeMap();
//g_isDead();
//g_playerMove();			
//g_checkPair(oriMap);
//g_pairUp();
//g_setMap();
//g_replenishMap();
//Update7-7：内容写好了我就写上面的函数..
static int g_score = 0;
void meun(int);
int init(void);
int gameMode(void);
int recordMode(void);
int optionMode(void);
int exitMode(void);
void g_game(void);
Map g_P_S_R(Map oriMap);

int main(int argc, char*argv[])
{
	init();
	meun(mouseCheck.meun);
}
int init(void)
{
	srand((unsigned)time(0));
	yage_canvas_load_image("")
		return 0;
}

void meun(int playerChoose)
{
	int condition = 1;
	while (condition)
		switch (playerChoose)
	{
		case 1:
			//start game
			condition = gameMode();
			break;
		case 2:
			//open record mode
			condition = leaderboardMode();
			break;
		case 3:
			//option
			condition = optionMode();
			break;
		case 4:
			//exit program
			condition = exitMode();
			break;
		default:
	}
}

int gameMode()
{
	g_game();
	return 1;
}

int leaderboardMode()
{
	// 7.9
	return 1;
}

int optionMode()
// 7.9
{
	return 1;
}

int exitMode()
{
	yage_quit();
	return 0;
}

void g_game()
{
	//partial variable
	//Piece.type means basic elements of piece
	//Piece.specType means special piece 
	//specType 0.None 1.Line 2.Row 3.Tre*Tre 4.UnclearAllSamePiece 5.Unclearable 6.
	int restOfLive = 6; //初始生命值
	bool isMapDead = 0;//bool
	bool isExpMax = 0;//bool


	Map newmap = g_makeMap();//Lht+Tgf+Hjy
	isMapDead = g_isDead();//Lht
	while (restOfLive){
		//if(pair_Up)
		//+if(button.exit_inGame())
		if (g_pauseGame()){}
		else{
			newMap = g_checkPair();
			if (Map.get[消除数量]() == 0)
			{
				if (isMapDead)
				{
					g_deleteMap(newMap);
					Map newmap = g_makeMap();
				}
				else
				{

					newMap = g_playerMove();//g_playerMove()->Lds -> Lc //"="need of operator overlording
					/*
					1.用户点下去
					2.拖动-播放动画
					|-不合法
					|-合法-Map 交换数据(int,int,int,int,Map&)-bool checkMap(Map)-
					|-不可消除-换回数据-播放动画
					|-可消除-g-P-S-R-
					*/

					g_checkMap(oriMap);//Lc

					g_P_S_R(newMap);
					//+isExpMax();
					//nedOPT:in loops,this function"isMapDead"will carry out twice with one loop
					//Update7-7:slove
					isMapDead = g_isDead();
					if (isMapDead)
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
	l_scoreUpdate();//record Game score,if the score is at the top 10 of leaderboard, congratulations and refresh the learboard
}

Map& g_P_S_R(Map& oriMap)
{
	//newMap[g_game] -> oriMap[g_C_P_S_R]

	g_pairUp();//消除//Lc + Lds

	//g_setMap();//掉落//Lht+Lds+Hjy+Tgf

	g_replenishMap();//Push_back//Tgf//book
}

Map& g_playerMove(Map&)
{
	/*
	1.用户点下去
	2.拖动-播放动画
	|-不合法
	|-合法-Map 交换数据(int,int,int,int,Map&)-bool checkMap(Map)-
	|-不可消除-换回数据-播放动画
	|-可消除-g-P-S-R-
	*/
}

Map g_makeMap()
{
	//Map *newMap = new Map();
	Map newmap;
	return newMap;
}

void g_deleteMap(Map& deadMap)