#include <iostream>
#include <Windows.h>
#include <string>
void welcome()
{
	std::cout << "****************************************************" << std::endl;
	std::cout << "*                 ��ӭ����ɻ���ս                 *" << std::endl;
	std::cout << "*                  ����1��ʼ����                   *" << std::endl;
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