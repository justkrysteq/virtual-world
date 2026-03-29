#pragma once

#include "../Organism.hpp"

#define PROBABILITY_OF_SPREADING 3
#define MAX_PROBABILITY 100

class Plant : public Organism {
public:
	Plant(
		World *world,
		Position position,
		char symbol,
		int color,
		int strength = 0,
		int initiative = 0
	);

	virtual void take_action();
	virtual void collide(Organism *organism);
	void spread();
};
