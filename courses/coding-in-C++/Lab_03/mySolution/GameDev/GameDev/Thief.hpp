#ifndef THIEF_HPP
#define THIEF_HPP

#include "Warrior.hpp"

class Thief : public Warrior {
public:
	Thief& steal(Character& target);
};

#endif // !HEALER_HPP