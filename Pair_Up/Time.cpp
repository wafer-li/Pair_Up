#include "Time.h"


Time::Time()
{
	struct yage_timer *timer = NULL;
}


Time::~Time()
{
}

double Time::time_yage_create(int level)
{
	int seconds_ = 30;
	if (level >= 1 && level <= 3)
	{
		seconds_ += 15;
	}
	if (level >= 4 && level <= 6)
	{
		seconds_ += 20;
	}
	if (level >= 1 && level <= 9)
	{
		seconds_ += 25;
	}
	else
		seconds_ += 30;
	struct yage_timer *timer = yage_timer_create(seconds_);
	struct yage_message msg;
	while (yage_get_message(&msg, 0))
	{
		if (msg.type != kYageTimer)
			continue;
		if (msg.timer.type == kYageTimerRunning)
		{
			//yage_clear();
			return seconds_ - msg.timer.seconds;
			//another way: return yage_timer_get_time_elapsed(timer);
		}
		else
		{
			yage_timer_stop(timer);
		}
	}
}

void Time::time_yage_pause(struct yage_timer * timer)
{
	yage_timer_pause(timer);
}
void Time::time_yage_resume(struct yage_timer *timer)
{
	yage_timer_resume(timer);
}
