#include "../../../headers/organisms/animals/Turtle.hpp"

Turtle::Turtle(World *world, Position position) : Animal(world, position, TURTLE_SYMBOL, PAIR_TURTLE, TURTLE_STRENGTH, TURTLE_INITIATIVE) {
}

void Turtle::take_action() {
}

void Turtle::collide(Organism *organism) {
}
