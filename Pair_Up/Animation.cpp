#include"Animation.h"
#include"gameMode.h"

Animation::Animation(void)
{
	int n = 0, i_ = 0;
	int w_ = 100, h_ = 100;
	PIMAGE A = newimage();
	getimage(A, "resource\\skin1\\Skin1_Piece_1_0.png", 0, 0);
	PIMAGE B = newimage();
	getimage(B, "resource\\skin1\\Skin1_Piece_3_0.png", 0, 0);
	PIMAGE C = newimage();
	getimage(C, "resource\\GBk3.png", 0, 0);

	w = w_;
	h = h_;
	BG = C;
	for (i_=0; i_ < 9;i_++)
	for (n = 0; n < 9; n++)
	{
		x[i_][n] = 519+w * n;
		y[i_][n] = 52+h * i_;
		P[i_][n] = B;
		m[i_][n] = 1;
		d[i_][n] = 0;
		if (i_ % 2){
			P[i_][n] = A;
			m[i_][n] = 0;
		}
	}
	putimage(0, 0, BG);
	for (i_ = 0; i_ < 9; i_++)
	for (n = 0; n < 9; n++)
	{
		BP[i_][n] = newimage();
		getimage(BP[i_][n], x[i_][n], y[i_][n],w, h);
	}
	for (i_ = 0; i_ < 9; i_++)
	for (n = 0; n < 9; n++)
	{
	
		putimage_transparent(NULL, P[i_][n], x[i_][n] , y[i_][n], BLACK);
	}

}
Animation::Animation(int startx, int starty, int wide, int high,Map map)
{
	int k_ = 0, i_ = 0, n_ = 0;
	/////////////////////////////初始化各种类型素材图片////////////////////////////////
	for (k_=0; k_ < 6; k_++)TYPE[k_] = newimage();
	BG = newimage();
	getimage(TYPE[0], "resource\\skin1\\Skin1_Piece_1_0.png", 0, 0);
	getimage(TYPE[1], "resource\\skin1\\Skin1_Piece_2_0.png", 0, 0);
	getimage(TYPE[2], "resource\\skin1\\Skin1_Piece_3_0.png", 0, 0);
	getimage(TYPE[3], "resource\\skin1\\Skin1_Piece_4_0.png", 0, 0);
	getimage(TYPE[4], "resource\\skin1\\Skin1_Piece_5_0.png", 0, 0);
	getimage(TYPE[5], "resource\\skin1\\Skin1_Piece_6_0.png", 0, 0);
	getimage(BG, "resource\\GBk3.png", 0, 0);
	//////////////////////////////确定每个方块的参数//////////////////////////////
	w = wide;
	h = high;
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		P[i_][n_] = TYPE[(map.getMaplists()[n_][8 - i_].getType())-1];
		x[i_][n_] = startx + w*n_;
		y[i_][n_] = starty + h*i_;
		m[i_][n_] = 1;
		d[i_][n_] = 0;
	}
	//////////////////////////////输出背景保存格子//////////////////////////////
	putimage(0, 0, BG);
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		BP[i_][n_] = newimage();
		getimage(BP[i_][n_], x[i_][n_], y[i_][n_], w, h);
	}
	//////////////////////////////输出方块//////////////////////////////////////
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{

		putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_], BLACK);
	}
	

}
Animation::~Animation()
{

}
int Animation::puanimation(int aa, int bb, int cc, int dd, Map&oriMap)
{
	
	int n = 0, i_ = 0;
	int r = 0;
	mouse_msg _a;
	int k = 0;
	int c = 0;
	PIMAGE BK__ = newimage();
	getimage(BK__, 0, 0, 1476, 1016);
	for (;;)
	{

		if (r == 1){
			putimage(0, 0, BK__);
			
			break;

		}
		_a = getmouse();
		putimage(0, 0, BK__);
	
		
		
		if (!(_a.x <= cc&&_a.x >= aa&&_a.y <= dd&&_a.y >= bb))break;
		if (_a.is_left())k++;
		
		
		for (i_ = 0; i_ < 9 &&( k %2==0); i_++)
		for (n = 0; n < 9 && (k%2==0); n++)
		{
			
			setcolor(WHITE);
			
			if (_a.x <= x[i_][n] + w && _a.x >= x[i_][n] && _a.y <= y[i_][n] + h && _a.y >= y[i_][n])
			{
				
				rectangle(x[i_][n], y[i_][n], x[i_][n] + w, y[i_][n] + h);
				
			
			}
		}
		for (i_ = 0; i_ < 9 && (k % 2 == 1); i_++)
		{
			for (n = 0; n < 9 && (k % 2 == 1); n++)
			{
				setcolor(WHITE);

				if (_a.x <= x[i_][n] + w && _a.x >= x[i_][n] && _a.y <= y[i_][n] + h && _a.y >= y[i_][n])
				{
					rectangle(x[i_][n], y[i_][n], x[i_][n] + w, y[i_][n] + h);
					r = (this->animation_change(i_, n, aa, bb, cc, dd, oriMap));
					delimage(BK__);
					BK__ = newimage();
					getimage(BK__, 0, 0, 1476, 1016);

					k = 0;

				}

			}
		}

		
		
	}
	
	delimage(BK__);
	return 0;
}
int Animation::animation_change(int i_, int n, int aa, int bb, int cc, int dd, Map&oriMap)
{
	mouse_msg _a;
	int k = 0;
	int i1 = i_,n1 = n;
	int i2=i_, n2=n;
	int r = 0;
	PIMAGE BK_ = newimage();
	getimage(BK_, 0, 0, 1476, 1016);
	
	for (;;)
	{
		
		_a = getmouse();
		if (!(_a.x <= cc&&_a.x >= aa&&_a.y <= dd&&_a.y >= bb))break;
		if (_a.is_left())
		{
			if (!(_a.x <= x[i2][n2] + w && _a.x >= x[i2][n2] && _a.y <= y[i2][n2] + h && _a.y >= y[i2][n2]) && !(i1 != i2&&n1 != n2))
			{
				
				this->animation_restore(i1, n1, i2, n2);
				
			}
			//////////////发生数据交换，判断是否能产生消除的交换/////////////////////////////////////////
			else{
				r = 1;
				oriMap.swap(n1, 8 - i1, n2, 8 - i2);
				if (!g_checkMap(n1, 8 - i1, n2, 8 - i2,oriMap)){
					this->animation_restore(i1, n1, i2, n2);
					oriMap.swap(n1, 8 - i1, n2, 8 - i2);
					r = 0;
				}
			}
			/////////////////////////////////////////////////////////////////////
			putimage(x[i1][n1], y[i1][n1], BP[i1][n1]);
			putimage(x[i2][n2], y[i2][n2], BP[i2][n2]);
			putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1], BLACK);
			putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2], BLACK);
			break;
		}
		
		
		for (i_ = 0; i_ < 9 && (k == 0); i_++)
		for (n = 0; n < 9 &&( k == 0); n++)
		{
			
			
			if (_a.x <= x[i_][n] + w && _a.x >= x[i_][n] && _a.y <= y[i_][n] + h && _a.y >= y[i_][n] && ((i_ <= i1 + 1 && i_ >= i1 - 1 && n == n1) || (n >= n1 - 1 && n <= n1 + 1 && i_ == i1)) && (_a.x <= cc&&_a.x >= aa&&_a.y <= dd&&_a.y >= bb))
			{
				putimage(0, 0, BK_);
			
				i2 = i_;
				n2 = n;
				if (i2!=i1||n2!=n1){
					putimage(0, 0, BK_);
					this->animation_move(i1, n1, i2, n2);
				
					k = 1; 

				}
				
				
			
				
			}
		}
		
		
	}
	delimage(BK_);
	return r;
}
int Animation::animation_restore(int i1, int n1, int i2, int n2)
{
	
	int k = 0;
	int d = 0;
	PIMAGE A = newimage();
	putimage(x[i1][n1], y[i1][n1], BP[i1][n1]);
	putimage(x[i2][n2], y[i2][n2], BP[i2][n2]);
	setcolor(WHITE);
	rectangle(x[i1][n1], y[i1][n1], x[i1][n1] + w, y[i1][n1] + h);
	rectangle(x[i2][n2], y[i2][n2], x[i2][n2] + w, y[i2][n2] + h);
	PIMAGE BK_ = newimage();
	getimage(BK_, 0, 0, 1476, 1016);
	if (i1 == i2&&n1<n2)
	for (int k = 0; k <= w; k++, delay_fps(240))
	{
		for (; keystate(VK_LBUTTON););
		putimage(0, 0, BK_);
	
		putimage_transparent(NULL, P[i1][n1], x[i1][n1] + k, y[i1][n1], BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2] - k, y[i2][n2], BLACK);
	}
	if (i1 == i2&&n1>n2)
	for (int k = 0; k <= w; k++, delay_fps(240))
	{
		for (; keystate(VK_LBUTTON););
		putimage(0, 0, BK_);
		
		
		putimage_transparent(NULL, P[i1][n1], x[i1][n1] - k, y[i1][n1], BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2]+ k, y[i2][n2], BLACK);
	}
	if (n1 == n2&&i1>i2)
	for (int k = 0; k <= h; k++, delay_fps(240))
	{
		for (; keystate(VK_LBUTTON););
	
		putimage(0, 0, BK_);
		
		putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1] - k, BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2] + k, BLACK);

	}
	if (n1 == n2&&i1<i2)
	for (int k = 0; k <= h; k++, delay_fps(240))
	{
		for (; keystate(VK_LBUTTON););
	
		putimage(0, 0, BK_);
	
		putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2] - k, BLACK);
		putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1] + k, BLACK);
	
	}
	A = P[i1][n1];
	P[i1][n1] = P[i2][n2];
	P[i2][n2] = A;
	putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1] , BLACK);
	putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2] , BLACK);

	flushmouse();
	
	
	delimage(BK_);
	//delete(A);
	
	return 0;
}
int Animation::animation_move(int i1, int n1, int i2, int n2)
{
	int d = 0;

	putimage(x[i1][n1], y[i1][n1], BP[i1][n1]);
	putimage(x[i2][n2], y[i2][n2], BP[i2][n2]);
	setcolor(WHITE);
	rectangle(x[i1][n1], y[i1][n1], x[i1][n1] + w, y[i1][n1] + h);
	rectangle(x[i2][n2], y[i2][n2], x[i2][n2] + w, y[i2][n2] + h);
	PIMAGE BK_ = newimage();
	getimage(BK_, 0, 0, 1476, 1016);
	PIMAGE A = newimage();
	if (i1 == i2&&n1<n2)
	for (int k = 0; k <= w; k++, delay_ms(0))
	{
		
		putimage(0, 0, BK_);
	
		putimage_transparent(NULL, P[i1][n1], x[i1][n1] + k, y[i1][n1], BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2] - k, y[i2][n2], BLACK);

	}
	if (i1 == i2&&n1>n2)
	for (int k = 0; k <= w; k++, delay_ms(0))
	{
		putimage(0, 0, BK_);
		
		putimage_transparent(NULL, P[i1][n1], x[i1][n1] - k, y[i1][n1], BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2] + k, y[i2][n2], BLACK);

	}
	if (n1 == n2&&i1>i2)
	for (int k = 0; k <= h; k++, delay_ms(0))
	{
		putimage(0, 0, BK_);
		putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1] - k, BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2] + k, BLACK);
	

	}
	if (n1 == n2&&i1<i2)
	for (int k = 0; k <= h; k++, delay_ms(0))
	{
		putimage(0, 0, BK_);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2] - k, BLACK);
		putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1] + k, BLACK);
	

	}
	A = P[i1][n1];
	P[i1][n1] = P[i2][n2];
	P[i2][n2] = A;
	putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1], BLACK);
	putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2], BLACK);
	
	delimage(BK_);
	//delete(A);
	return 0;
}
int Animation::animation_disappear(Map&oriMap)
{
	PIMAGE A = newimage();
	getimage(A, "F:\\消消乐\\测试图\\测试图\\a3.png", 0, 0);
	int i_ = 0, n_ = 0;
	delay_ms(Global::delay_disappear);
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		m[i_][n_] = (oriMap.getMaplists()[n_][8 - i_].getIsClear());
		if (m[i_][n_] == 1)putimage_transparent(NULL,A,x[i_][n_], y[i_][n_], BLACK);

	}
	delay_ms(Global::delay_disappear);

	for (i_=0; i_ < 9; i_++)
	for (n_=0; n_ < 9; n_++)
		{
		if (m[i_][n_] == 1)putimage_transparent(NULL,BP[i_][n_],x[i_][n_], y[i_][n_],BLACK);

		}
	for (i_ = 8; i_ > 0; i_--)
	for (n_ = 8; n_ >= 0; n_--)
	{
		
		if (m[i_][n_] == 1)d[i_ - 1][n_] = d[i_][n_]+1;
		if (m[i_][n_] == 0)d[i_ - 1][n_] = d[i_][n_];

	}
	
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		if (m[i_][n_] == 1)d[i_][n_] = 0;

	}
	

	return 0;
}
int Animation::animation_fall(Map&oriMap)
{



	int i_ = 0, n_ = 0, d_ = 0, c_ = 0;//c_用于判断动画是否结束
	////////////////////动画输出////////////////////////////////////////
	for (i_ = 0, n_ = 0, d_ = 0; d_ <= h * 9; d_++, i_ = 0, n_ = 0, c_ = 0, delay_fps(Global::delay_fall))
	{
		for (; keystate(VK_LBUTTON););
		putimage(0, 0, BG);
	for (i_ = 8; i_ >=0; i_--)
	for (n_ = 8; n_ >=0; n_--)
	{

		
		if (d_ < (h*d[i_][n_]) && (m[i_][n_] != 1)&&d[i_][n_]!=0){
			putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_] + d_, BLACK);
			c_++;
		}
		if (d_>=(h*d[i_][n_]) && (m[i_][n_] != 1))
		{
			putimage_transparent(NULL,P[i_][n_],x[i_][n_], y[i_][n_] + h*d[i_][n_], BLACK);
		
		}
	}
	
	
	if (c_ == 0)break;
}
	//////////////////////////////////调整数据////////////////////////////////////
	for (i_ = 8; i_ >= 0; i_--)
	for (n_ = 8; n_ >= 0; n_--)
	{
		if (m[i_][n_] == 1)d_add[n_]++;
		if (d[i_][n_] != 0 && m[i_][n_] != 1){
		P[i_ + d[i_][n_]][n_] = P[i_][n_];
		m[i_ + d[i_][n_]][n_] = 0;

		d[i_][n_] = 0;
		m[i_][n_] = 1;
	}
	}
	

	return 0;
}


