#include "../../headers/organisms/Animal.hpp"
#include "../../headers/World.hpp"

Animal::Animal(World *world, Position position, char symbol, int color, int strength, int initiative) : Organism(world, position, symbol, color, strength, initiative) {
}

void Animal::take_action() { // TODO: IMPORTANT: YOU NEED TO CHECK WORLD BOUNDARIES
	if (this->get_omit_action()) {
		this->set_omit_action(false);
		return;
	}

	Position offset = this->get_random_offset();
	Position new_position = this->get_position() + offset;

	if (this->get_world()->get_organism(new_position.x, new_position.y) != nullptr) {
		this->get_world()->get_organism(new_position.x, new_position.y)->collide(this);
	} else {
		this->move(new_position);
		// TODO: Print: Organism moved to {new_position.x, new_position.y}
	}
}

void Animal::collide(Organism *other) {
	if (this->get_type() == other->get_type()) {
		this->breed(other);
		return;
	}

	Organism::collide(other);
}

void Animal::breed(Organism *other) { // TODO: Check if positions for offspring are valid
	this->set_omit_action(true);

	Position offset_for_offspring = this->choose_offset_for_offspring(other);
	this->get_world()->spawn_organism(this->get_type(), this->get_position() + offset_for_offspring);

	return;
}

Position Animal::choose_offset_for_offspring(Organism *other) { // Sets would solve this way easier
	Position offsets[OFFSET_COUNT*2];
	Position offset_to_other = this->get_position() - other->get_position();
	
	int offsets_count = 0;

	for (int i = 0; i < OFFSET_COUNT; i++) {
		if (offsets[i] == offset_to_other) {
			continue;
		}

		offsets[i] = Organism::all_offsets[i];
		offsets_count++;
	}

	for (int i = 0; i < OFFSET_COUNT; i++) {
		Position other_offset = Organism::all_offsets[i] + offset_to_other;

		if (other_offset == Position{0, 0}) {
			continue;
		}

		bool is_offset_included = false;

		for (int j = 0; j < OFFSET_COUNT; j++) {
			if (other_offset == offsets[j]) {
				is_offset_included = true;
				break;
			}
		}

		if (!is_offset_included) {
			offsets[offsets_count] = other_offset;
			offsets_count++;
		}
	}

	return this->get_random_free_offset(offsets, offsets_count);
}

bool Animal::get_omit_action() const {
	return this->omit_action;
}

void Animal::set_omit_action(bool omit_action) {
	this->omit_action = omit_action;
}
