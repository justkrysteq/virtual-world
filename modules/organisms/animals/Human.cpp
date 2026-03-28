#include "../../../headers/organisms/animals/Human.hpp"

Human::Human() : Animal(HUMAN_STRENGTH, HUMAN_INITIATIVE, HUMAN_SYMBOL, PAIR_HUMAN) {
}

Human::Human(Position position) : Animal(HUMAN_STRENGTH, HUMAN_INITIATIVE, position, HUMAN_SYMBOL, PAIR_HUMAN) {
}

void Human::take_action() {
}

void Human::collide() {
}
