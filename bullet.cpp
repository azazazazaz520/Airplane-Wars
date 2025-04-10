#include "bullet.h"
#include <algorithm>
std::vector<bullet> bullet::bullets;
bullet::bullet(int x, int y)        // 初始化一个子弹
{
   bullet_x = x;
   bullet_y = y;
}

void bullet::move_bullet()          // 移动子弹
{
   bullet_y--;
}

void bullet::add_bullet(int x, int y)
{
	bullets.emplace_back(x, y);            //添加一个子弹进入vector数组  
}

void bullet::update()
{
	/*for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move_bullet();
	}
	for (int i = bullets.size() - 1; i >= 0; i--)
	{
		if (bullets[i].bullet_y <= 0)
		{
			bullets.erase(bullets.begin()+ i);
		}
	}*/
	for (auto& b : bullets) b.move_bullet();
	bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
		[](const bullet& b) { return b.bullet_y <= 0; }), bullets.end());
}
void bullet::display()
{
    for (auto& b : bullets) {
        // 清除旧位置
		for (int i = 0; i < b.bullets.size(); i++)
		{
			gotoXY(b.bullet_x, 1);
			std::cout << " ";
			gotoXY(b.bullet_x - 1, 1);
			std::cout << " ";
			gotoXY(b.bullet_x + 1, 1);
			std::cout << " ";
		}
		if (b.bullet_y + 1 >= 0)
		{
			gotoXY(b.bullet_x, b.bullet_y + 1);
			std::cout << " ";
		}
		
        // 绘制新位置
		if (b.bullet_y > 0)
		{
			gotoXY(b.bullet_x, b.bullet_y);
			std::cout << "*";
		}
		else
		{
			gotoXY(b.bullet_x, 0);
			std::cout << " ";
		}
        
    }
}

void bullet::gotoXY(int x, int y)       //光标移动函数
{
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄  
	SetConsoleCursorPosition(hOut, pos); // 两参数分别是指定哪个窗体，具体位置  
}


