#include "../../../headers/organisms/animals/CyberSheep.hpp"

#include <ncurses.h>

CyberSheep::CyberSheep(World *world, Position position) : Animal(world, position, CYBER_SHEEP_SYMBOL, PAIR_CYBER_SHEEP, CYBER_SHEEP_STRENGTH, CYBER_SHEEP_INITIATIVE) {
}

void CyberSheep::take_action() {
	if (this->get_closest_of_type(SOSNOWKIS_BORSCHT) == nullptr) {
		Animal::take_action();

		return;
	}

	Organism *closest_sosnowskis_borscht = this->get_closest_of_type(SOSNOWKIS_BORSCHT);
	Position delta_pos = this->get_position() - closest_sosnowskis_borscht->get_position();

	Position offset = Position{(int) (delta_pos.x < 0) - (int) (delta_pos.x > 0), (int) (delta_pos.y < 0) - (int) (delta_pos.y > 0)};

	Animal::take_action(offset);
}
