#include "Time.h"

//Ctor & Dtor
Time::Time()
{
	//All are seconds
	remainTime = 30;
	startPoint = fclock();
	stopPoint = 0.0;
	changePoint = 0.0;
	timeAmount = Global::INIT_TIME;
}

Time::~Time()
{}

/* Private Method */

int Time::countRemainTime()
{
	double  remainTimeBuffer;
	changePoint = fclock();
	if (!stopPoint)
	{
		remainTimeBuffer = timeAmount - (changePoint - startPoint);
	}
	else
	{
		remainTimeBuffer = timeAmount - (stopPoint - startPoint);
	}

	return int(remainTimeBuffer + 0.5);
}

/* Public Method */

int Time::getRemainTime()
{
	return countRemainTime();
}

//Pause the RemainTime subtract
void Time::pauseTime()
{
	stopPoint = fclock();
}

void Time::resumeTime()
{
	stopPoint = 0.0;
}

void Time::addTime(Score & score)
{
	int level = score.getLevel();

	if (level >= 1 && level < 4)
	{
		timeAmount += Global::ADDTIME_L1;
	}
	if (level >= 4 && level < 7)
	{
		timeAmount += Global::ADDTIME_L2;
	}
	if (level >= 7 && level < 10)
	{
		timeAmount += Global::ADDTIME_L3;
	}
	if (level > 10)
	{
		timeAmount += Global::ADDTIME_L4;
	}
}