#include "../headers/Organism.hpp"

Organism::Organism() {
	this->strength = 0;
	this->initiative = 0;
	this->age = 0;
	this->is_alive = true;
	this->position.x = 0;
	this->position.y = 0;
}

Organism::Organism(int strength, int initiative) {
	this->strength = strength;
	this->initiative = initiative;
	this->age = 0;
	this->is_alive = true;
	this->position.x = 0;
	this->position.y = 0;
}

Organism::Organism(int strength, int initiative, Position position) {
	this->strength = strength;
	this->initiative = initiative;
	this->age = 0;
	this->is_alive = true;
	this->position = position;
}

Organism::Organism(int strength) {
	this->strength = strength;
	this->initiative = 0;
	this->age = 0;
	this->is_alive = true;
	this->position.x = 0;
	this->position.y = 0;
}

Organism::Organism(int strength, Position position) {
	this->strength = strength;
	this->initiative = 0;
	this->age = 0;
	this->is_alive = true;
	this->position = position;
}

Organism::Organism(Position position) {
	this->strength = 0;
	this->initiative = 0;
	this->age = 0;
	this->is_alive = true;
	this->position = position;
}

Position* Organism::get_available_positions() const {
}

Position Organism::choose_available_position() const {
}

Position Organism::get_position() const {
	return this->position;
}

void Organism::set_position(Position position) {
	this->position = position;
}

bool Organism::get_is_alive() const {
	return this->is_alive;
}

int Organism::get_strength() const {
	return this->strength;
}

int Organism::get_initiative() const {
	return this->initiative;
}

int Organism::get_age() const {
	return this->age;
}
