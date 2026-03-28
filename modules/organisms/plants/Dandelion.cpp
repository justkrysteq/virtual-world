#include "../../../headers/organisms/plants/Dandelion.hpp"

Dandelion::Dandelion() : Plant(DANDELION_SYMBOL, PAIR_DANDELION) {
}

Dandelion::Dandelion(Position position) : Plant(position, DANDELION_SYMBOL, PAIR_DANDELION) {
}

void Dandelion::take_action() {
}
