#include "../../headers/organisms/Plant.hpp"
#include "../../headers/World.hpp"

Plant::Plant(World *world, Position position, char symbol, int color, int strength, int initiative) : Organism(world, position, symbol, color, strength, initiative) {
}

void Plant::take_action() {
	std::uniform_int_distribution<int> probability(0, MAX_PROBABILITY);

	if (probability(this->get_world()->get_rng()) < PROBABILITY_OF_SPREADING) {
		this->spread();
	}
}

void Plant::collide(Organism *organism) {
	Organism::collide(organism);
}

void Plant::spread() {
	this->get_world()->spawn_organism(this->get_type(), this->get_random_free_offset(Organism::all_offsets, OFFSET_COUNT));
}
