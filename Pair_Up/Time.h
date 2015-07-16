#ifndef TIME_H
#define TIME_H
#include "graphics15.h"
#include "Global.h"
#include "Score.h"

class Time
{
private:
	//All are seconds
	int remainTime;
	double timeAmount;
	double stopPoint;
	double changePoint;
	double startPoint;
	double resumePoint;

	//isStop
	bool stopFlag;

	/* Private Method */
	int countRemainTime();

public:
	/* Ctor & Dtor */
	Time();
	~Time();

	//RemainTime
	int getRemainTime();

	//PauseTime
	void pauseTime();

	//ResumeTime
	void resumeTime();

	//isStop
	bool isStop();

	//addTime
	//When level up
	void addTime(Score & score);
};

#endif
