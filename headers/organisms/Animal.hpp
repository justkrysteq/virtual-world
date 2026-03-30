#pragma once

#include "../Organism.hpp"

class Animal : public Organism {
private:
	bool omit_action = false;

	void breed(Organism *other);
public:
	Position choose_offset_for_offspring(Organism *other);
	Animal(
		World *world,
		Position position,
		char symbol,
		int color,
		int strength = 0,
		int initiative = 0
	);

	virtual void take_action();
	virtual void collide(Organism *organism);

	bool get_omit_action() const;
	void set_omit_action(bool omit_action);
};
