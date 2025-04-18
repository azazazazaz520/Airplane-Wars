#include "Player.h"



Player::Player()
{

}


void Player::Maingame()
{
    int plane_x = myplane.Getx();
    int plane_y = myplane.Gety();
    gotoXY(plane_x, plane_y);
	bullet _bullet(plane_x, plane_y);

    char flag;
    while (true)
    {
        Sleep(20);
        plane_x = myplane.Getx();
        plane_y = myplane.Gety();
        if (_kbhit())
        {
            flag = _getch();
            myplane.update(flag);
        }

        myplane.display();
        _bullet.update();
        
       
        _bullet.display();
        _bullet.add_bullet(plane_x, plane_y);

        enemy.update();
        enemy.display();



    }
}