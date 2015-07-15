#include "Option.h"


//Ctor
//Default setting:
//Skin -> The LoveLive Skin
//Background -> GBk3.png
Option::Option()
{
	std::string strSK,strBG;
	std::stringstream ssSK,ssBG;
	std::ifstream ipSK;
	std::ifstream ipBG;
	ipSK.open("OptionSK.txt", std::ios::in);
	ipBG.open("OptionBG.txt", std::ios::in);
	ipSK >> strSK;
	ipBG >> strBG;
	ssSK << strSK;
	ssBG << strBG;
	ssSK >> this->skin;
	ssBG >> this->background;
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