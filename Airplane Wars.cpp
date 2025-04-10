#include <iostream>
#include <conio.h> // _kbhit(), _getch()
#include <windows.h>
#include "Welcome.h"
#include "Myplane.h"
int main()
{
	//SetConsoleOutputCP(65001); // 设置控制台为UTF-8编码
	welcome();
	Myplane myplane;
	myplane.begin();
	system("pause");
}