#include "../headers/Organism.hpp"
#include "../headers/World.hpp"

Organism::Organism(
	World *world,
	Position position,
	char symbol,
	int color,
	int strength,
	int initiative,
	int age
) : world(world), position(position), symbol(symbol), color(color), strength(strength), initiative(initiative), age(age) {
}

Position Organism::get_random_offset() {
	std::uniform_int_distribution<int> offset(0, 7);

	return Organism::all_offsets[offset(this->world->get_rng())];
}

Position Organism::get_position() const {
	return this->position;
}

void Organism::set_position(Position position) {
	this->position = position;
	this->world->set_organism(this->position.x, this->position.y, this);
}

void Organism::die() {
	this->world->set_organism(this->position.x, this->position.y, nullptr);

	delete this;
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

World *Organism::get_world() {
	return this->world;
}

enum OrganismType Organism::get_type() const {
	switch (this->symbol) {
		case ANTELOPE_SYMBOL:
			return ANTELOPE;
		case CYBER_SHEEP_SYMBOL:
			return CYBER_SHEEP;
		case FOX_SYMBOL:
			return FOX;
		case HUMAN_SYMBOL:
			return HUMAN;
		case SHEEP_SYMBOL:
			return SHEEP;
		case TURTLE_SYMBOL:
			return TURTLE;
		case WOLF_SYMBOL:
			return WOLF;
		case DANDELION_SYMBOL:
			return DANDELION;
		case GRASS_SYMBOL:
			return GRASS;
		case GUARANA_SYMBOL:
			return GUARANA;
		case SOSNOWKIS_BORSCHT_SYMBOL:
			return SOSNOWKIS_BORSCHT;
		case WOLFBERRIES_SYMBOL:
			return WOLFBERRIES;
		default:
			return HUMAN;
	}
}

void Organism::collide(Organism *other) {
	if (this->get_strength() > other->get_strength()) {
		other->die();

		return;
	}

	this->die();
	other->set_position(this->get_position());
}

Position Organism::get_random_free_offset(const Position *offsets, const int offsets_count) {
	bool occupied[OFFSET_COUNT*2];

	for (int i = 0; i < offsets_count; i++) {
		if (this->get_world()->get_organism(this->get_position().x + offsets[i].x, this->get_position().y + offsets[i].y) != nullptr) {
			occupied[i] = true;
		}
	}

	Position available_offsets[OFFSET_COUNT*2];
	int available_offsets_count = 0;

	for (int i = 0; i < offsets_count; i++) {
		if (!occupied[i]) {
			available_offsets[available_offsets_count] = offsets[i];
			available_offsets_count++;
		}
	}

	std::uniform_int_distribution<int> offset_index(0, available_offsets_count);

	return available_offsets[offset_index(this->get_world()->get_rng())];
}

Organism::~Organism() {
}
