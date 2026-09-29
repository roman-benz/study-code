#ifndef HEALER_HPP
#define HEALER_HPP

#include "Mage.hpp"

class Healer : public Mage {
public:
	Healer& heal(Character& target);
};

#endif // !HEALER_HPP