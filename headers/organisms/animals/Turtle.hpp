#pragma once

#include "../Animal.hpp"

#define TURTLE_STRENGTH 2
#define TURTLE_INITIATIVE 1
#define TURTLE_SYMBOL 'T'
#define TURTLE_REPEL_STRENGTH 5

class Turtle : public Animal {
public:
	Turtle(World *world, Position position);

	void take_action() override;
	void collide(Organism *other) override;
};
