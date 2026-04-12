#include "../../../headers/organisms/plants/SosnowskisBorscht.hpp"
#include "../../../headers/World.hpp"

SosnowskisBorscht::SosnowskisBorscht(World *world, Position position) : Plant(world, position, SOSNOWKIS_BORSCHT_SYMBOL, PAIR_SOSNOWKIS_BORSCHT, SOSNOWKIS_BORSCHT_STRENGTH) {
}

void SosnowskisBorscht::take_action() {
	this->kill_adjacent_organisms(true, true); // TODO: Implement: print killed organisms

	Plant::take_action();
}

void SosnowskisBorscht::collide(Organism *other) { // TODO: Implement: print collision
	if (other->get_type() == CYBER_SHEEP) {
		this->die();
		other->move(this->get_position());

		return;
	}

	other->die();
}
