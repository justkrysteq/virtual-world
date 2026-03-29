#pragma once
#include "../Organism.hpp"

class Animal : public Organism {
private:
	bool omit_action = false;
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

	bool get_omit_action() const;
	void set_omit_action(bool omit_action);
};
