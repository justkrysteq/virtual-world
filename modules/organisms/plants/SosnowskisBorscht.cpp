#include "../../../headers/organisms/plants/SosnowskisBorscht.hpp"
#include "../../../headers/World.hpp"

SosnowskisBorscht::SosnowskisBorscht(World *world, Position position) : Plant(world, position, SOSNOWKIS_BORSCHT_SYMBOL, PAIR_SOSNOWKIS_BORSCHT, SOSNOWKIS_BORSCHT_STRENGTH) {
}

void SosnowskisBorscht::take_action() {
	Organism *adjacent_organisms[OFFSET_COUNT];
	int adjacent_organisms_count = 0;

	for (int i = 0; i < OFFSET_COUNT; i++) {
		Position checked_position = this->get_position() + Organism::all_offsets[i];

		if (checked_position > Position{0, 0} && checked_position < Position{this->get_world()->get_width() - 1, this->get_world()->get_height() - 1}) {
			Organism *adjacent_organism = this->get_world()->get_organism(checked_position.x, checked_position.y);

			if (adjacent_organism != nullptr && adjacent_organism->is_animal() && adjacent_organism->get_type() != CYBER_SHEEP) {
				adjacent_organisms[adjacent_organisms_count] = adjacent_organism;
				adjacent_organisms_count++;
			}
		}
	}

	for (int i = 0; i < adjacent_organisms_count; i++) {
		adjacent_organisms[i]->die();
	}

	Plant::take_action();
}

void SosnowskisBorscht::collide(Organism *other) {
	if (other->get_type() == CYBER_SHEEP) {
		return;
	}

	other->die();
}
