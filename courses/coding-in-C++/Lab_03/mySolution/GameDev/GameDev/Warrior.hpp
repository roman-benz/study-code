#include "Characater.hpp"

class Warrior : public Character {
protected:
	uint8_t weapon_skill_points;
public:
	void display();
};