#ifndef GLOBAL_H
#define GLOBAL_H

//never instantiation the class
class Global
{
public:
	Global();
	~Global();
	const static int x_scr ;
	const static int y_scr ;
	const static int x_map ;
	const static int y_map  ;
	const static int x_piece ;
	const static int y_piece ;
	const static int x_map_LT ;
	const static int x_map_LB ;
	const static int y_map_LT ;
	const static int y_map_LB ;

//specType:	
/*
*0.ori-原始方块-什么都不做
*1.line-消除列
*2.row-消除行		
*3.box-消除3*3	
*4.same_color-消除同色	
*5.unclear-不可消除	
*6.death-直接死亡
*/
	enum SpecType
	{
		origin, line,row,box,same_color,unclearable,death
	};
};


#endif