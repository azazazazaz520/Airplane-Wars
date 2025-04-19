#include "Player.h"
using namespace std;


Player::Player()
{
    plane_x = myplane.Getx();
    plane_y = myplane.Gety();
    myscore = 0;
}


void Player::onCollision(const bullet& b)
{
    for (int i = b.bullets.size() - 1; i >= 0; i--)
    {
        bool bRemoveEenemy = false;
        for (int j = enemy.vecEnemy.size() - 1; j >= 0; j--)
        {
            bool is_enemy = enemy.vecEnemy[j].isExist(b.bullets[i].bullet_x, b.bullets[i].bullet_y);
            if (is_enemy == true)
            {
                
                gotoXY(b.bullets[i].bullet_x, b.bullets[i].bullet_y);
                std::cout << " ";
                gotoXY(enemy.vecEnemy[j].enemy_x - 2, enemy.vecEnemy[j].enemy_y - 2);
                cout << "   ";
                gotoXY(enemy.vecEnemy[j].enemy_x-2, enemy.vecEnemy[j].enemy_y);
                cout << "   ";
                gotoXY(enemy.vecEnemy[j].enemy_x-2, enemy.vecEnemy[j].enemy_y-1);
                cout << "   ";
                gotoXY(enemy.vecEnemy[j].enemy_x-2, enemy.vecEnemy[j].enemy_y+1);
                cout << "   ";
                gotoXY(enemy.vecEnemy[j].enemy_x-2, enemy.vecEnemy[j].enemy_y+2);
                cout << "   ";


                enemy.vecEnemy.erase(enemy.vecEnemy.begin() + j);
                b.bullets.erase(b.bullets.begin() + i);
                myscore++;
                break;
            }
        }
    }
}



void Player::Maingame()
{
    
    gotoXY(plane_x, plane_y);
    bullet _bullet(plane_x, plane_y);

    char flag;
    while (true)
    {
        Sleep(16);
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
        onCollision(_bullet);
        score();
        gotoXY(0, 1);
        cout << string(100, ' '); 
    }
}


void Player::score()
{
    gotoXY(80, 0);
    std::cout << "×Ü¼Æ£º" << myscore;
   

}