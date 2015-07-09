//this file include function for UI to Datebase

#ifndef GAMEMODE_H
#define GAMEMODE_H
#include"Map.h"

//gameMode entrance
void g_game(viod);

//swap two Piece
void swapPiece(int x1, int y1, int x2, int y2, Map& map);

//judge the Map for clearable(you can use it anywhere but not effecient)
bool g_checkMap(Map & map);

//judge the Map for clearable(more effeciently, but more parameters)
bool g_checkMap(int index_x1, int index_y1, int index_x2, int index_y2, Map & theMap);

void g_P_S_R(Map& oriMap)
{
	//newMap[g_game] -> oriMap[g_C_P_S_R]

	g_pairUp();//消除//Lc + Lds

	//g_setMap();//掉落//Lht+Lds+Hjy+Tgf

	g_replenishMap();//Push_back//Tgf//book
}

void g_playerMove(Map& oriMap)
{

	/*
	1.用户点下去
	2.拖动-播放动画
	|-不合法
	|-合法-Map 交换数据(int,int,int,int,Map&)-bool g_checkMap(Map)-
	|-不可消除-换回数据-播放动画
	|-可消除-g-P-S-R-
	*/
}

Map g_makeMap()
{
	//Map *newMap = new Map();
	Map newmap;
	return newmap;
}

void g_deleteMap(Map& deadMap);
#endif