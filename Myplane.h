#ifndef _MYPLANE_H_
#define _MYPLANE_H_

#include <iostream>
#include <conio.h> // _kbhit(), _getch()
#include <windows.h>
#include <vector>
#include "Cursor.h"
#include "bullet.h"
#include "Plane_info.h"
#include "Enemy.h"

class Myplane {
private:
	int plane_x;  //�ɻ��ĺ�����
	int plane_y;  //�ɻ���������
	Player_plane Player_plane_1;
	SEnemy enemy;
public:
	Myplane();
	void begin();
	void update(char c);
	void Move_plane(int x,int y);     //�ƶ��ɻ�λ�ã�x��y�����ڸ����������ƶ�����
	void display() const;


};

#endif // !_MYPLANE_H_