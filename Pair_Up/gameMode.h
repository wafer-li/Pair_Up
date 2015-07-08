//this file include function for UI to Datebase

#ifndef GAMEMODE_H
#define GAMEMODE_H
#include"Map.h"
//swap two Piece
Map swapPiece(int, int, int, int, Map&);

//judege the Map for clearable(you can use it anywhere but not effecient)
bool checkMap(Map);

//judege the Map for clearable(more effeciently, but more parameters)
bool checkMap(int index_x1, int index_y1, int index_x2, int index_y2, Map theMap);

#endif