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
) : world(world), position(position), symbol(symbol), color(color), strength(strength), initiative(initiative), age(age), is_alive(is_alive) {
}

Position Organism::get_random_offset(const Position *all_offsets, const int all_offsets_count) {
	Position offsets[all_offsets_count];
	int offsets_count = 0;

	for (int i = 0; i < all_offsets_count; i++) {
		if (this->get_position() + all_offsets[i] > Position{this->get_world()->get_width() - 1, this->get_world()->get_height() - 1}
			|| this->get_position() + all_offsets[i] < Position{0, 0}) {
			continue;
		}

		offsets[offsets_count] = all_offsets[i];
		offsets_count++;
	}

	if (offsets_count == 0) {
		return Position{0, 0};
	}

	std::uniform_int_distribution<int> offset_index(0, offsets_count-1);

	return offsets[offset_index(this->get_world()->get_rng())];
}

Position Organism::get_position() const {
	return this->position;
}

void Organism::move(Position new_position) {
	this->world->set_organism(this->position.x, this->position.y, nullptr);
	this->world->set_organism(new_position.x, new_position.y, this);
	this->position = new_position;
}

void Organism::die() {
	this->world->set_organism(this->position.x, this->position.y, nullptr);

	this->set_is_alive(false); // TODO: This is a memory leak, fix pls
}

int Organism::get_strength() const {
	return this->strength;
}

void Organism::set_strength(int strength) {
	this->strength = strength;
}

int Organism::get_initiative() const {
	return this->initiative;
}

int Organism::get_age() const {
	return this->age;
}

void Organism::set_age(int age) {
	this->age = age;
}

bool Organism::get_is_alive() const {
	return this->is_alive;
}

void Organism::set_is_alive(bool is_alive) {
	this->is_alive = is_alive;
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

bool Organism::is_animal() const {
	return this->get_type() == ANTELOPE || this->get_type() == CYBER_SHEEP || this->get_type() == FOX || this->get_type() == HUMAN || this->get_type() == SHEEP || this->get_type() == TURTLE || this->get_type() == WOLF;
}

Position Organism::get_random_free_offset(const Position *offsets, const int offsets_count, const bool strength_check) {
	bool *occupied = (bool *) malloc(offsets_count * sizeof(bool));

	for (int i = 0; i < offsets_count; i++) {
		if (this->get_position() + offsets[i] > Position{this->get_world()->get_width() - 1, this->get_world()->get_height() - 1}
			|| this->get_position() + offsets[i] < Position{0, 0}) {
			occupied[i] = true;
			continue;
		}

		if (this->get_world()->get_organism(this->get_position().x + offsets[i].x, this->get_position().y + offsets[i].y) != nullptr
			&& (!strength_check || this->get_world()->get_organism(this->get_position().x + offsets[i].x, this->get_position().y + offsets[i].y)->get_strength() > this->get_strength())) {
			occupied[i] = true;
		} else {
			occupied[i] = false;
		}
	}

	Position *available_offsets = (Position *) malloc(offsets_count * sizeof(Position));
	int available_offsets_count = 0;

	for (int i = 0; i < offsets_count; i++) {
		if (!occupied[i]) {
			available_offsets[available_offsets_count] = offsets[i];
			available_offsets_count++;
		}
	}

	if (available_offsets_count == 0) {
		return Position{0, 0};
	}

	std::uniform_int_distribution<int> offset_index(0, available_offsets_count-1);

	Position random_free_offset = available_offsets[offset_index(this->get_world()->get_rng())];

	free(occupied);
	free(available_offsets);

	return random_free_offset;
}

bool Organism::type_exists(enum OrganismType type) {
	for (int y = 0; y < this->get_world()->get_height(); y++) {
		for (int x = 0; x < this->get_world()->get_width(); x++) {
			if (this->get_world()->get_organism(x, y) != nullptr && this->get_world()->get_organism(x, y)->get_type() == type) {
				return true;
			}
		}
	}

	return false;
}

Organism *Organism::get_closest_of_type(enum OrganismType type) {
	Organism *closest_organism = nullptr;
	float closest_distance = std::numeric_limits<float>::max();

	for (int y = 0; y < this->get_world()->get_height(); y++) {
		for (int x = 0; x < this->get_world()->get_width(); x++) {
			if (this->get_world()->get_organism(x, y) != nullptr && this->get_world()->get_organism(x, y)->get_type() == type) {
				float distance = this->get_position().distance(this->get_world()->get_organism(x, y)->get_position());

				if (distance < closest_distance) {
					closest_distance = distance;
					closest_organism = this->get_world()->get_organism(x, y);
				}
			}
		}
	}

	return closest_organism;
}

void Organism::kill_adjacent_organisms(bool only_animals, bool cannot_be_cyber_sheep) {
	Organism *adjacent_organisms[OFFSET_COUNT];
	int adjacent_organisms_count = 0;

	for (int i = 0; i < OFFSET_COUNT; i++) {
		Position checked_position = this->get_position() + Organism::all_offsets[i];

		if (checked_position < Position{0, 0} || checked_position > Position{this->get_world()->get_width() - 1, this->get_world()->get_height() - 1}) {
			continue;
		}

		Organism *adjacent_organism = this->get_world()->get_organism(checked_position.x, checked_position.y);

		if (adjacent_organism != nullptr
			&& (!only_animals || adjacent_organism->is_animal())
			&& (!cannot_be_cyber_sheep || adjacent_organism->get_type() != CYBER_SHEEP)) {
			adjacent_organisms[adjacent_organisms_count] = adjacent_organism;
			adjacent_organisms_count++;
		}
	}

	for (int i = 0; i < adjacent_organisms_count; i++) {
		adjacent_organisms[i]->die();
	}
}

Organism::~Organism() {
}
