#pragma once
#include "../Organism.hpp"

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
};
