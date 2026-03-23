#include "../../../headers/organisms/animals/Human.hpp"

Human::Human() : Animal(HUMAN_STRENGTH, HUMAN_INITIATIVE) {
}

Human::Human(Position position) : Animal(HUMAN_STRENGTH, HUMAN_INITIATIVE, position) {
}

void Human::take_action() {
}

void Human::collide() {
}
