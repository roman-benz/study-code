#include "Mage.hpp"
#include <iostream>

void Mage::display(){
	std::cout << "Name: " << name << std::endl;
	std::cout << "Type: " << "Mage" << std::endl;
	std::cout << "HP: " << health_points << std::endl;
	std::cout << "Mana Points: " << mana_points << std::endl;
	std::cout << "LVL: " << level << std::endl;
}

