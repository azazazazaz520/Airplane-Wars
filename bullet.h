#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "Cursor.h"
struct bullet
{
	static std::vector <bullet> bullets;
	bullet(int x, int y);     //��ʼ��
	void move_bullet();       //�ƶ��ӵ� 
	static void add_bullet(int x,int y);         //����ӵ�
	static void update();       //�ƶ�ÿ���ӵ���λ��
	static void display();
	int bullet_x;
	int bullet_y;
};