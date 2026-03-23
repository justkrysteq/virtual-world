#include "../headers/World.hpp"

World::World() {
	this->world_width = 20;
	this->world_height = 20;

	initial_spawn_all();
}

World::World(int world_width, int world_height) {
	this->world_width = world_width;
	this->world_height = world_height;

	initial_spawn_all();
}

void World::initial_spawn_all() {
}

void World::next_turn() {
}
