#pragma once

#include "colors.hpp"

typedef struct {
	int x;
	int y;
} Position;

class Organism {
private:
	int strength, initiative, age, color;
	bool is_alive;
	char symbol;
	Position position;
public:
	Organism();
	Organism(int strength);
	Organism(int strength, int initiative);
	Organism(int strength, Position position);
	Organism(Position position);
	Organism(int strength, int initiative, Position position);
	Organism(int strength, char symbol, int color);
	Organism(int strength, int initiative, char symbol, int color);
	Organism(int strength, Position position, char symbol, int color);
	Organism(Position position, char symbol, int color);
	Organism(int strength, int initiative, Position position, char symbol, int color);
	virtual void take_action() = 0;
	virtual void collide() = 0;

	Position* get_available_positions() const;
	Position choose_available_position() const;
	Position get_position() const;
	void set_position(Position position);

	bool get_is_alive() const;
	int get_strength() const;
	int get_initiative() const;
	int get_age() const;
	char get_symbol() const;
	int get_color() const;

	virtual ~Organism();
};
