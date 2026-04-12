#pragma once

#include <cstdlib>
#include <random>
#include <ncurses.h>
#include <vector>

#include "organisms/animals/Antelope.hpp"
#include "organisms/animals/CyberSheep.hpp"
#include "organisms/animals/Fox.hpp"
#include "organisms/animals/Human.hpp"
#include "organisms/animals/Sheep.hpp"
#include "organisms/animals/Turtle.hpp"
#include "organisms/animals/Wolf.hpp"
#include "organisms/plants/Dandelion.hpp"
#include "organisms/plants/Grass.hpp"
#include "organisms/plants/Guarana.hpp"
#include "organisms/plants/SosnowskisBorscht.hpp"
#include "organisms/plants/Wolfberries.hpp"

#define INITIAL_SPAWN_COUNT 2
#define ORGANISM_TYPE_COUNT WOLFBERRIES+1
#define DEFAULT_WORLD_WIDTH 20
#define DEFAULT_WORLD_HEIGHT 20

class World {
private:
	int world_width;
	int world_height;
	// int current_organism_index;
	std::vector<std::string> messages;
	Organism ***organisms;
	std::mt19937 rng{std::random_device{}()};
	static int compare_organisms(const void *a, const void *b);
	Human *human;

public:
	World();
	World(int world_width, int world_height);
	void initial_spawn_all();
	void next_turn();
	int get_width() const;
	int get_height() const;
	Organism *get_organism(int x, int y) const;
	void set_organism(int x, int y, Organism *organism);
	// void next_organism();
	std::mt19937 &get_rng();
	void spawn_organism(enum OrganismType type, Position position);
	Human *get_human() const;
	void add_message(std::string message);
	int get_message_count() const;
	std::string get_message(int index) const;
	void set_human(Human *human);

	~World();
};
