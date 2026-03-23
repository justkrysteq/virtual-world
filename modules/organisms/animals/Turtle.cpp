#include "../../../headers/organisms/animals/Turtle.hpp"

Turtle::Turtle() : Animal(TURTLE_STRENGTH, TURTLE_INITIATIVE) {
}

Turtle::Turtle(Position position) : Animal(TURTLE_STRENGTH, TURTLE_INITIATIVE, position) {
}

void Turtle::take_action() {
}

void Turtle::collide() {
}
