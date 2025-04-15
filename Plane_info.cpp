#include "Plane_info.h"


Player_plane::Player_plane()
{
	line_1 += " /*\\";
	line_2 += "<<*>>";
	line_3 += " * * ";

}
void Player_plane::display1() const
{
	std::cout << line_1 << "\n";

}
void Player_plane::display2() const
{
	std::cout << line_2 << "\n";
}
void Player_plane::display3() const
{
	std::cout << line_3 << "\n";
}