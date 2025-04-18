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

public:
	Player();
	void Maingame();
};
