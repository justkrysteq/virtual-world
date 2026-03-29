#include "../headers/World.hpp"

World::World() : World(DEFAULT_WORLD_WIDTH, DEFAULT_WORLD_HEIGHT) {
}

World::World(int world_width, int world_height) {
	this->world_width = world_width;
	this->world_height = world_height;
	this->organisms = (Organism ***) malloc(world_height * sizeof(Organism**));

	for (int y = 0; y < this->world_height; y++) {
		this->organisms[y] = (Organism **) malloc(world_width * sizeof(Organism*));
		for (int x = 0; x < this->world_width; x++) {
			this->organisms[y][x] = nullptr;
		}
	}

	initial_spawn_all();
}

void World::spawn_organism(enum OrganismType type, Position position) {
	switch (type) {
		case ANTELOPE:
			this->organisms[position.y][position.x] = new Antelope(this, position);
			break;
		case CYBER_SHEEP:
			this->organisms[position.y][position.x] = new CyberSheep(this, position);
			break;
		case FOX:
			this->organisms[position.y][position.x] = new Fox(this, position);
			break;
		case HUMAN:
			this->organisms[position.y][position.x] = new Human(this, position);
			break;
		case SHEEP:
			this->organisms[position.y][position.x] = new Sheep(this, position);
			break;
		case TURTLE:
			this->organisms[position.y][position.x] = new Turtle(this, position);
			break;
		case WOLF:
			this->organisms[position.y][position.x] = new Wolf(this, position);
			break;
		case DANDELION:
			this->organisms[position.y][position.x] = new Dandelion(this, position);
			break;
		case GRASS:
			this->organisms[position.y][position.x] = new Grass(this, position);
			break;
		case GUARANA:
			this->organisms[position.y][position.x] = new Guarana(this, position);
			break;
		case SOSNOWKIS_BORSCHT:
			this->organisms[position.y][position.x] = new SosnowskisBorscht(this, position);
			break;
		case WOLFBERRIES:
			this->organisms[position.y][position.x] = new Wolfberries(this, position);
			break;
	}
}

void World::initial_spawn_all() {
	Position used_positions[INITIAL_SPAWN_COUNT*ORGANISM_TYPE_COUNT];
	int used_positions_count = 0;

	std::uniform_int_distribution<int> width_dist(0, this->world_width-1);
	std::uniform_int_distribution<int> height_dist(0, this->world_height-1);

	for (int i = 0; i < INITIAL_SPAWN_COUNT; i++) {
		for (int type = 0; type < ORGANISM_TYPE_COUNT; type++) {
			Position position = {width_dist(this->rng), height_dist(this->rng)};
			bool is_position_used = false;

			// TODO: Implement: do not allow spawning on the same position twice (causes memory leaks)

			// while (!is_position_used) {
			// 	for (int j = 0; j < used_positions_count; j++) {
			// 		if (j == 0) {
			// 			is_position_used = false;
			// 		}
			//
			// 		if (used_positions[j].x == position.x && used_positions[j].y == position.y) {
			// 			position = {width_dist(this->rng), height_dist(this->rng)};
			// 			is_position_used = true;
			// 		}
			//
			// 		if (j == used_positions_count-1 && !is_position_used) {
			// 			is_position_used = false;
			// 		}
			// 	}
			// }

			used_positions[used_positions_count] = position;
			used_positions_count++;

			spawn_organism((OrganismType) type, position);
		}
	}
}

void World::next_turn() {
}

int World::get_width() const {
	return this->world_width;
}

int World::get_height() const {
	return this->world_height;
}

Organism *World::get_organism(int x, int y) const {
	return this->organisms[y][x];
}

void World::set_organism(int x, int y, Organism *organism) {
	if (this->organisms[y][x] != nullptr) {
		delete this->organisms[y][x];
	}

	this->organisms[y][x] = organism;
}

std::mt19937 &World::get_rng() {
	return this->rng;
}

World::~World() {
	if (this->organisms == nullptr) return;
	for (int y = 0; y < this->world_height; y++) {
		if (this->organisms[y] != nullptr) {
			for (int x = 0; x < this->world_width; x++) {
				delete this->organisms[y][x];
			}

			free(this->organisms[y]);
		}
	}
	free(this->organisms);
}
