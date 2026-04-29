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
	} else if (this->is_special_ability_active()) {
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

void Human::activate_special_ability() { // TODO: Now the ability acts asynchronously, make it scheduled for the next turn (cuz print issues) also there is a bug where pressing enenenenen will stop counting down the cooldown
	if (this->special_ability_cooldown > 0) {
		this->get_world()->add_message(this->get_name() + std::string(" needs to wait for ") + std::to_string(SPECIAL_ABILITY_COOLDOWN - this->special_ability_cooldown) + std::string(" more turns before activating special ability"));
		return;
	}

	this->special_ability_active = true;
	this->special_ability_cooldown = SPECIAL_ABILITY_COOLDOWN;
	this->get_world()->add_message(this->get_name() + std::string(" activated special ability"));
}

void Human::deactivate_special_ability() {
	this->special_ability_active = false;
	this->get_world()->add_message(this->get_name() + std::string("'s special ability has been deactivated"));
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

bool Human::is_special_ability_active() const {
	return this->special_ability_active;
}

int Human::get_special_ability_cooldown() const {
	return this->special_ability_cooldown;
}

void Human::set_special_ability_cooldown(int special_ability_cooldown) {
	this->special_ability_cooldown = special_ability_cooldown;
}