int Animation::animation_add(Map&oriMap)
{
int i_ = 0, n_ = 0, d_ = 0,c_=0;

for (i_ = 0; i_ < 9; i_++)
for (n_ = 0; n_ < 9; n_++)
{
	P[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1];



}



for (i_ = 0, n_ = 0, d_ = 0; d_ <= h * 9; d_ = d_++, i_ = 0, n_ = 0, c_ = 0, delay_fps(Global::delay_add))
{

	for (; keystate(VK_LBUTTON););
	putimage(0, 0, BG);
	for (i_ = 0; i_ < 9; i_++)
	{

		for (n_ = 0; n_ < 9; n_++)
		{

			if (i_ <= (d_add[n_] - 1) && (d_add[n_] * h>d_))
			{
				if (((y[i_][n_] - (d_add[n_]) * h + d_) <= y[0][0]) && ((y[i_][n_] - (d_add[n_]) * h + d_) >= (y[0][0] - h)))putimage(x[i_][n_], y[0][0], w, h, P[i_][n_], 0, (y[0][0] - (y[i_][n_] - (d_add[n_]) * h + d_)));
				if ((y[i_][n_] - (d_add[n_]) * h + d_)>y[0][0])putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_] - (d_add[n_]) * h + d_, BLACK);
				c_++;
			}
			else putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_], BLACK);

		}
	}
		if (c_ == 0)break;
	
}
for (i_ = 0; i_ < 9; i_++)
{
	d_add[i_] = 0;
}

