#include <iostream>
#include <Windows.h>
#include <string>
void welcome()
{
	std::cout << "****************************************************" << std::endl;
	std::cout << "*                 欢迎游玩飞机大战                 *" << std::endl;
	std::cout << "*                  输入1开始游玩                   *" << std::endl;
	std::string input;
	while (true)
	{
		std::cin >> input;
		if (input == "1")
		{
			system("cls");
			break;
		}
	}
}