#include "../../../headers/organisms/animals/Turtle.hpp"
#include "../../../headers/World.hpp"

Turtle::Turtle(World *world, Position position) : Animal(world, position, TURTLE_SYMBOL, PAIR_TURTLE, TURTLE_STRENGTH, TURTLE_INITIATIVE) {
}

void Turtle::take_action() {
	std::uniform_int_distribution<int> move_chance(0, 3); // 1 in 4 chance to move

	if (move_chance(this->get_world()->get_rng()) == 0) {
		Animal::take_action();
	}

}

void Turtle::collide(Organism *organism) {
}
