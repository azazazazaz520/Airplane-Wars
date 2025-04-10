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
	gotoXY(last_x - 1, last_y);
	std::cout << "   ";  // 用空格覆盖原有内容
	
	gotoXY(plane_x - 1, plane_y);
	std::cout << "xox";
	last_x = plane_x;
	last_y = plane_y;
}

void Myplane::update(char c)
{
	switch (c)
	{
	case 'a': Move_plane(-1, 0); break;
	case 'd': Move_plane(1, 0); break;
	case 'w': Move_plane(0, -1); break;
	case 's': Move_plane(0, 1); break;
	case 27: exit(0); break;
		
	}
}


void Myplane::Move_plane(int x,int y)
{
	const int min_x = 1, max_x = 78;
	const int min_y = 1, max_y = 24;
	if (plane_x + x >= min_x && plane_x + x <= max_x)
		plane_x += x;
	if (plane_y + y >= min_y && plane_y + y <= max_y)
		plane_y += y;
	
	
}

void Myplane::gotoXY(int x, int y)  
{  
 COORD pos = { x, y };  
 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄  
 SetConsoleCursorPosition(hOut, pos); // 两参数分别是指定哪个窗体，具体位置  
}  