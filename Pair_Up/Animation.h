#ifndef __ANIMATION__
#define __ANIMATION__
#include"graphics15.h"
#include<iostream>
#include"Map.h"
#include"Global.h"
class Animation
{
private:
	 int x[9][9];
	 int y[9][9];
	//static int R[10];
	 int w;
	 int h;
	 int d[9][9];                    //掉落高度
	int m[9][9];                     //是否消除
	int k[9][9];
	 PIMAGE P[9][9];                 //方块图
	 PIMAGE BP[9][9];                //格子图
	 PIMAGE BG;                      // 背景
	 PIMAGE TYPE[6];                 //所有普通方块素材图片
	 PIMAGE STYPE[2];                //特殊方块图片
	 int d_add[9];
public:
	Animation();
	Animation(int startx, int starty, int wide, int high, Map map);                      //游戏区域起始点的横坐标 纵坐标 素材宽度 高度 Map
	~Animation();
	
	int puanimation(int aa, int bb, int cc, int dd, Map&oriMap);                        //执行游戏功能的范围起始点X,Y,宽度，高度，
	int animation_change(int i_, int n, int aa, int bb, int cc, int dd, Map&oriMap);
	  int animation_restore(int i1, int n1, int i2, int n2);
	 int animation_move(int i1, int n1, int i2, int n2);
	 int animation_disappear(Map&oriMap);
	 int animation_fall(Map&oriMap);
	 int animation_add(void);
	 int animation_add(Map&oriMap);
	 int animation_newmap(Map&oriMap);
};
#endif;