#ifndef GLOBAL_H
#define GLOBAL_H

//WRANING:DO NOT instantiation the class
class Global
{
public:
	/* Ctor & Dtor */
	Global();
	~Global();


	/* Global Variable */

	//Common Coordinate
	const static int x_scr ;
	const static int y_scr ;
	const static int x_0;
	const static int y_0;

	//Game Coordinate
	const static int x_map ;
	const static int y_map  ;
	const static int x_piece ;
	const static int y_piece ;
	const static int x_map_LT ;
	const static int x_map_LB ;
	const static int y_map_LT ;
	const static int y_map_LB ;
	const static int x_g_b_exit;
	const static int y_g_b_exit;
	const static int x_g_b_pause;
	const static int y_g_b_pause;
	const static int MAX_SIZE;

	//Delay
	const static int delay_fall;               //fps
	const static int delay_add;                //fps
	const static int delay_change;             //fps
	const static int delay_disappear;          //ms
	const static int speed;

	//Time
	const static double INIT_TIME;	//seconds
	const static double ADDTIME_L1;
	const static double ADDTIME_L2;
	const static double ADDTIME_L3;
	const static double ADDTIME_L4;

	//PassScore
	const static int FIRST_PASSSCORE;


	//specType:	
	/*
	*0.ori-原始方块-什么都不做
	*1.line-消除列
	*2.row-消除行		
	*3.box-消除3*3
	*4.same_color-消除同色	
	*5.unclear-不可消除
	*/
	enum SpecType
	{
		origin, line,row,box,same_color,unclearable
	};
};


#endif