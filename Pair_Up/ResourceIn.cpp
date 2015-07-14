#include "test.h"

int ResourceIn(){
	Option opt;
	std::string temp;
	std::stringstream ss;
	PIMAGE BG;                      
	PIMAGE TYPEALL[6][6];
	PIMAGE DP;             
	BG = newimage();
	DP = newimage();

	for (int i = 0; i != 6; ++i){
		for (int j = 0; j != 6; ++j)
		{
			TYPEALL[i][j] = newimage();
			ss << "resource\\skin" << opt.getSkin() << "\\Skin" << opt.getSkin() << "_Piece_" << i + 1 << "_" << j << ".png";
			ss >> temp;
			getimage(TYPEALL[i][j], temp.c_str(), 0, 0);
			ss.clear();
		}
	}

	ss << "resource\\skin" << opt.getSkin() << "\\Skin" << opt.getSkin() << "_Piece_Clear.png";
	ss >> temp;
	getimage(DP, temp.c_str(), 0, 0);
	ss.clear();
	ss << "resource\\BackGround\\GameBk" << opt.getBackground() << ".png";
	ss >> temp;
	getimage(BG, temp.c_str(), 0, 0);
	ss.clear();

	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			putimage(i*100, j*100, TYPEALL[i][j]);
		}
	}
	return 1;
}