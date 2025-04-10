#include "Myplane.h"  

Myplane::Myplane() : plane_x(25), plane_y(15)
{  

}  

void Myplane::begin()  
{  
	gotoXY(plane_x, plane_y);  
	std::cout << "xx" << std::endl;
	bullet _bullet(plane_x, plane_y);
	char flag;
	while (true)
	{
		Sleep(100);
		
		//std::cout << "创建了一个子弹！" << std::endl;
		
		
		if (_kbhit())
		{
			flag = _getch();
			update(flag);
		}		
		
		
		_bullet.add_bullet(plane_x, plane_y);
		_bullet.update();
		_bullet.display();
		display();
		
	}
}  

 
void Myplane::display()
{
	static int last_x = plane_x, last_y = plane_y;
	gotoXY(last_x, last_y);
	std::cout << "  ";  // 用空格覆盖原有内容
	
	gotoXY(plane_x, plane_y);
	std::cout << "xx";
	last_x = plane_x;
	last_y = plane_y;
}

void Myplane::update(char c)
{
	switch (c)
	{
	case 'a' : Move_plane(-1, 0); break;
	case 'd': Move_plane(1, 0); break;
	case 'w': Move_plane(0, -1); break;
	case 's': Move_plane(0, 1); break;
	case '27': exit(0);
		break;
	}
}


void Myplane::Move_plane(int x,int y)
{
	plane_x += x;
	plane_y += y;
}

void Myplane::gotoXY(int x, int y)  
{  
 COORD pos = { x, y };  
 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄  
 SetConsoleCursorPosition(hOut, pos); // 两参数分别是指定哪个窗体，具体位置  
}  