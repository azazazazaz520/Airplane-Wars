#ifndef _MYPLANE_H_
#define _MYPLANE_H_

#include <iostream>
#include <conio.h> // _kbhit(), _getch()
#include <windows.h>
#include <vector>
#include "Cursor.h"
#include "bullet.h"
#include "Plane_info.h"


class Myplane{
private:
	int plane_x;  //飞机的横坐标
	int plane_y;  //飞机的纵坐标
	Player_plane Player_plane_1;
public:
	Myplane();
	//void begin();
	void update(char c);
	void Move_plane(int x,int y);     //移动飞机位置，x和y代表在各个方向上移动多少
	void display() const;
	int Getx() { return plane_x; }
	int Gety() { return plane_y; }
};

#endif // !_MYPLANE_H_