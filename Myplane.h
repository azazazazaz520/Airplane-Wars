#ifndef _MYPLANE_H_
#define _MYPLANE_H_

#include <iostream>
#include <conio.h> // _kbhit(), _getch()
#include <windows.h>
#include <vector>
#include "bullet.h"
class Myplane {
private:
	int plane_x;  //�ɻ��ĺ�����
	int plane_y;  //�ɻ���������
public:
	Myplane();
	void begin();
	void gotoXY(int x, int y);
	void update(char c);
	void Move_plane(int x,int y);     //�ƶ��ɻ�λ�ã�x��y�����ڸ����������ƶ�����
	void display();


};
#endif // !_MYPLANE_H_