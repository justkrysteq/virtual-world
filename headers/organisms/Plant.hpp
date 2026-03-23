#pragma once
#include "../Organism.hpp"

class Plant : public Organism {
public:
	Plant();
	Plant(Position position);
	Plant(int strength, Position position);
	Plant(int strength);

	virtual void take_action();
	virtual void collide();
};
