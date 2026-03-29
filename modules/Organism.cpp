#include "../headers/Organism.hpp"
#include "../headers/World.hpp"

Organism::Organism(
	World *world,
	Position position,
	char symbol,
	int color,
	int strength,
	int initiative,
	int age,
	bool is_alive
) : strength(strength), initiative(initiative), age(age), color(color), is_alive(is_alive), symbol(symbol), position(position), world(world) {
}

// Position* Organism::get_available_positions() const {
// }
//
// Position Organism::choose_available_position() const {
// }

Position Organism::get_random_offset() {
	std::uniform_int_distribution<int> offset(0, 7);

	switch (offset(this->rng)) {
		case 0:
			return {-1, 0};
		case 1:
			return {1, 0};
		case 2:
			return {0, -1};
		case 3:
			return {0, 1};
		case 4:
			return {-1, -1};
		case 5:
			return {1, -1};
		case 6:
			return {-1, 1};
		case 7:
			return {1, 1};
		default:
			return {0, 0};
	}
}

Position Organism::get_position() const {
	return this->position;
}

void Organism::set_position(Position position) {
	this->position = position;
	this->world->set_organism(this->position.x, this->position.y, this);
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

char Organism::get_symbol() const {
	return this->symbol;
}

int Organism::get_color() const {
	return this->color;
}

const World *Organism::get_world() const {
	return this->world;
}

Organism::~Organism() {
}
