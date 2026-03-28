#pragma once
#include "../Organism.hpp"

class Animal : public Organism {
public:
	Animal();
	Animal(int strength, int initiative);
	Animal(int strength, int initiative, Position position);
	Animal(int strength, int initiative, char symbol, int color);
	Animal(int strength, int initiative, Position position, char symbol, int color);

	virtual void take_action();
	virtual void collide();
};
