#include "Enemy.h"
#include "stdafx.h"
#include "Cursor.h"
SEnemy::SEnemy()
{
	nCreateTime = 0;
	nMoveTime = 0;
	Move_time = 0;
	enemy_x = 0;
	enemy_y = 0;
	line_1 += "\\+/";
	line_2 += "| ";
}
void SEnemy::update()
{
	nCreateTime++;
	if (nCreateTime >= 20 && vecEnemy.size() < 10)
	{
		nCreateTime = 0;          //创建敌人有时间间隔
		add_enemy();
	}

	for (auto& e : vecEnemy)
	{
		e.Move_Enemy();
	}
	vecEnemy.erase(std::remove_if(vecEnemy.begin(), vecEnemy.end(),
		[](const SEnemy& e) { return e.enemy_y > 23; }), vecEnemy.end());
}

void SEnemy::init_enemy_date(int x,int y)
{
	enemy_x = x;
	enemy_y = y;
}

void SEnemy::add_enemy()
{
	SEnemy Enemy;
	int rad_enemy_x;
	const int min_spacing = 3; // 最小间隔
	bool valid_position = false;
	while (!valid_position)
	{
		rad_enemy_x = rand() % 78 + 2;           //随机敌人x坐标
		valid_position = true;
		for (const auto& e : vecEnemy)
		{
			if (abs(e.enemy_x - rad_enemy_x) < min_spacing)
			{
				valid_position = false;
				break;
			}
		}
	}
	Enemy.init_enemy_date(rad_enemy_x, 2);   
	vecEnemy.push_back(Enemy);
}

void SEnemy::Move_Enemy()
{
	nMoveTime++;
	if (nMoveTime > 5)
	{
		nMoveTime = 0;
		enemy_y++; // 敌人向下移动
	}
	
}
void SEnemy::display() const
{
	for (auto& e : vecEnemy)
	{
		/*清除上一次移动前敌人的图标*/
		/*if (e.enemy_y > 24 || e.enemy_y < 0)
			continue;*/
		if (e.enemy_y - 1 >= 0) {
			gotoXY(e.enemy_x - 2, e.enemy_y - 1);
			std::cout << "   ";  // line_1 (上次位置)
			gotoXY(e.enemy_x - 1, e.enemy_y);
			std::cout << "   ";  // line_2 (上次位置)
		}

		/*刷新敌人图标*/
		if (e.enemy_y <= 22)
		{
			gotoXY(e.enemy_x - 2, e.enemy_y);
			cout << line_1;
			gotoXY(e.enemy_x - 1, e.enemy_y + 1);
			cout << line_2;
		}
		//gotoXY(0, 23);
		//cout << string(100, ' '); // 清除整个底部行
		//gotoXY(0, 24);
		//cout << string(100, ' '); // 清除整个底部行
		//gotoXY(0, 25);
		//cout << string(100, ' '); // 清除整个底部行
	}
}



bool SEnemy::isExist(int x,int y) const
{
	if (x == enemy_x && y == enemy_y)
	{
		return true;
	}
	else
	{
		return false;
	}
}