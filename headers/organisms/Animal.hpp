#pragma once
#include "../Organism.hpp"

class Animal : public Organism {
public:
	Animal();
	Animal(int strength, int initiative);
	Animal(int strength, int initiative, Position position);

	virtual void take_action();
	virtual void collide();
};
