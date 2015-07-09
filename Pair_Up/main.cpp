//------------READ-ME--------------------------------------------
//标记nedOPT的地方意味着需要优化
//标记+的地方意味着需要添加
//Update7-7: 现已确定方块的属性是 Piece.type		(0，6]    match to six different piece basic type
//			 特殊方块：			Piece.specType	[0，6]	  match to seven different piece addition type
//			specType:			0.ori-原始方块-什么都不做		1.line-消除列	2.row-消除行		3.box-消除3*3	4.same_color-消除同色	5.unclear-不可消除	6.death-直接死亡
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
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include "yage.h"
#include "Map.h"
#include "Piece.h"
#include "Button.h"
//接口函数列表
//g_makeMap();
//g_isDead();
//g_playerMove();			
//g_checkPair(oriMap);
//g_pairUp();
//g_setMap();
//g_replenishMap();
//Update7-7：内容写好了我就写上面的函数..
const static int x_scr = 1476;
const static int y_scr = 1016;
const static int x_map = 900;
const static int y_map = 900;
const static int x_piece = 100;
const static int y_piece = 100;
const static int x_map_LT = 519;
const static int x_map_LB = 519;
const static int y_map_LT = 52;
const static int y_map_LB = 952;
static int glo_score = 0;
void resource(Option)
{	
	struct yage_canvas *Background = yage_canvas_load_image("Bk.png");
	resourceSkin(o_skin);
}
void resourceSkin(int skin)
{
	std::vector<struct yage_canvas *> pieceSkin;
	std::string temp;
	std::stringstream ss;
	for (int i = 1; i != 7; ++i)
	for (int j = 1; j != 7; ++j)
	{
		ss << "Skin" << skin << "_Piece_" << i << "_" << j << ".png";
		ss >> temp;
		ss.clear();
		std::cout << temp << std::endl;
		pieceSkin.push_back(yage_canvas_load_image(temp.c_str()));
	}
	system("PAUSE");
}

int main(int argc, char*argv[])
{

	init();
	meun(start());
	yage_quit();
	return 0;
}

int init(void)
{
	srand((unsigned)time(0));
	yage_init(x_scr, y_scr);
	return 0;

}

void meun(int playerChoose)
{
	int condition = 1;

	while (condition)
		switch (playerChoose)
	{
		case 1:
			condition = gameMode();
			//start game
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
	}
}

int gameMode()
{
	g_game();
	return 1;
}

int leaderboardMode()
{
	return 1;
}

int optionMode()
{
	return 1;
}

int exitMode()
{

	return 0;
}