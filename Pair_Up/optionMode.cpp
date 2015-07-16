#include "optionMode.h"
#include "graphics15.h"
#include "Button.h"
#include "Global.h"
#include <fstream>
#include <string>
#include <sstream>
int optionBK(){
	cleardevice();
	std::stringstream ss;
	std::string temp;
	int mouseCheck = 0;
	//基起点
	int x1 = 150, y1 = 100;
	//基高基长
	int w = 270, h = 200;
	//渐增
	int n_x = 300, n_y = 210;
	int check = 0;
	PIMAGE imageBG = newimage();
	PIMAGE P_cut1 = newimage();
	PIMAGE P_cut2 = newimage();
	PIMAGE P_cut3 = newimage();
	getimage(imageBG, "resource\\option1.png", 0, 0);
	putimage(0, 0, imageBG);
	PIMAGE P_BG[12];
	Button *B_BG[12];
	Button *B_cut1 = new Button(153, 15, 120, 60, -1, P_cut1);
	Button *B_cut2 = new Button(293, 15, 110, 60, -2, P_cut2);
	Button *B_cut3 = new Button(1116, 9, 115, 56, -3, P_cut3);
	for (int i = 0; i != 12; ++i){
		P_BG[i] = newimage();
		ss << "resource\\BackGround\\GameBKS\\" << i + 1 << ".png";
		ss >> temp;
		//getimage(P_BG[i], temp.c_str(),w, h);
		getimage(P_BG[i], temp.c_str(), w, h);
		ss.clear();
	}
	for (int i = 0; i != 4; ++i)
	{
		B_BG[i] = new Button(x1 + (i - 0) * n_x, y1 + 0 * n_y, w, h - 10, i + 1, P_BG[i]);
	}
	for (int i = 4; i != 8; ++i)
	{
		B_BG[i] = new Button(x1 + (i - 4) * n_x, y1 + 1 * n_y, w, h - 10, i + 1, P_BG[i]);
	}
	for (int i = 8; i != 12; ++i)
	{
		B_BG[i] = new Button(x1 + (i - 8) * n_x, y1 + 2 * n_y, w, h - 10, i + 1, P_BG[i]);
	}


	while (mouseCheck != -1 && mouseCheck != -2 && mouseCheck != -3){
		Button::setbutton(Global::x_0, Global::y_0, Global::x_scr, Global::y_scr);
		mouseCheck = Button::pubutton(Global::x_0, Global::y_0, Global::x_scr, Global::y_scr, 1);
		if (1 <= mouseCheck && mouseCheck < 13){
			check = mouseCheck;
		}
	}
	
	if (1 <=check && check < 13){
		std::ofstream op;
		op.open("OptionBG.txt", std::ios::out);
		if (!op.fail()){
			ss << check;
			ss >> temp;
			op << temp;
			op.close();
		}
	}
	//________________________delete_mode____________________________
	delete B_cut1;
	delete B_cut2;
	delete B_cut3;
	delimage(P_cut1);
	delimage(P_cut2);
	delimage(P_cut3);
	delimage(imageBG);
	for (int i = 0; i != 12; ++i){
		delete B_BG[i];
		delimage(P_BG[i]);
	}		
	flushmouse();
	return mouseCheck;
}
int optionSK(){
	cleardevice();
	std::stringstream ss;
	std::string temp;
	int mouseCheck = 0;
	int trans = 0;
	//基起点
	int x1 = 150, y1 = 100;
	//基高基长
	int w = 540, h = 400;
	//渐增
	int n_x = 580, n_y = 410;
	PIMAGE imageSKIN = newimage();
	PIMAGE P_cut1 = newimage();
	PIMAGE P_cut2 = newimage();
	PIMAGE P_cut3 = newimage();
	getimage(imageSKIN, "resource\\option2.png", 0, 0);
	putimage(0, 0, imageSKIN);
	PIMAGE P_SK[4];
	Button *B_SK[4];
	Button *B_cut1 = new Button(153, 15, 120, 60, -1, P_cut1);
	Button *B_cut2 = new Button(293, 15, 110, 60, -2, P_cut2);
	Button *B_cut3 = new Button(1116,9, 115, 56, -3, P_cut3);
	for (int i = 0; i != 4; ++i){
		P_SK[i] = newimage();
		ss << "resource\\BackGround\\GameBKS\\S" << i + 1 << ".png";
		ss >> temp;
		getimage(P_SK[i], temp.c_str(), w, h);
		ss.clear();
	}
	for (int i = 0; i != 2; ++i)
	{
		B_SK[i] = new Button(x1 + (i - 0) * n_x, y1 + 0 * n_y, w, h - 10, i + 1, P_SK[i]);
	}
	for (int i = 2; i != 4; ++i)
	{
		B_SK[i] = new Button(x1 + (i - 2) * n_x, y1 + 1 * n_y, w, h - 10, i + 1, P_SK[i]);
	}
	//___________________init______________________________
	while (mouseCheck != -1 && mouseCheck != -2 && mouseCheck != -3){
		Button::setbutton(Global::x_0, Global::y_0, Global::x_scr, Global::y_scr);
		mouseCheck = Button::pubutton(Global::x_0, Global::y_0, Global::x_scr, Global::y_scr, 1);
		if (1 <= mouseCheck && mouseCheck < 5)
			trans = mouseCheck;

	}
		std::ofstream op;
	if (1 <= trans && trans < 5){
		op.open("OptionSK.txt", std::ios::out);
		if (!op.fail()){
			ss << trans;
			ss >> temp;
			op << temp;
			op.close();
		}
	}

	//________________delete_mode__________________________
	delete B_cut1;
	delete B_cut2;
	delete B_cut3;
	delimage(P_cut1);
	delimage(P_cut2);
	delimage(P_cut3);
	delimage(imageSKIN);
	for (int i = 0; i != 4; ++i){
		delete B_SK[i];
		delimage(P_SK[i]);
	}
	flushmouse();
	return mouseCheck;
}

void o_option()
{
 	int loopFlag = -1;
	while(loopFlag != -3){
			if (loopFlag == -1)
			loopFlag = optionBK();
			if (loopFlag == -2)
			loopFlag = optionSK();
	}
}
