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
		this->get_world()->get_organism(new_position.x, new_position.y)->collide(this);
	} else {
		this->set_position(new_position);
		// TODO: Print: Organism moved to {new_position.x, new_position.y}
	}
}

void Animal::collide(Organism *other) {
	if (typeid(this) == typeid(other)) {
		this->breed(other);
	}

	if (this->get_strength() > other->get_strength()) {
		other->die();

		return;
	}

	this->die();
	other->set_position(this->get_position());
}

void Animal::breed(Organism *other) {
	this->set_omit_action(true);

	Position offset_for_offspring = this->choose_offset_for_offspring(other);
	this->get_world()->spawn_organism(this->get_type(), this->get_position() + offset_for_offspring);

	return;
}

Position Animal::choose_offset_for_offspring(Organism *other) {
	Position offsets[OFFSET_COUNT*2];
	Position offset_to_other = this->get_position() - other->get_position();

	for (int i = 0; i < OFFSET_COUNT; i++) {
		offsets[i] = Organism::all_offsets[i];
	}
	
	int offsets_count = OFFSET_COUNT;

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
			offsets[i+OFFSET_COUNT] = other_offset;
			offsets_count++;
		}
	}

	bool occupied[OFFSET_COUNT*2];

	for (int i = 0; i < offsets_count; i++) {
		if (this->get_world()->get_organism(this->get_position().x + offsets[i].x, this->get_position().y + offsets[i].y) != nullptr) {
			occupied[i] = true;
		}
	}

	Position available_offsets[OFFSET_COUNT*2];
	int available_offsets_count = 0;

	for (int i = 0; i < offsets_count; i++) {
		if (!occupied[i]) {
			available_offsets[available_offsets_count] = offsets[i];
			available_offsets_count++;
		}
	}

	std::uniform_int_distribution<int> offset_index(0, available_offsets_count);

	return available_offsets[offset_index(this->get_world()->get_rng())];
}

bool Animal::get_omit_action() const {
	return this->omit_action;
}

void Animal::set_omit_action(bool omit_action) {
	this->omit_action = omit_action;
}
