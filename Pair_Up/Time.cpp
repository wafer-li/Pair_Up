#include "Time.h"

int time_ege(int level)
{
	int totalSeconds = time(0) % 60;
	int currentSeconds = 0;
	int seconds = 30;
	if (level >= 1 && level <= 3)
		seconds += 15;
	if (level >= 4 && level <= 6)
		seconds += 20;
	if (level >= 7 && level <= 9)
		seconds += 20;
	for (;;)
	{
		int currentSeconds = time(0) % 60;
		int subtract = currentSeconds - totalSeconds;
		if (subtract <= seconds)
		{
			return subtract;
			delay_ms(1000);
		}
		else
			break;
	}
}