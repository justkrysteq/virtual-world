#include "../../../headers/World.hpp"

Fox::Fox(World *world, Position position) : Animal(world, position, FOX_SYMBOL, PAIR_FOX, FOX_STRENGTH, FOX_INITIATIVE) {
}

void Fox::take_action() {
	Animal::take_action(this->get_random_free_offset(Organism::all_offsets, OFFSET_COUNT, true), false);
	this->get_world()->add_message(this->get_name() + std::string(" moved to ") + std::to_string(this->get_position().x) + " " + std::to_string(this->get_position().y) + std::string(" avoiding potential collisions"));
}
