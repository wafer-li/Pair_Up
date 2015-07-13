#include "leaderboardMode.h"

/*judge is the score at the top 10 of the game
* if it is,write it into leaderboard
*/
#include "graphics15.h"
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <utility>
/*judge is the score at the top 10 of the game
* if it is,write it into leaderboard
*/


// this function judge the score,and save the date
void l_inRanking(int score)
{
	std::fstream rank1;
	rank1.open("rankingList.dat", std::ios::in);
	std::multimap<int, std::string> rankMap;//get all the score
	std::string userName;
	std::string Name;//get user's name
	char ege_Name[100];//to get ege_name
	int userScore;
	std::multimap<int, std::string>::iterator p;
	if (!rank1.fail())
	{
		for (; !rank1.eof();)
		{
			rank1 >> userScore;
			rank1 >> userName;
			rankMap.insert(std::map<int, std::string>::value_type(userScore, userName));
			//if there is a failue, try to read and write one by one
		}
	}
	rank1.close();
	p = rankMap.begin();
	if (rankMap.size() != 0)
	{
		if (score > (p->first))
		{
			ege::inputbox_getline("请输入你的名字", "没办法队员对于做漂亮输入框这件事弃疗了/n将就下好了(┬＿┬)↘", ege_Name, 100);
			Name = ege_Name;
			rankMap.insert(std::make_pair(score, Name));
			//begin write the date
			rank1.open("rankingList.dat", std::ios::out);
			for (p = rankMap.begin(); p != rankMap.end(); p++)
			{
				userScore = p->first;
				userName = p->second;
				rank1 << ' ' << userScore;
				rank1 << ' ' << userName;
			}
		}
		rank1.close();
	}
	else
	{
		ege::inputbox_getline("请输入你的名字", "没办法队员对于做漂亮输入框这件事弃疗了/n将就下好了(┬＿┬)↘", ege_Name, 100);
		Name = ege_Name;
		rankMap.insert(std::make_pair(score, Name));
		//begin write the date
		rank1.open("rankingList.dat", std::ios::out);
		for (p = rankMap.begin(); p != rankMap.end(); p++)
		{
			userScore = p->first;
			userName = p->second;
			rank1 << ' ' << userScore;
			rank1 << ' ' << userName;

		}
		rank1.close();
	}
}

/*
The function display the LeaderBoard to user.
this function do not cheek the number of score.
*/
void l_leaderboard()
{
	//界面初始化
	PIMAGE image0 = newimage();
	getimage(image0, "PairupLeader.jpg", 0, 0);
	putimage(0, 0, image0);
	setbkmode(TRANSPARENT);
	setfont(-100, -49, "Kingdom Hearts");
	setcolor(EGERGB(255, 0, 0));
	/********************************************/
	std::fstream rank2;
	rank2.open("rankingList.dat", std::ios::in);
	std::string userName;
	int userScore;
	std::string name;//username for UI
	std::string score;//userscore for UI
	std::multimap<int, std::string> rankMap;//get all the score
	std::multimap<int, std::string>::iterator p;
	std::stringstream temp;
	for (; !rank2.eof();)
	{
		rank2 >> userScore;
		rank2 >> userName;
		rankMap.insert(std::map<int, std::string>::value_type(userScore, userName));
		//if there is a failue, try to read and write one by one
	}
	rank2.close();
	//dispaly the score
	if (rankMap.size() != 0)
	{
		p = rankMap.begin();
		for (int i = 1; p != rankMap.end(); p++, i++)
		{
			if (p->first > 0)
			{
				//five locations, so we need five judge for them
				if ((rankMap.size() - i) == 0)
				{
					temp << p->first;
					temp >> score;
					outtextxy(288, 157, score.c_str());
					temp.clear();
					temp << p->second;
					temp >> name;
					outtextxy(668, 208, name.c_str());
					temp.clear();
				}
				else if ((rankMap.size() - i) == 1)
				{
					temp << p->first;
					temp >> score;
					outtextxy(601, 309, score.c_str());
					temp.clear();
					temp << p->second;
					temp >> name;
					outtextxy(996, 358, name.c_str());
					temp.clear();
				}
				else if ((rankMap.size() - i) == 2)
				{
					temp << p->first;
					temp >> score;
					outtextxy(631, 496, score.c_str());
					temp.clear();
					temp << p->second;
					temp >> name;
					outtextxy(1038, 540, name.c_str());
					temp.clear();
				}
				else if ((rankMap.size() - i) == 3)
				{
					temp << p->first;
					temp >> score;
					outtextxy(704, 684, score.c_str());
					temp.clear();
					temp << p->second;
					temp >> name;
					outtextxy(1100, 722, name.c_str());
					temp.clear();
				}
				else if ((rankMap.size() - i) == 4)
				{
					temp << p->first;
					temp >> score;
					outtextxy(623, 889, score.c_str());
					temp.clear();
					temp << p->second;
					temp >> name;
					outtextxy(1012, 933, name.c_str());
					temp.clear();
				}

			}
		}
	}
	mouse_msg m_temp;
	for (; !((m_temp.is_left()) || (m_temp.is_right()));)
	{
		m_temp = getmouse();
	}
	delimage(image0);
}
//void l_leaderboard();