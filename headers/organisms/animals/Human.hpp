#pragma once

#include <ncurses.h>
#include <algorithm>
#include "../Animal.hpp"

#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4
#define HUMAN_SYMBOL 'H'
#define SPECIAL_ABILITY_COOLDOWN 5

enum HumanAction {
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP_LEFT,
	MOVE_UP_RIGHT,
	MOVE_DOWN_LEFT,
	MOVE_DOWN_RIGHT,
	HUMAN_ACTION_UNSET
};

class Human : public Animal {
private:
	HumanAction next_action = HUMAN_ACTION_UNSET;
	int special_ability_cooldown = 0;
	bool special_ability_active = false;

public:
	Human(World *world, Position position);

	void take_action() override;
	void collide(Organism *other) override;

	void set_next_action(HumanAction next_action);
	HumanAction get_next_action() const;
	Position get_offset_for_action(HumanAction action);
	void translate_input_to_action(int key, int next_key);
	void activate_special_ability();
	void deactivate_special_ability();
	bool is_special_ability_active() const;
	int get_special_ability_cooldown() const;
	void set_special_ability_cooldown(int special_ability_cooldown);
};
