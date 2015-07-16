#ifndef __ANIMATION__
#define __ANIMATION__
#include"graphics15.h"
#include "Option.h"
#include"Global.h"
#include"Map.h"
#include"gameMode.h"
#include<string>
#include<sstream>
#include<iostream>
#include"Button.h"
#include "Score.h"
#include "Time.h"

class Animation
{
private:
	 int x[9][9];       //81个方块的横坐标坐标数组
	 int y[9][9];       //81个方块的纵坐标坐标数组
	 int w;             //方块宽度
	 int h;             //方块高度
	 int fall[9][9];    //原方块掉落高度
	 int fall_add[9];    //补充方块的掉落高度（按列）
	int appear[9][9];                     //是否被消除 1为不被消除
	 PIMAGE PIECE[9][9];                 //方块图
	 PIMAGE PIECE_BG[9][9];                //格子图
	 PIMAGE BG;                      // 背景
	 PIMAGE TYPE[6][6];                 //所有方块素材图片
	// PIMAGE STYPE[6][4];                //特殊方块图片
	 PIMAGE PIECE_D;                       //消除状态图
	 PIMAGE game_stop;
	 PIMAGE game_start;
	 PIMAGE game_exit;
	 PIMAGE COMBO;
	 MUSIC music_disappear;
	 MUSIC music_combo;
	 MUSIC music_bgm;
	 int lasttime;
	 int lastlevel;
	
	
public:
	Animation();
	Animation(Option opt , Map map);                
	~Animation();
	
	int puanimation(int startx, int starty, int wide, int high, Map&oriMap,Time& time);                        // startx,  starty,  wide,  high执行游戏功能的范围起始点X,Y,宽度，高度，
	int animation_change(int i1, int n1, int startx, int starty, int wide, int high, Map&oriMap,Time&time);   //i1 n1为方块下标 i1为行 n1为列
	 int animation_restore(int i1, int n1, int i2, int n2);
	 int animation_move(int i1, int n1, int i2, int n2);
	 int animation_disappear(Map&oriMap,Time&time);
	 int animation_fall(Map&oriMap);
	 int animation_add(void);
	 int animation_add(Map&oriMap);
	 int animation_newmap(Map&oriMap);
	 int animation_click(int i1,int n1, Map&oriMap,Time&time);
	 int animation_fall_add(Map&oriMap,Score& score,Time&time,int combo);
	 int animation_stop(void);
	 int animation_combo();
	 void music_stop();
	 void music_start();
};
#endif;