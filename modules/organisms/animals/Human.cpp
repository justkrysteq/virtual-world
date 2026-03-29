#include "../../../headers/organisms/animals/Human.hpp"

Human::Human(World *world, Position position) : Animal(world, position, HUMAN_SYMBOL, PAIR_HUMAN, HUMAN_STRENGTH, HUMAN_INITIATIVE) {
}

void Human::take_action() {
}

void Human::collide() {
}
