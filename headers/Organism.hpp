#pragma once

typedef struct {
	int x;
	int y;
} Position;

class Organism {
private:
	int strength, initiative, age;
	bool is_alive;
	Position position;
public:
	Organism();
	Organism(int strength);
	Organism(int strength, int initiative);
	Organism(int strength, Position position);
	Organism(Position position);
	Organism(int strength, int initiative, Position position);
	virtual void take_action() const = 0;
	virtual void collide() const = 0;

	Position* get_available_positions() const;
	Position choose_available_position() const;
	Position get_position() const;
	void set_position(Position position);

	bool get_is_alive() const;
	int get_strength() const;
	int get_initiative() const;
	int get_age() const;
};
