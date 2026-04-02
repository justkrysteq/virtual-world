#include "../../../headers/organisms/animals/Fox.hpp"

Fox::Fox(World *world, Position position) : Animal(world, position, FOX_SYMBOL, PAIR_FOX, FOX_STRENGTH, FOX_INITIATIVE) {
}

void Fox::take_action() {
	Animal::take_action(this->get_random_free_offset(Organism::all_offsets, OFFSET_COUNT, true));
}
