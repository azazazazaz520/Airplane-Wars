#pragma once
#include <iostream>
#include <vector>
#include <string>
class SEnemy {
private:
	int nCreateTime;
	int Move_time;		 //
	
	
	std::string line_1;
	std::string line_2;

	int nMoveTime;

public:
	int enemy_x;         //横坐标
	int enemy_y;         //纵坐标
	std::vector<SEnemy> vecEnemy;          //存放敌人的vector数组
	SEnemy();
    void update();
	void add_enemy();
	void init_enemy_date(int x,int y);          //初始化敌人位置数据
	void Move_Enemy();
	void display() const;
	bool isExist(int x,int y) const;

};