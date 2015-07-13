//------------READ-ME--------------------------------------------
//标记nedOPT的地方意味着需要优化
//标记+的地方意味着需要添加

//Update7-7: 现已确定方块的属性是 Piece.type		(0，6]    match to six different piece basic type
//			 特殊方块：			Piece.specType	[0，6]	  match to seven different piece addition type
//			specType:			
/*
* 0.ori-原始方块-什么都不做		
* 1.line-消除列
* 2.row-消除行		
* 3.box-消除3*3	
* 4.same_color-消除同色
* 5.unclear-不可消除	
* 6.death-直接死亡
*/

//Update7-7:Please add getter and setter for your class :D
//Update7-7:Please change your function name to match main function as possible~ 
//Update7-8:对Map类请求：增添一个数据域读取消除方块的总数
//Update7-8:Map在中间删除元素后 其中的迭代器会失效，请注意在循环里重建新迭代器
//Update7-8:-无效信息-Map队列使用左上角为坐标原点
//Update7-8:Map队列更新为使用左下角为坐标原点
//Update7-8:游戏窗口大小为1476*1016
//Update7-9:每个Piece大小:100*100，有效区域:98*98，Map区域大小:900*900，左上原点位置:(x_map_LT,y_map_LT)，左下原点位置:(x_map_LB,y_map_LB)		
//			每块[x][y]piece坐标的位置：
//Update7-9:同名请求： 统一函数命名 检查是否-is 配对-pair 消除-clear 记分板（排行榜）-leaderboard 块-piece 图-map 分数-score 创造-make 判定旗帜-flag
//			旧的，原始的-ori 新的-new
//			gameMode下的函数请加 "g_" 前缀，learboardMode下的函数请加 "l_" 前缀
//Update7-9:坐标全部使用传参处理
//Update7-10:暂停继续按钮坐标:(85 802)(327 802)
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include "graphics15.h"
#include "leaderboardMode.h"
#include "Map.h"
#include "Piece.h"
#include "Global.h"
#include "Button.h"
#include "resource.h"
#include"Animation.h"
#include "gameMode.h"
#include "optionMode.h"
//接口函数列表
//g_makeMap();
//g_isDead();
//g_playerMove();			
//g_checkPair(oriMap);
//g_pairUp();
//g_setMap();
//g_replenishMap();

void resourceLoad(Option);
void resourceLoadSkin(int);
int gameMode();
int leaderboardMode();//+
int optionMode();//+
int exitMode();
int init(void);
int meun(int);
int start(void);
//
int start(void)
{	
	Resource res;
	int mouseCheck= 0;


	Button *button_menu = new Button(800, 400, 640, 120, 1, res.newGameButton_basic, res.newGameButton_move, res.newGameButton_press);
	Button *button_menu2 = new Button(800, 521, 640, 120, 2, res.leaderboard_basic, res.leaderboard_move, res.leaderboard_press);
	Button *button_menu3 = new Button(800, 642, 640, 120, 3, res.optionButton_basic,res.optionButton_move, res.optionButton_press);	
	Button *button_menu4 = new Button(800, 763, 640, 120, 4, res.exitButton_basic, res.exitButton_move,res.exitButton_press);

	
	mouseCheck = Button::pubutton(0, 0, 1476, 1016, res.BK);

	delete(button_menu);
	delete(button_menu2);
	delete(button_menu3);
	delete(button_menu4);

	delimage(res.newGameButton_basic);
	delimage(res.newGameButton_move);
	delimage(res.newGameButton_press);
	delimage(res.exitButton_basic);
	delimage(res.exitButton_move);
	delimage(res.exitButton_press);
	delimage(res.leaderboard_basic);
	delimage(res.leaderboard_move);
	delimage(res.leaderboard_press);

	return mouseCheck;
	
}

//Main Function
int main(int argc, char*argv[])
{
	int condition = 1;
	init();
	while (condition)
	{
	condition = meun(start());
	}
	//yage_quit();
	closegraph();
	return 0;
}

int init(void)
{
	srand((unsigned)time(0));
	initgraph(Global::x_scr, Global::x_scr);
	setrendermode(RENDER_AUTO);
	//setrendermode(RENDER_MANUAL);
	//yage_init(Global::x_scr, Global::y_scr);
	return 0;
}

//NEED TO FIX:
//CONDITION WILL ALWAYS BE 1 IT CAUSE INFINITY LOOP
int meun(int playerChoose)
{
	int condition = 0;
		switch (playerChoose)
		{
		case 1:
			//start game
			condition = gameMode();
			break;
		case 2:
			//open record mode
			condition = leaderboardMode();
			break;
		case 3:
			//option
			condition = optionMode();
			break;
		case 4:
			//exit program
			condition = exitMode();
			break;
		default:
			condition = 1;
			break;
		}
		return condition;
}

int gameMode()
{	
	g_game();
	return 1;
}

int leaderboardMode()
{	
	l_leaderboard();
	return 1;
}

int optionMode()
{	
	o_option();
	return 1;
}

int exitMode()
{
	return 0;
}

void resourceLoad(Option option)
{
//	struct yage_canvas *Background = yage_canvas_load_image("Bk.png");
	resourceLoadSkin(option.getSkin());
}

void resourceLoadSkin(int skin)
{
	std::vector<struct yage_canvas *> pieceSkin;
	std::string temp;
	std::stringstream ss;
	//加载6*5=30张皮肤 (6种方块每个有5种特殊方块）
	for (int i = 1; i != 7; ++i)
		for (int j = 0; j != 7; ++j)
		{
			ss << "Skin" << skin << "_Piece_" << i << "_" << j << ".png";
			ss >> temp;
			ss.clear();
			std::cout << temp << std::endl;
			//pieceSkin.push_back(yage_canvas_load_image(temp.c_str()));
		}
		ss << "Skin" << skin << "_Piece_Special_1";
		ss >> temp;
		ss.clear();
		//struct yage_canvas *specPiece1 = yage_canvas_load_image(temp.c_str());
		ss << "Skin" << skin << "_Piece_Special_2";
		ss >> temp;
		ss.clear();
		//struct yage_canvas *specPiece2 = yage_canvas_load_image(temp.c_str());

}