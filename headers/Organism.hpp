#pragma once

#include <random>
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

class World;

typedef struct Position {
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

	bool operator!=(const Position& other) const {
		return !(*this == other);
	}
} Position;

class Organism {
private:
	int strength, initiative, age, color;
	char symbol;
	Position position;
	World *world;
public:
	inline static constexpr Position all_offsets[OFFSET_COUNT] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

	Organism(
		World *world = nullptr,
		Position position = {0, 0},
		char symbol = '?',
		int color = 0,
		int strength = 0,
		int initiative = 0,
		int age = 0
	);

	virtual void take_action() = 0;
	virtual void collide(Organism *organism) = 0;

	Position get_random_offset();
	Position get_position() const;
	void set_position(Position position);

	int get_strength() const;
	int get_initiative() const;
	int get_age() const;
	char get_symbol() const;
	int get_color() const;
	World *get_world();
	enum OrganismType get_type() const;

	void die();

	virtual ~Organism();
};
