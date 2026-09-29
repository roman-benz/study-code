
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <cstdint>
#include <stdlib.h>
#include "Weapon.hpp"

class Inventory {
private:
	static constexpr uint8_t MAX_WEAPONS = 10;
	Weapon weapons[MAX_WEAPONS];
public:
	bool isEmpty() const;
	bool isFull() const;
	bool addItem(const std::string& item);
	bool removeLastItem(std::string& item);
	
};


#endif // !INVENTORY_HPP
