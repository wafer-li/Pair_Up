-//------------READ-ME--------------------------------------------
-//标记nedOPT的地方意味着需要优化
-//标记+的地方意味着需要添加
-//Update7-7: 现已确定方块的属性是 Piece.type		(0，6]    match to six different piece basic type
-//			 特殊方块：			Piece.specType	[0，6]	  match to seven different piece addition type
-//			specType:			0.ori	1.line	2.row	3.box	4.same_color	5.unclear	6.death
-//Update7-7:Please add getter and setter for your class :D
-//Update7-7:Please change your function name to match main function as possible~ 
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
Map g_C_P_S_R(Map oriMap);

int main(int argc, char*argv[])
{
	meun(mouseCheck.meun);
}
int init(void)
{
	srand((unsigned)time(0));
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
			condition = recordMode();
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

int recordMode()
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
	int isMapDead = 0;//bool
	int isExpMax = 0;//bool
	Map newmap;

	g_makeMap();//Lht+Tgf+Hjy
	isMapDead = g_isDead();//Lht
	while (restOfLive){
		//if(pair_Up)
		//+if(button.exit_inGame())
		if (g_pauseGame()){}
		else{
			if (isMapDead)
				g_makeMap();
			else{
				newMap = g_playerMove();//g_playerMove()->Lds -> Lc //"="need of operator overlording
				g_C_P_S_R(newMap);
				//+isExpMax();
				//nedOPT:in loops,this function"isMapDead"will carry out twice with one loop
				//Update7-7:slove
				isMapDead = g_isDead();
				if (isMapDead)
					--restOfLive;
				}
		}

	}
}

Map g_C_P_S_R (Map oriMap)
{			//newMap[g_game] -> oriMap[g_C_P_S_R]
			g_checkPair(oriMap);//Lc 

			g_pairUp();//Lc + Lds

			g_setMap();//Lht+Lds+Hjy+Tgf

			g_replenishMap();//Tgf//book
}

Map g_playerMove(Map)
{
   // + Lds's function
}