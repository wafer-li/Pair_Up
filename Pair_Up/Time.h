#ifndef TIME_H
#define TIME_H
#include <iostream>
#include "yage.h"

class Time
{
public:
	Time();
	~Time();
	double time_yage_create(int level);
	void time_yage_pause(struct yage_timer * timer);
	void time_yage_resume(struct yage_timer *timer);
private:
	struct yage_timer *timer;

};
#endif
