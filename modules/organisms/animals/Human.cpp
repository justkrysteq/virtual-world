#include "../../../headers/organisms/animals/Human.hpp"
#include "../../../headers/World.hpp"

Human::Human(World *world, Position position) : Animal(world, position, HUMAN_SYMBOL, PAIR_HUMAN, HUMAN_STRENGTH, HUMAN_INITIATIVE) {
}

void Human::take_action() {
	Position new_position = this->get_position() + this->get_offset_for_action(this->get_next_action());

	if (!(new_position < Position{0, 0} || new_position > Position{this->get_world()->get_width() - 1, this->get_world()->get_height() - 1})) {
		Animal::take_action(this->get_offset_for_action(this->get_next_action()));
	}

	this->set_next_action(HUMAN_ACTION_UNSET);

	if (this->special_ability_cooldown > 0) {
		this->special_ability_cooldown--;
	} else {
		this->deactivate_special_ability();
	}
}

void Human::collide(Organism *other) {
	if (this->special_ability_active) {
		this->kill_adjacent_organisms();
	}

	Animal::collide(other);
}

void Human::set_next_action(HumanAction next_action) {
	this->next_action = next_action;
}

HumanAction Human::get_next_action() const {
	return this->next_action;
}

void Human::activate_special_ability() {
	if (this->special_ability_cooldown > 0) {
		return;
	}

	this->special_ability_active = true;
	this->special_ability_cooldown = SPECIAL_ABILITY_COOLDOWN;
}

void Human::deactivate_special_ability() {
	this->special_ability_active = false;
	this->special_ability_cooldown = SPECIAL_ABILITY_COOLDOWN;
}

Position Human::get_offset_for_action(HumanAction action) {
	switch (action) {
		case MOVE_UP:
			return Position{0, -1};
		case MOVE_DOWN:
			return Position{0, 1};
		case MOVE_LEFT:
			return Position{-1, 0};
		case MOVE_RIGHT:
			return Position{1, 0};
		case MOVE_UP_LEFT:
			return Position{-1, -1};
		case MOVE_UP_RIGHT:
			return Position{1, -1};
		case MOVE_DOWN_LEFT:
			return Position{-1, 1};
		case MOVE_DOWN_RIGHT:
			return Position{1, 1};
		default:
			return Position{0, 0};
	}
}

void Human::translate_input_to_action(int key, int next_key) {
	if (key == next_key) {
		switch (key) {
			case KEY_UP:
				this->set_next_action(MOVE_UP);
				break;
			case KEY_DOWN:
				this->set_next_action(MOVE_DOWN);
				break;
			case KEY_LEFT:
				this->set_next_action(MOVE_LEFT);
				break;
			case KEY_RIGHT:
				this->set_next_action(MOVE_RIGHT);
				break;
		}

		return;
	}

	int keys[] = {key, next_key};

	std::sort(keys, keys + 2);

	switch (keys[0]) {
		case KEY_UP:
			switch (keys[1]) {
				case KEY_LEFT:
					this->set_next_action(MOVE_UP_LEFT);
					break;
				case KEY_RIGHT:
					this->set_next_action(MOVE_UP_RIGHT);
					break;
			}
			break;
		case KEY_DOWN:
			switch (keys[1]) {
				case KEY_LEFT:
					this->set_next_action(MOVE_DOWN_LEFT);
					break;
				case KEY_RIGHT:
					this->set_next_action(MOVE_DOWN_RIGHT);
					break;
			}
			break;
	}
}
