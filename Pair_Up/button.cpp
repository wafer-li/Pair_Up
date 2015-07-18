#include"button.h"
int Button::button_x[20] = {0};
int Button::button_y[20] = { 0 };
int Button::button_w[20] = { 0 };
int Button::button_h[20] = { 0 };
int Button::button_R[20] = { 0 };
int Button:: button_i = 0;
PIMAGE Button::button_P[20] = { NULL }; 
PIMAGE Button::button_P2[20] = { NULL};
PIMAGE Button::button_P3[20] = { NULL };
PIMAGE Button::button_RP =  NULL ;
PIMAGE Button::button_allP = { NULL };
PIMAGE Button::button_M[20] = { NULL };
PIMAGE Button::button_O[20] = { NULL };
PIMAGE Button::chose = NULL;
int Button::cho = 0;
MUSIC Button::music_button_o;
MUSIC Button::music_button_m;
Button::Button(int startx, int starty, int wide, int high, int Return, PIMAGE p, PIMAGE p2, PIMAGE p3) //起始点的横坐标 纵坐标 宽度 高度 常态图 选中图 点击图
{
	button_x[button_i] = startx;
	button_y[button_i] = starty;
	button_R[button_i] = Return;
	button_w[button_i] = wide;
	button_h[button_i] = high;
	button_P[button_i] = p;
	button_P2[button_i] = p2;
	button_P3[button_i] = p3;
	music_button_m.OpenFile("resource//button_m.wav");
	music_button_o.OpenFile("resource//button_o.mp3");
	if (button_i == 0)
	{
		button_RP = newimage();
		getimage(button_RP, Global::x_0, Global::y_0, Global::x_scr, Global::y_scr);
	}
	button_i++;
	//putimage_transparent(NULL, p, startx, starty, BLACK);


}
Button::Button(int startx, int starty, int wide, int high, int Return, PIMAGE p) //起始点的横坐标 纵坐标 宽度 高度 常态图 选中图 点击图
{
	button_x[button_i] = startx;
	button_y[button_i] = starty;
	button_R[button_i] = Return;
	button_w[button_i] = wide;
	button_h[button_i] = high;
	button_P[button_i] = p;
	button_P2[button_i] = p;
	button_P3[button_i] = p;
	if (button_i == 0)
	{
		button_RP = newimage();
		getimage(button_RP, Global::x_0, Global::y_0, Global::x_scr, Global::y_scr);
	}
	button_i++;
	//putimage_transparent(NULL, p, startx, starty, BLACK);


}
Button::~Button()
{
	int j = 0;
	for (j = 0; j < 20; j++)
	{
		button_x[j] = 0;
		button_y[j] = 0;
		button_w[j] = 0;
		button_h[j] = 0;
		button_R[j] = 0;
	}
	cho = 0;
	button_i--;
	delimage(button_M[button_i]);
	delimage(button_O[button_i]);

	if (button_i == 0)
	{
		delimage(button_allP);
		delimage(button_RP);


	}
	
}
int Button::setbutton(int startx, int starty, int wide, int high)//执行函数的范围起始点X,Y,宽度，高度,     /*本函数将按钮三态图整合到背景上并重新保存图片以减少输出图片的次数*/
{
	int k = 0;
	int nn = 0;
	int uu = 0;

	putimage(startx, starty, wide, high, button_RP, startx,starty);      //输出按钮执行区域原图
	 button_allP = newimage();



	for (nn = 0; nn <button_i; nn++)                          //将选中态和按下态整合到原图上重新保存
	{
		button_M[nn] = newimage();
		button_O[nn] = newimage();
		getimage(button_M[nn], startx, starty, wide, high);
		getimage(button_O[nn], startx, starty, wide, high);

		for (uu = 0; uu <button_i; uu++){
			if (uu != nn){
				putimage_transparent(button_M[nn], button_P[uu], button_x[uu], button_y[uu], BLACK);
				putimage_transparent(button_O[nn], button_P[uu], button_x[uu], button_y[uu], BLACK);
			}

		}
		putimage_transparent(button_M[nn], button_P2[nn], button_x[nn], button_y[nn], BLACK);
		putimage_transparent(button_O[nn], button_P3[nn], button_x[nn], button_y[nn], BLACK);


	}

	for (nn = 0; nn < button_i; nn++)
	{ 
		putimage_transparent(NULL, button_P[nn], button_x[nn], button_y[nn], BLACK);           //将常态输出到背景上
	}

	getimage(button_allP, startx, starty, wide, high);                   //将常态图保存

	return 0;
}
int Button::pubutton(int startx, int starty, int wide, int high)//执行函数的范围起始点X,Y,宽度，高度
{
	int k = 0;
	int nn = 0;
	int uu = 0;
	mouse_msg mouse;
	
	flushmouse();
	for (;;)
	
	{

		mouse = getmouse();
		
		putimage(startx, starty, button_allP);
		
		if (!((mouse.x <= (startx + wide)) && (mouse.x >= startx) && (mouse.y <= (starty + high)) && (mouse.y >= starty)))
		{
			putimage(startx, starty, button_allP);
			break;//鼠标范围不在执行区域时退出
		}
		for (nn = 0; nn < 10&&(k==0); nn++){

			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){
				
				putimage(startx, starty, button_M[nn]);
				music_button_m.Play(0);
			//按钮选中状态
				//playmusic(A);   选中效果音
			}
		}

		if (mouse.is_left())k++;
		for ( nn = 0; nn< 10 &&( k == 1); nn++){
			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] &&mouse.y >= button_y[nn]){
				putimage(startx, starty, button_O[nn]);
				//按钮按下状态
				
			}
		}
		if (k==2){
			for ( nn = 0; nn < 10; nn++){
				
				if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn])
				{
					music_button_o.Play(0);
					// playmusic(B); 按键效果音
					return button_R[nn];//松开按钮后返回值
				}
			}
			return 0;
		}
		
	}
	
	return 0;
}
int Button::pubutton(int startx, int starty, int wide, int high,Time&time,PIMAGE bg)//执行函数的范围起始点X,Y,宽度，高度
{
	int k = 0;
	int nn = 0;
	int uu = 0;
	mouse_msg mouse;
	int clock = 0;

	setcolor(WHITE); 
	flushmouse();
	for (;;)

	{
		for (; !mousemsg();)
		{
		
			putimage(0, 200, 510, 100, bg, 0, 200);
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:");
			xyprintf(70, 250, "%d", clock);      //鼠标不动时时间变动
			if (clock <= 0){
				flushmouse();
				return 1;
			}
		}
		mouse = getmouse();
		putimage(startx, starty, button_allP);

		if (!((mouse.x <= (startx + wide)) && (mouse.x >= startx) && (mouse.y <= (starty + high)) && (mouse.y >= starty)))
		{
			putimage(startx, starty, button_allP);
			break;//鼠标范围不在执行区域时退出
		}
		for (nn = 0; nn < 20 && (k == 0); nn++){

			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){

				
				rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);
				//按钮选中状态
				//playmusic(A);   选中效果音
			}
		}

		if (mouse.is_left())k++;
		for (nn = 0; nn< 20 && (k == 1); nn++){
			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){
				
				rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);
				//按钮按下状态

			}
		}
		if (k == 2){
			for (nn = 0; nn < 10; nn++){

				if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn])
				{// playmusic(B); 按键效果音
					
				


					return button_R[nn];//松开按钮后返回值
				}
			}
			return 0;
		}

	}

	return 0;
}
int Button::pubutton(int startx, int starty, int wide, int high, int rectangle_)//执行函数的范围起始点X,Y,宽度，高度，方框模式
{
	int k = 0;
	int nn = 0;
	int uu = 0;
	mouse_msg mouse;

	flushmouse();

	for (;;)

	{

		mouse = getmouse();
		if (cho == 0)putimage(startx, starty, button_allP);
		if (cho == 1)putimage(startx, starty, chose);

		if (!((mouse.x <= (startx + wide)) && (mouse.x >= startx) && (mouse.y <= (starty + high)) && (mouse.y >= starty)))
		{
			if (cho == 0)putimage(startx, starty, button_allP);
			if (cho == 1)putimage(startx, starty, chose);
			break;//鼠标范围不在执行区域时退出
		}
		for (nn = 0; nn < 20 && (k == 0); nn++){

			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){
				setcolor(WHITE);
				if (cho == 0)putimage(startx, starty, button_allP);
				if (cho == 1)putimage(startx, starty, chose);
				rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);
				//按钮选中状态
				//playmusic(A);   选中效果音
			}
		}

		if (mouse.is_left())k++;
		for (nn = 0; nn< 20 && (k == 1); nn++){
			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){
				putimage(startx, starty, button_allP);
				setcolor(RED);
				rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);

				//按钮按下状态

			}
		}
		if (k == 2){
			for (nn = 0; nn < 20; nn++){

				if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn])
				{// playmusic(B); 按键效果音
					putimage(startx, starty, button_allP);
					setcolor(RED);
					rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);
					delimage(chose);
					chose = newimage();
					getimage(chose, startx, starty, wide, high);
					cho = 1;



					return button_R[nn];//松开按钮后返回值
				}
			}
			return 0;
		}

	}

	return 0;
}