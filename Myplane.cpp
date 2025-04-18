#include "Myplane.h"  

Myplane::Myplane() : plane_x(25), plane_y(15)         //初始化飞机位置
{  
  
}  

void Myplane::display() const
{
  static int last_x = plane_x, last_y = plane_y;
  gotoXY(last_x - 2, last_y-1);
  std::cout << "      ";
  gotoXY(last_x - 3, last_y);
  std::cout << "      ";
  gotoXY(last_x - 4, last_y + 1);
  std::cout << "        ";
  gotoXY(last_x - 4, last_y + 2);
  std::cout << "        ";
  gotoXY(last_x - 4, last_y + 3);
  std::cout << "        ";


  gotoXY(last_x - 2, last_y);
  Player_plane_1.display1();
  gotoXY(last_x - 2, last_y + 1);
  Player_plane_1.display2();
  gotoXY(last_x - 2, last_y + 2);
  Player_plane_1.display3();
  
  last_x = plane_x;
  last_y = plane_y;
}


void Myplane::update(char c)
{
  switch (c)
  {
      case 'a': Move_plane(-1, 0); break;
      case 'd': Move_plane(1, 0); break;
      case 'w': Move_plane(0, -1); break;
      case 's': Move_plane(0, 1); break;
      case 27: exit(0); break;
  }
}

void Myplane::Move_plane(int x, int y)
{
  const int min_x = 1, max_x = 78;
  const int min_y = 1, max_y = 24;
  if (plane_x + x - 3 >= min_x && plane_x + x <= max_x)
      plane_x += x;
  if (plane_y + y - 2 >= min_y && plane_y + y <= max_y)
      plane_y += y;
}