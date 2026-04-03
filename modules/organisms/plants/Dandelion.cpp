#include "../../../headers/organisms/plants/Dandelion.hpp"

Dandelion::Dandelion(World *world, Position position) : Plant(world, position, DANDELION_SYMBOL, PAIR_DANDELION) {
}

void Dandelion::take_action() {
	for (int i = 0; i < DANDELION_SPREAD_TRIES; i++) {
		Plant::take_action();
	}
}
