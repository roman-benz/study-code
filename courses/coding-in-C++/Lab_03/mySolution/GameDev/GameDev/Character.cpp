#include "Characater.hpp"
#include <iostream>

void Character::display() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "HP: " << health_points << std::endl;
	std::cout << "LVL: " << level << std::endl;
}



