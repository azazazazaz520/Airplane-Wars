#include "Enemy.h"
#include "stdafx.h"
#include "Cursor.h"
SEnemy::SEnemy()
{
	this->Create_time = 0;
	Move_time = 0;
	enemy_x = 0;
	enemy_y = 0;
	line_1 += "\\+/";
	line_2 += "| ";
}
void SEnemy::update()
{
	//Sleep(50);
	if (vecEnemy.size() < 10)
	{
		//Create_time = 0;          //����������ʱ����
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
	const int min_spacing = 3; // ��С���
	bool valid_position = false;
	while (!valid_position)
	{
		rad_enemy_x = rand() % 78;           //�������x����
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
	Enemy.init_enemy_date(rad_enemy_x, 0);   
	vecEnemy.push_back(Enemy);
}

void SEnemy::Move_Enemy()
{
	if (enemy_y < 24) {
		enemy_y++; // ���������ƶ�
	}
	
}
void SEnemy::display() const
{
	for (auto& e : vecEnemy)
	{
		/*�����һ���ƶ�ǰ���˵�ͼ��*/
		if (e.enemy_y > 24 || e.enemy_y < 0)
			continue;
		gotoXY(e.enemy_x - 2, e.enemy_y);
		cout << "   ";
		gotoXY(e.enemy_x - 2, e.enemy_y - 1);
		cout << "   ";
		gotoXY(e.enemy_x - 2, e.enemy_y + 1);
		cout << "   "; 
		gotoXY(e.enemy_x - 2, e.enemy_y + 2);
		cout << "   ";
		gotoXY(e.enemy_x - 2, e.enemy_y - 2);
		cout << "   ";

		/*ˢ�µ���ͼ��*/
		if (e.enemy_y <= 24)
		{
			gotoXY(e.enemy_x - 2, e.enemy_y);
			cout << line_1;
			gotoXY(e.enemy_x - 1, e.enemy_y + 1);
			cout << line_2;
		}
		gotoXY(0, 23);
		cout << string(100, ' '); // ��������ײ���
		gotoXY(0, 24);
		cout << string(100, ' '); // ��������ײ���
		gotoXY(0, 25);
		cout << string(100, ' '); // ��������ײ���
	}
}