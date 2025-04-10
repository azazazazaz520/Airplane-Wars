#ifndef _MYPLANE_H_
#define _MYPLANE_H_

#include <iostream>
#include <conio.h> // _kbhit(), _getch()
#include <windows.h>
#include <vector>
#include "bullet.h"
class Myplane {
private:
	int plane_x;  //飞机的横坐标
	int plane_y;  //飞机的纵坐标
public:
	Myplane();
	void begin();
	void gotoXY(int x, int y);
	void update(char c);
	void Move_plane(int x,int y);     //移动飞机位置，x和y代表在各个方向上移动多少
	void display();


};
#endif // !_MYPLANE_H_