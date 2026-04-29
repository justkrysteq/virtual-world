#include "../../../headers/organisms/plants/SosnowskisBorscht.hpp"
#include "../../../headers/World.hpp"

SosnowskisBorscht::SosnowskisBorscht(World *world, Position position) : Plant(world, position, SOSNOWKIS_BORSCHT_SYMBOL, PAIR_SOSNOWKIS_BORSCHT, SOSNOWKIS_BORSCHT_STRENGTH) {
}

void SosnowskisBorscht::take_action() {
	this->kill_adjacent_organisms(true, true);

	Plant::take_action();
}

void SosnowskisBorscht::collide(Organism *other) {
	if (other->get_type() == CYBER_SHEEP) {
		this->die();
		other->move(this->get_position());
		this->get_world()->add_message(this->get_name() + std::string(" was eaten by ") + other->get_name());

		return;
	}

	this->die();
	other->die();
	this->get_world()->add_message(this->get_name() + std::string(" was eaten by ") + other->get_name());
	other->get_world()->add_message(other->get_name() + std::string(" dies from eating ") + this->get_name());
}