flushmouse();

return 0;
}

int Animation::animation_add(void)
{
	int i_ = 0, n_ = 0, d_ = 0, c_ = 0;
	int cc[9] = { 9, 9, 9, 9, 9, 9, 9, 9, 9 };


	for (i_ = 0, n_ = 0, d_ = 0; d_ <= h * 9; d_ = d_++, i_ = 0, n_ = 0, c_ = 0, delay_fps(Global::delay_add))
	{

		for (; keystate(VK_LBUTTON););
		putimage(0, 0, BG);
		for (i_ = 0; i_ < 9; i_++)
		for (n_ = 0; n_ < 9; n_++)
		{

			if (i_ <= (cc[n_] - 1) && (cc[n_] * h>d_))
			{
				if (((y[i_][n_] - (cc[n_]) * h + d_) <= y[0][0]) && ((y[i_][n_] - (cc[n_]) * h + d_) >= (y[0][0] - h)))putimage(x[i_][n_], y[0][0], w, h, P[i_][n_], 0, (y[0][0] - (y[i_][n_] - (cc[n_]) * h + d_)));
				if ((y[i_][n_] - (cc[n_]) * h + d_)>y[0][0])putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_] - (cc[n_]) * h + d_, BLACK);
				c_++;
			}
			else putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_], BLACK);

		}
		if (c_ == 0)break;
	}
	
	flushmouse();

	return 0;
}
int Animation::animation_newmap(Map&oriMap)
{
	int i_ = 0, n_ = 0;
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		P[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1];
		
		
	
		
	}
	
	this->animation_add();
	return 0;
}