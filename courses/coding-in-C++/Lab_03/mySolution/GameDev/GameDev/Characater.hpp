#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <stdlib.h>
#include <string>
#include <iostream>
#include "Inventory.hpp"

class Character {
protected:
	std::string name;
	uint8_t health_points = 100;
	uint8_t level = 0;
	Inventory inventory;
	static constexpr uint8_t MAX_HP = 100;
	static constexpr uint8_t MAX_LEVEL = 10;
	static constexpr uint8_t XP_TRESHOLD = 100;
public:
	void display();	
	void levelUp();

	friend class Healer;
};

#endif // !CHARCATER_HPP