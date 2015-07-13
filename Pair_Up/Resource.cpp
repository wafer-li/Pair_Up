#include "Resource.h"


Resource::Resource()
{
	 exitButton_basic = newimage();
	 optionButton_basic = newimage();
	 newGameButton_basic = newimage();
	 leaderboard_basic = newimage();
	 BK = newimage();
	 exitButton_move = newimage();
	 optionButton_move = newimage();
	 newGameButton_move = newimage();
	 leaderboard_move = newimage();
	 exitButton_press = newimage();
	 optionButton_press = newimage();
	 newGameButton_press = newimage();
	 leaderboard_press = newimage();

	getimage(exitButton_basic, "resource\\exit.png", 0, 0);
	getimage(exitButton_move, "resource\\exit-m.png", 0, 0);
	getimage(exitButton_press, "resource\\exit-on.png", 0, 0);
	getimage(optionButton_basic, "resource\\Option.png", 0, 0);
	getimage(optionButton_move, "resource\\Option-m.png", 0, 0);
	getimage(optionButton_press, "resource\\Option-on.png", 0, 0);
	getimage(newGameButton_basic, "resource\\newGame.png", 0, 0);
	getimage(newGameButton_move, "resource\\newGame-m.png", 0, 0);
	getimage(newGameButton_press, "resource\\newGame-on.png", 0, 0);
	getimage(leaderboard_basic, "resource\\leaderboard.png", 0, 0);
	getimage(leaderboard_move, "resource\\leaderboard-m.png", 0, 0);
	getimage(leaderboard_press, "resource\\leaderboard-on.png", 0, 0);
	getimage(BK, "resource\\BK.png", 0, 0);
}


Resource::~Resource()
{
}
