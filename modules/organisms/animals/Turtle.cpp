#include "../../../headers/organisms/animals/Turtle.hpp"

Turtle::Turtle() : Animal(TURTLE_STRENGTH, TURTLE_INITIATIVE, TURTLE_SYMBOL, PAIR_TURTLE) {
}

Turtle::Turtle(Position position) : Animal(TURTLE_STRENGTH, TURTLE_INITIATIVE, position, TURTLE_SYMBOL, PAIR_TURTLE) {
}

void Turtle::take_action() {
}

void Turtle::collide() {
}
