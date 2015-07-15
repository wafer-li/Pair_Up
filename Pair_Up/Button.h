#ifndef __BUTTON__
#define __BUTTON__
#include"graphics15.h"
#include<iostream>
#include"Global.h"
#include"Time.h";
class Button
{
private:
	static int button_x[20];       //按钮起始点横坐标
	static int button_y[20];       //按钮起始点纵坐标
	static int button_R[20];       //按钮按下后的返回值
	static int button_w[20];       //按钮区域宽度
	static int button_h[20];       //按钮区域高度
	static int button_i;           //按钮数量
	static PIMAGE button_P[20];    //按钮常态源图   
	static PIMAGE button_P2[20];   //按钮选中态源图
	static PIMAGE button_P3[20];   //按钮按下态源图
	static PIMAGE button_RP;       //按钮输出前的原图
	static PIMAGE button_allP;      //按钮全部输出图
	static PIMAGE button_M[20];    //选中状态截图
	static PIMAGE button_O[20];     //按下状态截图
	static PIMAGE chose;           //红框截图
	static int cho;   //用于选中判断
public:
	
	Button(int startx, int starty, int wide, int high, int Return, PIMAGE p, PIMAGE p2, PIMAGE p3);//按钮起始点的横坐标 纵坐标 宽度 高度 常态图 选中图 点击图
	Button(int startx, int starty, int wide, int high, int Return, PIMAGE p);//方框模式
	~Button(void);
	static int setbutton(int startx, int starty, int wide, int high);//执行函数的范围起始点X,Y,宽度，高度，执行前的截图 ，该函数会对图片进行整理且将按钮常态输出到屏幕
	static int pubutton(int startx, int starty, int wide, int high);//执行函数的范围起始点X,Y,宽度，高度，
	static int pubutton(int startx, int starty, int wide, int high,int rectangle_);  //rectangle_是无用参数只用于区分三态模式与方框模式
	static int pubutton(int startx, int starty, int wide, int high, Time&time, PIMAGE bg);  //rectangle_是无用参数只用于区分三态模式与方框模式(无红框);
		
};
#endif;