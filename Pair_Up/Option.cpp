#include "Option.h"


Option::Option()
{
	skin = 1;
	background = 0;
}

Option::~Option()
{
}

int Option::getSkin(void)
{
	return this->skin;
}

int Option::getBackground(void)
{
	return this->background;
}

void Option::setSkin(int sS)
{
	this->skin = sS;
}
void Option::setBackground(int sB)
{
	this->background = sB;
}