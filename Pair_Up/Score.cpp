#include "Score.h"
#include<cmath>


/* Ctor & Dtor */

//The value of level1
Score::Score()
{
	score = 0;
	level = 1;
	passScore = 1000;
}


Score::~Score()
{
	//Dtor
}

//Method

/* Private Method */

int Score::countAdditionNum(int level)
{
	int N =  0;

	if (level >= 1 && level < 4)
	{
		N = level * 1000;
	}

	if (level >= 4 && level < 7)
	{
		N = ((2 * level) - 3) * 1000;
	}

	if (level >= 7 && level < 10)
	{
		N = ((3 * level) - 7) * 1000;
	}

	if (level >= 10)
	{
		N = ((4 * level) - 15) * 1000;
	}

	return N;
}

int Score::countPassScore(int level)
{
	if (level == 1)
	{
		return 1000;
	}
	else
	{
		return(countPassScore(level - 1) + countAdditionNum(level));
	}
}

void Score::setPassScore(int level)
{
	passScore = countPassScore(level);
}


/* Public Method */

//Score
int Score::getScore()
{
	return score;
}

//The Interface that support for front-end 
void Score::changeScore(int num, int com)
{
	score += int((30 * pow(1.5, num - 3) * com));
}

//PassScore
int Score::getPassScore()
{
	return passScore;
}

//Level
int Score::getLevel()
{
	return level;
}

//The Interface for front-end
bool Score::levelUp()
{
	bool flag = false;

	if (score >= passScore)
	{
		level++;
		flag = true;
		setPassScore(level);
	}

	return flag;
}