#include <iostream>
#include <conio.h> // _kbhit(), _getch()
#include <windows.h>
#include "Welcome.h"
#include "Player.h"
#include "Cursor.h"

int main()
{
	//SetConsoleOutputCP(65001); // 设置控制台为UTF-8编码
	srand(time(0));
	welcome();
	HideCursor();         //隐藏光标
	Player player;
	player.Maingame();

	
	
}