#include <stdlib.h>
#include <random>

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

class World {
private:
	int world_width;
	int world_height;
	// int current_organism_index;
	Organism ***organisms;
	void spawn_organism(enum OrganismType type, Position position);
	void initial_spawn_all();
	std::mt19937 rng{std::random_device{}()};

public:
	World();
	World(int world_width, int world_height);
	void next_turn();
	int get_width() const;
	int get_height() const;
	Organism *get_organism(int x, int y) const;
	// void next_organism();
	~World();
};
