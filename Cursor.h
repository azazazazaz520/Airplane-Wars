#pragma once
inline void gotoXY(short x, short y) //����ƶ���(x,y)λ��
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//�������ֱ���ָ���ĸ����壬����λ��
}
inline void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//�ڶ���ֵΪ0��ʾ���ع��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}