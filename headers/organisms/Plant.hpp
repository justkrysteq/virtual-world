#pragma once
#include "../Organism.hpp"

class Plant : public Organism {
public:
	Plant();
	Plant(Position position);
	Plant(int strength, Position position);
	Plant(int strength);
	Plant(char symbol, int color);
	Plant(Position position, char symbol, int color);
	Plant(int strength, Position position, char symbol, int color);
	Plant(int strength, char symbol, int color);

	virtual void take_action();
	virtual void collide();
};
