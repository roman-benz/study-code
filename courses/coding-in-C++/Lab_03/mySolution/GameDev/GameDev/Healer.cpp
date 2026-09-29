#include "Healer.hpp"
#include <stdlib.h>

Healer& Healer::heal(Character& target) {
	if (target.health_points != NULL) {
		if (target.health_points < 91) {
			target.health_points = target.health_points + 10; //Heal by 10hp
		}
		else if (target.health_points < 100 && target.health_points > 90) {
			target.health_points = 100;
		}
	}
	else {
		std::cout << "Ungueltiger target Character!" << std::endl;
		return *this;
	}
	return *this;
}
