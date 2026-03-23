#include "../headers/Organism.hpp"

Organism::Organism() : strength(0), initiative(0), age(0), is_alive(true), position({0, 0}) {
}

Organism::Organism(int strength, int initiative) : strength(strength), initiative(initiative), age(0), is_alive(true), position({0, 0}) {
}

Organism::Organism(int strength, int initiative, Position position) : strength(strength), initiative(initiative), age(0), is_alive(true), position(position) {
}

Organism::Organism(int strength) : strength(strength), initiative(0), age(0), is_alive(true), position({0, 0}) {
}

Organism::Organism(int strength, Position position) : strength(strength), initiative(0), age(0), is_alive(true), position(position) {
}

Organism::Organism(Position position) : strength(0), initiative(0), age(0), is_alive(true), position(position) {
}

// Position* Organism::get_available_positions() const {
// }
//
// Position Organism::choose_available_position() const {
// }

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

Organism::~Organism() {
}
