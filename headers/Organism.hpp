#pragma once

#include <random>
#include <cmath>
#include <iostream>
#include <limits>
#include "colors.hpp"

#define OFFSET_COUNT 8

enum OrganismType {
	ANTELOPE,
	CYBER_SHEEP,
	FOX,
	HUMAN,
	SHEEP,
	TURTLE,
	WOLF,
	DANDELION,
	GRASS,
	GUARANA,
	SOSNOWKIS_BORSCHT,
	WOLFBERRIES
};

#define ANTELOPE_NAME "Antelope"
#define CYBER_SHEEP_NAME "Cyber Sheep"
#define FOX_NAME "Fox"
#define HUMAN_NAME "Human"
#define SHEEP_NAME "Sheep"
#define TURTLE_NAME "Turtle"
#define WOLF_NAME "Wolf"
#define DANDELION_NAME "Dandelion"
#define GRASS_NAME "Grass"
#define GUARANA_NAME "Guarana"
#define SOSNOWKIS_BORSCHT_NAME "Sosnowskis Borscht"
#define WOLFBERRIES_NAME "Wolfberries"

class World;

typedef struct Position { // TODO: move to a different file and move the definitions to cpp file
	int x;
	int y;

	Position operator+(const Position& other) const {
		return {this->x + other.x, this->y + other.y};
	}

	Position operator-(const Position& other) const {
		return {this->x - other.x, this->y - other.y};
	}

	Position operator+=(const Position& other) {
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	bool operator==(const Position& other) const {
		return this->x == other.x && this->y == other.y;
	}

	bool operator>(const Position& other) const {
		return this->x > other.x || this->y > other.y;
	}

	bool operator<(const Position& other) const {
		return this->x < other.x || this->y < other.y;
	}

	bool operator!=(const Position& other) const {
		return !(*this == other);
	}

	Position operator/(const float &other) const {
		int new_x, new_y = 0;

		if (this->x > 0) {
			new_x = (this->x / other) > 0.5 ? 1 : 0;
		}

		if (this->x < 0) {
			new_x = (this->x / other) < -0.5 ? -1 : 0;
		}

		if (this->y > 0) {
			new_y = (this->y / other) > 0.5 ? 1 : 0;
		}

		if (this->y < 0) {
			new_y = (this->y / other) < -0.5 ? -1 : 0;
		}

		return {new_x, new_y};
	}

	friend std::ostream& operator<<(std::ostream& os, const Position& p) {
		return os << p.x << ' ' << p.y;
	}

	float distance(const Position &other) const {
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
} Position;

class Organism {
private:
	int strength, initiative, age, color;
	char symbol;
	Position position;
	World *world;
	bool is_alive;
protected:
	void kill_adjacent_organisms(bool only_animals = false, bool cannot_be_cyber_sheep = false);

public:
	inline static constexpr Position all_offsets[OFFSET_COUNT] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

	Organism(
		World *world = nullptr,
		Position position = {0, 0},
		char symbol = '?',
		int color = 0,
		int strength = 0,
		int initiative = 0,
		int age = 0,
		bool is_alive = true
	);

	virtual void take_action() = 0;
	virtual void collide(Organism *other) = 0;

	Position get_random_offset(const Position *all_offsets = Organism::all_offsets, const int all_offsets_count = OFFSET_COUNT);
	Position get_random_free_offset(const Position *offsets = Organism::all_offsets, const int offsets_count = OFFSET_COUNT, const bool strength_check = false);
	Position get_position() const;
	void move(Position new_position);

	int get_strength() const;
	void set_strength(int strength);
	int get_initiative() const;
	bool is_animal() const;
	int get_age() const;
	void set_age(int age);
	char get_symbol() const;
	int get_color() const;
	bool get_is_alive() const;
	void set_is_alive(bool is_alive);
	World *get_world();
	enum OrganismType get_type() const;
	bool type_exists(enum OrganismType type);
	Organism *get_closest_of_type(enum OrganismType type);
	std::string get_name() const;

	void die();

	virtual ~Organism();
};
