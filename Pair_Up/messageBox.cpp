#include "messageBox.h"
#include <sstream>
std::string messageBox()
{
	PIMAGE im_input = newimage();
	getimage(im_input, "resource\\InputBox.png", 0, 0);
	putimage_transparent(NULL, im_input, 492, 338, BLACK);
	setbkmode(TRANSPARENT);
    setfont(-36, -20, "Kingdom Hearts");
	setcolor(EGERGB(0, 0, 0));
	key_msg keyboard;
	mouse_msg mouse;
	std::string userInput;
	std::stringstream tempInput;
	std::string tempword;
	char c_tempword[2] = { '\0', '\0' };
	for (;;)
	{
		delay_ms(0);
		if (kbmsg())
		{
			keyboard = getkey();
			tempInput.clear();
			if (keyboard.key >= 48 && keyboard.key <= 57 && keyboard.msg == key_msg_up && userInput.size() <= 12)
			{

				tempInput << keyboard.key - 48;
				tempInput >> tempword;
				userInput.append(tempword);

				outtextxy(84 + 492, 78 + 338, userInput.c_str());
			}
			else if (keyboard.key >= 96 && keyboard.key <= 105 && keyboard.msg == key_msg_up && userInput.size() <= 12)
			{

				tempInput << keyboard.key - 96;
				tempInput >> tempword;
				userInput.append(tempword);

				outtextxy(84 + 492, 78 + 338, userInput.c_str());
			}
			else if (keyboard.key >= 65 && keyboard.key <= 90 && keyboard.flags != key_flag_shift && keyboard.msg == key_msg_up && userInput.size() <= 12)
			{
				c_tempword[0] = 'a' + keyboard.key - 65;

				userInput.append(c_tempword);

				outtextxy(84 + 492, 78 + 338, userInput.c_str());
			}
			else if (keyboard.key >= 65 && keyboard.key <= 90 && keyboard.flags == key_flag_shift && keyboard.msg == key_msg_up && userInput.size() <= 12)// shift + word // Caps + word
			{
				c_tempword[0] = 'A' + keyboard.key - 65;
				userInput.append(c_tempword);

				outtextxy(84 + 492, 78 + 338, userInput.c_str());
			}
			else if (keyboard.key == 8 && keyboard.msg == key_msg_up)//É¾³ı
			{
				if (userInput.length() != 0)
				{
					userInput = userInput.substr(0, userInput.length() - 1);
				}
				putimage(492, 338, im_input);
				outtextxy(84 + 492, 78 + 338, userInput.c_str());
			}
		}
		else if (mousemsg())
		{
			mouse = getmouse();
			if ((mouse.x >= 20 + 492) && (mouse.y >= 136 + 338) && (mouse.x <= 124 + 492) && (mouse.y <= 183 + 338)
				&& mouse.is_left())//ÍË³ö
			{
				userInput.clear();
				return userInput;
			}
			else if ((mouse.x >= 348 + 492) && (mouse.x <= 408 + 492) && (mouse.y >= 135 + 338) && (mouse.y <= 181 + 338)
				&& mouse.is_left())
			{
				return userInput;
			}
		}
	}
}