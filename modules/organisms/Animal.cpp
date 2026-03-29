#include "../../headers/organisms/Animal.hpp"
#include "../../headers/World.hpp"

Animal::Animal(World *world, Position position, char symbol, int color, int strength, int initiative) : Organism(world, position, symbol, color, strength, initiative) {
}

void Animal::take_action() {
	if (this->get_omit_action()) {
		this->set_omit_action(false);
		return;
	}

	Position offset = this->get_random_offset();
	Position new_position = this->get_position() + offset;

	if (this->get_world()->get_organism(new_position.x, new_position.y) != nullptr) {
		// this->collide(this->get_world()->get_organism(new_position.x, new_position.y));
	} else {
		this->set_position(new_position);
	}
}

void Animal::collide() {
}
