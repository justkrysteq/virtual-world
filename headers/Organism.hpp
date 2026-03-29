#pragma once

#include <random>
#include "colors.hpp"

class World;

typedef struct Position {
	int x;
	int y;

	Position operator+(const Position& other) const {
		return {this->x + other.x, this->y + other.y};
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
	bool is_alive;
	char symbol;
	Position position;
	World *world;
	std::mt19937 rng{std::random_device{}()};
public:
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
	virtual void collide() = 0;

	Position* get_available_positions() const;
	Position choose_available_position() const;
	Position get_random_offset();
	Position get_position() const;
	void set_position(Position position);

	bool get_is_alive() const;
	int get_strength() const;
	int get_initiative() const;
	int get_age() const;
	char get_symbol() const;
	int get_color() const;
	const World *get_world() const;

	virtual ~Organism();
};
