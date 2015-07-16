#include "Global.h"
//___________________Coordinate_Common___________________
const int Global::x_scr = 1476;
const int Global::y_scr = 1016;
const int Global::x_0 = 0;
const int Global::y_0 = 0;

//__________________Coordinate_Game____________________
const int Global::x_map = 900;
const int Global::y_map = 900;
const int Global::x_piece = 100;
const int Global::y_piece = 100;
const int Global::x_g_b_exit = 327;
const int Global::y_g_b_exit = 802;
const int Global::x_g_b_pause = 85;
const int Global::y_g_b_pause = 802;
//L:left T:top B:botton
const int Global::x_map_LT = 519;
const int Global::x_map_LB = 519;
const int Global::y_map_LT = 52;
const int Global::y_map_LB = 952;
const int Global::MAX_SIZE = 9;		//The max size of map line & row contain object

//__________________Coordinate_Menu___________________________

//_________________Delay_____________________________________
const int Global::delay_fall= 50000;            //fps
const int Global::delay_add = 60000;             //fps
const int Global::delay_change = 24000;          //fps
const int Global::delay_disappear = 200;     //ms 
const int Global::speed = 4;

//_____________________GAME_______________________

//Time
//seconds
const double Global::INIT_TIME = 60;	
const double Global::ADDTIME_L1 = 30;
const double Global::ADDTIME_L2 = 40;
const double Global::ADDTIME_L3 = 50;
const double Global::ADDTIME_L4 = 60;

//PassScore
const int Global::FIRST_PASSSCORE = 1000;

Global::Global()
{
}


Global::~Global()
{
}
