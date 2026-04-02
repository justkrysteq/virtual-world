#include "../../headers/organisms/Animal.hpp"
#include "../../headers/World.hpp"

Animal::Animal(World *world, Position position, char symbol, int color, int strength, int initiative) : Organism(world, position, symbol, color, strength, initiative) {
}

void Animal::take_action(const Position &offset) {
	if (this->get_omit_action()) {
		this->set_omit_action(false);
		return;
	}

	if (!this->get_is_alive()) {
		return;
	}

	if (offset == Position{0, 0}) {
		return;
	}

	Position new_position = this->get_position() + offset;

	if (this->get_world()->get_organism(new_position.x, new_position.y) != nullptr) {
		this->get_world()->get_organism(new_position.x, new_position.y)->collide(this);
	} else {
		this->move(new_position);
		// TODO: Print: Organism moved to {new_position.x, new_position.y}
	}
}

void Animal::take_action() {
	this->take_action(this->get_random_offset());
}

void Animal::collide(Organism *other) {
	if (this->get_type() == other->get_type()) {
		this->breed(other);
		return;
	}

	Organism::collide(other);
}

void Animal::breed(Organism *other) {
	this->set_omit_action(true);

	Position offset_for_offspring = this->choose_offset_for_offspring(other);

	if (offset_for_offspring == Position{0, 0}) {
		return;
	}

	this->get_world()->spawn_organism(this->get_type(), this->get_position() + offset_for_offspring);
}

Position Animal::choose_offset_for_offspring(Organism *other) { // Sets would solve this way easier
	Position offsets[OFFSET_COUNT*2];
	Position offset_to_other = other->get_position() - this->get_position();
	
	int offsets_count = 0;

	for (int i = 0; i < OFFSET_COUNT; i++) {
		offsets[offsets_count] = Organism::all_offsets[i];

		if (offsets[offsets_count] == offset_to_other) {
			continue;
		}

		offsets_count++;
	}

	for (int i = 0; i < OFFSET_COUNT; i++) {
		Position other_offset = Organism::all_offsets[i] + offset_to_other;

		if (other_offset == Position{0, 0}) {
			continue;
		}

		bool is_offset_included = false;

		for (int j = 0; j < offsets_count; j++) {
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
