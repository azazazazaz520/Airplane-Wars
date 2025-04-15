#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "Cursor.h"
struct bullet
{
	static std::vector <bullet> bullets;
	bullet(int x, int y);     //初始化
	void move_bullet();       //移动子弹 
	static void add_bullet(int x,int y);         //添加子弹
	static void update();       //移动每个子弹的位置
	static void display();
	int bullet_x;
	int bullet_y;
};