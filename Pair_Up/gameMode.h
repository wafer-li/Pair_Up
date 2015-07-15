//this file include function for UI to Datebase

#ifndef GAMEMODE_H
#define GAMEMODE_H

//Include Part
#include"Map.h"
#include"Animation.h"
#include"Global.h"
#include "Score.h"
#include "optionMode.h"
#include "leaderboardMode.h"
#include "Time.h"

//gameMode entrance
void g_game();

//swap two Piece
void swapPiece(int x1, int y1, int x2, int y2, Map& map);

//judge the Map for clearable(you can use it anywhere but not effecient)
bool g_checkMap(Map & map);

//judge the Map for clearable(more effeciently, but more parameters)
bool g_checkMap(int index_x1, int index_y1, int index_x2, int index_y2, Map & theMap);

//Binding : Pair up,clear the Map,and replenish it
int g_P_S_R(Map&);

//create a new map
Map & g_makeMap();

//Ïû³ý
int g_PairUp(Map&);

//²¹³ädeque
void g_replenishMap(Map&);

//É¾³ýËÀÍ¼
void g_deleteMap(Map& deadMap);

#endif