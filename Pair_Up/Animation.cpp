#include"Animation.h"

Animation::Animation(void)  //测试用
{

}
Animation::Animation(Option opt,Map map)
{
	int k_ = 0, i_ = 0, n_ = 0;

	std::string temp;
	std::stringstream ss;

	/////////////////////////////初始化各种类型素材图片////////////////////////////////	
	BG = newimage();
	DP = newimage();
	/*for (int i = 0; i != 6; i++){
		TYPE[i] = newimage();
		ss << "resource\\skin" << opt.getSkin() << "\\Skin" << opt.getSkin() << "_Piece_" << i+1 << "_0" << ".png";
		ss >> temp;
		getimage(TYPE[i], temp.c_str(), 0, 0);
		ss.clear();
		for (int k = 0; k != 5; k++){
			STYPE[i][k] = newimage();
			ss << "resource\\skin" << opt.getSkin() << "\\Skin" << opt.getSkin() << "_Piece_" << i << "_" << k+1 << ".png";
			ss >> temp;
			getimage(STYPE[i - 1][k], temp.c_str(), 0, 0);
			ss.clear();
		}
	}	*/
	for (int i = 0; i != 6; ++i){
		for (int j = 0; j != 6; ++j)
		{
			TYPEALL[i][j] = newimage();
			ss << "resource\\skin" << opt.getSkin() << "\\Skin" << opt.getSkin() << "_Piece_" << i + 1 << "_" << j << ".png";
			ss >> temp;
			getimage(TYPEALL[i][j], temp.c_str(), 0, 0);
			ss.clear();
		}
	}

	ss << "resource\\skin" << opt.getSkin() << "\\Skin" << opt.getSkin() << "_Piece_Special_" << opt.getSkin() << ".png";
	ss >> temp;
	getimage(DP, temp.c_str(), 0, 0);
	ss.clear();
	ss << "resource\\GBk" << opt.getBackground() << ".png";
	ss >> temp;
	getimage(BG, temp.c_str(), 0, 0);
	ss.clear();


	

	//加载6*5=30张皮肤 (6种方块每个有5种特殊方块）
	
	//////////////////////////////确定每个方块的参数//////////////////////////////
	w = Global::x_piece;
	h = Global::y_piece;
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		if (map.getMaplists()[n_][8 - i_].getSpecType() != 0)
		{
			//P[i_][n_] = STYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1][(map.getMaplists()[n_][8 - i_].getSpecType())-1 ];
			P[i_][n_] = TYPEALL[(map.getMaplists()[n_][8 - i_].getType()) - 1][(map.getMaplists()[n_][8 - i_].getSpecType())];
		}
		else {
			//P[i_][n_] = TYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1];
			P[i_][n_] = TYPEALL[(map.getMaplists()[n_][8 - i_].getType()) - 1][0];
		}
		x[i_][n_] = Global::x_map_LT + w*n_;
		y[i_][n_] = Global::y_map_LT + h*i_;
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

		if ((r == 1)||(r==3)){
			putimage(0, 0, BK__);
			
			break;

		}
		if (( r == 4)||(r==5)){
			putimage(0, 0, BK__);
			r = 0;
			
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
					k = 0;
				
				}
				if ((i1 == i2) && (n1 == n2))
				{
					r=(this->animation_click(i1, n1, oriMap));
					k = 0;
					
				}
		
			//////////////发生数据交换，判断是否能产生消除的交换/////////////////////////////////////////
				if (k==1){
				r = 1;
				if (!g_checkMap(n1, 8 - i1, n2, 8 - i2,oriMap)){
					this->animation_restore(i1, n1, i2, n2);
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
	for (int k = 0; k <= w; k += Global::speed, delay_fps(240))
	{
		for (; keystate(VK_LBUTTON););
		putimage(0, 0, BK_);
	
		putimage_transparent(NULL, P[i1][n1], x[i1][n1] + k, y[i1][n1], BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2] - k, y[i2][n2], BLACK);
	}
	if (i1 == i2&&n1>n2)
	for (int k = 0; k <= w; k += Global::speed, delay_fps(240))
	{
		for (; keystate(VK_LBUTTON););
		putimage(0, 0, BK_);
		
		
		putimage_transparent(NULL, P[i1][n1], x[i1][n1] - k, y[i1][n1], BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2]+ k, y[i2][n2], BLACK);
	}
	if (n1 == n2&&i1>i2)
	for (int k = 0; k <= h; k += Global::speed, delay_fps(240))
	{
		for (; keystate(VK_LBUTTON););
	
		putimage(0, 0, BK_);
		
		putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1] - k, BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2] + k, BLACK);

	}
	if (n1 == n2&&i1<i2)
	for (int k = 0; k <= h; k += Global::speed, delay_fps(240))
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
	for (int k = 0; k <= w; k += Global::speed, delay_fps(Global::delay_change))
	{
		
		putimage(0, 0, BK_);
	
		putimage_transparent(NULL, P[i1][n1], x[i1][n1] + k, y[i1][n1], BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2] - k, y[i2][n2], BLACK);

	}
	if (i1 == i2&&n1>n2)
	for (int k = 0; k <= w; k += Global::speed, delay_fps(Global::delay_change))
	{
		putimage(0, 0, BK_);
		
		putimage_transparent(NULL, P[i1][n1], x[i1][n1] - k, y[i1][n1], BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2] + k, y[i2][n2], BLACK);

	}
	if (n1 == n2&&i1>i2)
	for (int k = 0; k <= h; k += Global::speed, delay_fps(Global::delay_change))
	{
		putimage(0, 0, BK_);
		putimage_transparent(NULL, P[i1][n1], x[i1][n1], y[i1][n1] - k, BLACK);
		putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2] + k, BLACK);
	

	}
	if (n1 == n2&&i1<i2)
	for (int k = 0; k <= h; k += Global::speed, delay_fps(Global::delay_change))
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

	int i_ = 0, n_ = 0;
	delay_ms(Global::delay_disappear);
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		m[i_][n_] = (oriMap.getMaplists()[n_][8 - i_].getIsClear());
		if (m[i_][n_] == 1)
		{
			
			putimage_transparent(NULL, DP, x[i_][n_], y[i_][n_], BLACK);
		}

	}
	delay_ms(Global::delay_disappear);

	for (i_=0; i_ < 9; i_++)
	for (n_=0; n_ < 9; n_++)
		{
		if (m[i_][n_] == 1)putimage_transparent(NULL,BP[i_][n_],x[i_][n_], y[i_][n_],BLACK);

		}
	////////////////////////////数据处理//////////////////
	for (n_ = 0; n_ < 9; n_++)
	{
		d_add[n_] = 0;
	}


	for (i_ = 8; i_ >=0; i_--)
	for (n_ = 8; n_ >= 0; n_--)
	{
		
		if (i_ != 8){
			if (m[i_][n_] == 1)d[i_][n_] = d[i_ + 1][n_] + 1;
			if (m[i_][n_] == 0)d[i_][n_] = d[i_ + 1][n_];
		}
		if (i_ == 8){
			if (m[i_][n_] == 1)d[i_][n_] = 1;
			if (m[i_][n_] == 0)d[i_][n_] = 0;
		}


	}
	for (i_ = 0; i_ <8; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		if ((m[i_][n_] == 1) && (m[i_ + 1][n_] == 1))
		{
			d_add[n_]++;
			d[i_ + 1][n_] += d_add[n_];
		}
	}
	
	/*for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		if (m[i_][n_] == 1)d[i_][n_] = 0;

	}
	*/
	
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
	if (oriMap.getMaplists()[n_][8 - i_].getSpecType() != 0)
	{
		//P[i_][n_] = STYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][(oriMap.getMaplists()[n_][8 - i_].getSpecType())-1 ];
		P[i_][n_] = TYPEALL[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][(oriMap.getMaplists()[n_][8 - i_].getSpecType())];
	}
	else {
		//P[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1];
		P[i_][n_] = TYPEALL[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][0];
	}



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


	for (i_ = 0, n_ = 0, d_ = 0; d_ <= h * 9; d_+=Global::speed, i_ = 0, n_ = 0, c_ = 0, delay_fps(Global::delay_add))
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
		if (oriMap.getMaplists()[n_][8 - i_].getSpecType() != 0)
		{
			//P[i_][n_] = STYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][(oriMap.getMaplists()[n_][8 - i_].getSpecType())-1 ];
			P[i_][n_] = TYPEALL[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][(oriMap.getMaplists()[n_][8 - i_].getSpecType())];
		}
		else {
		//P[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1];
		P[i_][n_] = TYPEALL[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][0];
	}
		
	
		
	}
	
	this->animation_add();
	return 0;
}
int Animation::animation_click(int i1, int n1, Map&oriMap)
{
	int i_ = 0, n_ = 0, k_ = 0;
	int i2 = 0, n2 = 0;
	mouse_msg a_;
	PIMAGE BK_ = newimage();
	
	getimage(BK_, 0, 0, 1476, 1016);
	setcolor(WHITE);
	for (;k_<3;)
	{
		a_ = getmouse();
		if (a_.is_left())k_++;
		for (i_ = 0; i_ < 9 && (k_ == 0);i_++)
		for (n_ = 0; n_ < 9 && (k_ == 0); n_++)
		{
			if (a_.x <= x[i_][n_] + w && a_.x >= x[i_][n_] && a_.y <= y[i_][n_] + h && a_.y >= y[i_][n_])
			{

				putimage(0, 0, BK_);
				rectangle(x[i_][n_], y[i_][n_], x[i_][n_] + w, y[i_][n_] + h);
			}
		}
		
			for (i_ = 0; i_ < 9 && (k_ == 1); i_++)
			for (n_ = 0; n_ < 9 && (k_ == 1); n_++)
			{
				if (a_.x <= x[i_][n_] + w && a_.x >= x[i_][n_] && a_.y <= y[i_][n_] + h && a_.y >= y[i_][n_])
				{

					putimage(0, 0, BK_);
					rectangle(x[i_][n_], y[i_][n_], x[i_][n_] + w, y[i_][n_] + h);
				
				}
			}
		
		
			for (i_ = 0; i_ < 9 && (k_ == 2); i_++)
			for (n_ = 0; n_ < 9 &&( k_ == 2); n_++)
			{
				if (a_.x <= x[i_][n_] + w && a_.x >= x[i_][n_] && a_.y <= y[i_][n_] + h && a_.y >= y[i_][n_])
				{

					if ((i_ == i1 && ((n_ == n1 + 1) || (n_ == n1 - 1))) || (n_ == n1 && ((i_ == i1 + 1) || (i_ == i1 - 1))))
					{
						this->animation_move(i1, n1, i_, n_);
						i2 = i_;
						n2 = n_;
						k_ = 3;
						
					}
					else{
						putimage_transparent(NULL, BP[i_][n_], x[i_][n_], y[i_][n_], BLACK);
						putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_], BLACK);
						k_ = 5;
					}
				}
			}
			if (k_ == 3){
				if (!g_checkMap(n2, 8 - i2, n1, 8 - i1, oriMap)){
					this->animation_restore(i1,n1,i2,n2);
					k_ = 4;
					putimage(0, 0, BK_);
					
				}
				else{
					putimage_transparent(NULL, BP[i2][n2], x[i2][n2], y[i2][n2], BLACK);
					putimage_transparent(NULL, P[i2][n2], x[i2][n2], y[i2][n2], BLACK);
				}
				
			}

	}
	delimage(BK_);

	return k_;
}
int Animation::animation_fall_add(Map&oriMap)
{
	int i_ = 0, n_ = 0, d_ = 0, c_ = 0;//c_用于判断动画是否结束
	////////////////////更新数据////////////////////////////////
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		if (oriMap.getMaplists()[n_][8 - i_].getSpecType() != 0)
		{
			//P[i_][n_] = STYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][(oriMap.getMaplists()[n_][8 - i_].getSpecType())-1 ];
			P[i_][n_] = TYPEALL[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][(oriMap.getMaplists()[n_][8 - i_].getSpecType())];
		}
		else {
			//P[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1];
			P[i_][n_] = TYPEALL[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][0];
		}



	}
	/////////////////////////////播放动画///////////////////////////

	for (i_ = 0, n_ = 0, d_ = 0; d_ <= h * 9; d_ += Global::speed, i_ = 0, n_ = 0, c_ = 0, delay_fps(Global::delay_add))
	{

		for (; keystate(VK_LBUTTON););
		putimage(0, 0, BG);
		for (i_ = 0; i_ < 9; i_++)
		{

			for (n_ = 0; n_ < 9; n_++)
			{

				if ((d[i_][n_] * h>d_)&&(d[i_][n_]!=0))
				{
					
					if (((y[i_][n_] - (d[i_][n_]) * h + d_) <= y[0][0]) && ((y[i_][n_] - (d[i_][n_]) * h + d_) >= (y[0][0] - h)))putimage(x[i_][n_], y[0][0], w, h, P[i_][n_], 0, (y[0][0] - (y[i_][n_] - (d[i_][n_]) * h + d_)));
					if ((y[i_][n_] - (d[i_][n_]) * h + d_)>y[0][0])putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_] - (d[i_][n_]) * h + d_, BLACK);
					c_++;
				}
				else { 
					putimage_transparent(NULL, P[i_][n_], x[i_][n_], y[i_][n_], BLACK); 
				}

			}
		}
		if (c_ == 0)break;

	}
	flushmouse();
	return 0;
}