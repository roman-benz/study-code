#include "Warrior.hpp"
#include <iostream>

void Warrior::display() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Type: " << "Warrior" << std::endl;
	std::cout << "HP: " << health_points << std::endl;
	std::cout << "Weapon Skill Points: " << weapon_skill_points << std::endl;
	std::cout << "LVL: " << level << std::endl;
}