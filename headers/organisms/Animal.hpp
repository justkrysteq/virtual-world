#pragma once
#include "../Organism.hpp"

class Animal : public Organism {
public:
	Animal(
		World *world,
		Position position,
		char symbol,
		int color,
		int strength = 0,
		int initiative = 0
	);

	virtual void take_action();
	virtual void collide();
};
