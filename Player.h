#pragma once

//π‹¿Ìenemy£¨bullet£¨myplane¿‡


#include <iostream>
#include "Enemy.h"
#include "bullet.h"
#include "Myplane.h"
class Player 
{
private:
	
	SEnemy enemy;
	Myplane myplane;

	int plane_x ;
	int plane_y ;
	int myscore;

public:
	Player();
	void Maingame();
	void onCollision(const bullet& b);
	void score();
	
};
