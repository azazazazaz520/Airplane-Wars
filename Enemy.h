#pragma once
#include <iostream>
#include <vector>
#include <string>
class SEnemy {
private:
	int nCreateTime;
	int Move_time;		 //
	int enemy_x;         //������
	int enemy_y;         //������
	std::vector<SEnemy> vecEnemy;          //��ŵ��˵�vector����
	std::string line_1;
	std::string line_2;

	int nMoveTime;

public:
	SEnemy();
    void update();
	void add_enemy();
	void init_enemy_date(int x,int y);          //��ʼ������λ������
	void Move_Enemy();
	void display() const;

};