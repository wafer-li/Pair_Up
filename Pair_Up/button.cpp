#include"button.h";
int Button::x[10] = {0};
int Button::y[10] = { 0 };
int Button::w[10] = { 0 };
int Button::h[10] = { 0 };
int Button::R[10] = { 0 };
int Button:: i = 0;
PIMAGE Button::P[10] = { NULL }; 
PIMAGE Button::P2[10] = { NULL};
PIMAGE Button::P3[10] = { NULL };
Button::Button(int startx, int starty, int wide, int high, int Return, PIMAGE p, PIMAGE p2, PIMAGE p3) //起始点的横坐标 纵坐标 宽度 高度 常态图 选中图 点击图
{
	x[i] = startx;
	y[i] = starty;
	R[i] = Return;
	w[i] = wide;
	h[i] = high;
	P[i] = p;
	P2[i] = p2;
	P3[i] = p3;
	i++;
	//putimage_transparent(NULL, p, startx, starty, BLACK);


}
Button::~Button()
{
	i--;
	
}
int Button::pubutton(int aa,int bb,int cc,int dd,PIMAGE BK)//执行函数的范围起始点X,Y,宽度，高度，执行前的截图
{
	int k = 0;
	int nn = 0;
	mouse_msg a;
	PIMAGE q = BK;
	
	for (;;)
	{
		
		a = getmouse();
		putimage(0, 0, q);
		for ( nn = 0; nn < i; nn++)
		{
			putimage_transparent(NULL, P[nn], x[nn], y[nn], BLACK);//按钮常态
		}
		if (!(a.x <= cc&&a.x >= aa&&a.y <= dd&&a.y >= bb))break;//鼠标范围判断
		for (int n = 0; n < 10&&k==0; n++){

			if (a.x <= x[n] + w[n] && a.x >= x[n] && a.y <= y[n] + h[n] && a.y >= y[n]){
				putimage(0, 0, q);
				for ( nn = 0; nn < i; nn++)
				{
					if (nn != n)putimage_transparent(NULL, P[nn], x[nn], y[nn], BLACK);
				}
				putimage_transparent(NULL, P2[n], x[n], y[n], BLACK);//按钮选中状态
				//playmusic(A);   选中效果音
			}
		}

		if (a.is_left())k++;
		for (int n = 0; n < 10 && k == 1; n++){
			if (a.x <= x[n] + w[n] && a.x >= x[n] && a.y <= y[n] + h[n] && a.y >= y[n]){
				putimage(0, 0, q);
				for (nn = 0; nn < i; nn++)
				{
					if (nn != n)putimage_transparent(NULL, P[nn], x[nn], y[nn], BLACK);
				}
				putimage_transparent(NULL, P3[n], x[n], y[n], BLACK);//按钮按下状态
				
			}
		}
		if (k==2){
			for (int n = 0; n < 10; n++){
				
				if (a.x <= x[n] + w[n] && a.x >= x[n] && a.y <= y[n] + h[n] && a.y >= y[n])
				{// playmusic(B); 按键效果音
					
					return R[n];//松开按钮后返回值
				}
			}
			return 0;
			k = 0;
		}
		
	}
	return 0;
}