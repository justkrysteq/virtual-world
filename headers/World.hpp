#include "Organism.hpp"

class World {
private:
	int world_width;
	int world_height;
	// int current_organism_index;
	Organism* organisms[200]; // TODO: Make this dynamic
	void spawn_organism();
	void initial_spawn_all();

public:
	World();
	World(int world_width, int world_height);
	void next_turn();
	// void next_organism();
	// ~World();
};
