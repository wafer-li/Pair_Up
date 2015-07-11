#ifndef __BUTTON__
#define __BUTTON__
#include"graphics13.h"
#include<iostream>
class Button
{
private:
	static int x[10];
	static int y[10];
	static int R[10];
	static int w[10];
	static int h[10];
	static int i;
	static PIMAGE P[10];
	static PIMAGE P2[10];
	static PIMAGE P3[10];
public:
	
	Button(int startx, int starty, int wide, int high, int Return, PIMAGE p, PIMAGE p2, PIMAGE p3);//按钮起始点的横坐标 纵坐标 宽度 高度 常态图 选中图 点击图
	~Button(void);
	
	static int pubutton(int aa, int bb, int cc, int dd,PIMAGE BK);//执行函数的范围起始点X,Y,宽度，高度，执行前的截图

		
};
#endif;