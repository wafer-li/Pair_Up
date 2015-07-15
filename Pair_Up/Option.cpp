#include "Option.h"


//Ctor
//Default setting:
//Skin -> The LoveLive Skin
//Background -> GBk3.png
Option::Option()
{
	skin = 3;
	background = 7;
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