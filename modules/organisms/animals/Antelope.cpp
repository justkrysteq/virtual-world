#include "../../../headers/organisms/animals/Antelope.hpp"
#include "../../../headers/World.hpp"
Antelope::Antelope(World *world, Position position) : Animal(world, position, ANTELOPE_SYMBOL, PAIR_ANTELOPE, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE) {
}

void Antelope::take_action() {
	Animal::take_action(this->get_random_offset(this->antelope_offsets, ANTELOPE_OFFSET_COUNT));
}

void Antelope::collide(Organism *other) {
	std::uniform_int_distribution<int> escape_chance(0, 1); // 1 in 2 chance to escape
	
	if (escape_chance(this->get_world()->get_rng()) == 0 && other->get_type() != ANTELOPE) {
		this->move(this->get_position() + this->get_random_offset());
		return;
	}

	Animal::collide(other);
}
