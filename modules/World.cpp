#include "../headers/World.hpp"

World::World() : World(DEFAULT_WORLD_WIDTH, DEFAULT_WORLD_HEIGHT) {
}

World::World(int world_width, int world_height) {
	this->world_width = world_width;
	this->world_height = world_height;
	this->organisms = (Organism ***) malloc(world_height * sizeof(Organism **));

	for (int y = 0; y < this->world_height; y++) {
		this->organisms[y] = (Organism **) malloc(world_width * sizeof(Organism *));
		for (int x = 0; x < this->world_width; x++) {
			this->organisms[y][x] = nullptr;
		}
	}
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

	this->human = new Human(this, Position{this->world_width/2 - 1, this->world_height/2 - 1});
	this->set_organism(this->world_width/2 - 1, this->world_height/2 - 1, this->human);

	used_positions[used_positions_count++] = this->human->get_position();

	std::uniform_int_distribution<int> width_dist(0, this->world_width-1);
	std::uniform_int_distribution<int> height_dist(0, this->world_height-1);

	for (int i = 0; i < INITIAL_SPAWN_COUNT; i++) {
		for (int type = 0; type < ORGANISM_TYPE_COUNT; type++) {
			Position position = {width_dist(this->rng), height_dist(this->rng)};
			bool is_position_used = false;

			if ((OrganismType) type == HUMAN) {
				continue;
			}

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

			// spawn_organism((OrganismType) type, position);
		}
	}

	// spawn_organism(WOLF, Position{10, 14});
	// spawn_organism(WOLF, Position{10, 16});
	// spawn_organism(FOX, Position{10, 11});
	// spawn_organism(SOSNOWKIS_BORSCHT, Position{0, 11});
	// spawn_organism(SOSNOWKIS_BORSCHT, Position{20, 11});
	spawn_organism(CYBER_SHEEP, Position{8, 5});
	spawn_organism(GRASS, Position{0, 0});
	spawn_organism(DANDELION, Position{13, 0});

	spawn_organism(ANTELOPE, Position{16, 10});
	spawn_organism(WOLF, Position{8, 13});
	spawn_organism(GUARANA, Position{12, 1});
	spawn_organism(ANTELOPE, Position{12, 11});
	spawn_organism(ANTELOPE, Position{9, 10});
}

void World::next_turn() {
	this->messages.clear();

	Organism **organisms_to_take_action = (Organism **) malloc(this->world_height*this->world_width * sizeof(Organism *));
	int organisms_count = 0;

	for (int y = 0; y < this->world_height; y++) {
		for (int x = 0; x < this->world_width; x++) {
			Organism *organism = this->get_organism(x, y);

			if (organism != nullptr) {
				organisms_to_take_action[organisms_count] = organism;
				organisms_count++;
			}
		}
	}

	if (organisms_count > 1) {
		qsort(organisms_to_take_action, organisms_count, sizeof(Organism **), this->compare_organisms);
	}

	for (int i = 0; i < organisms_count; i++) {
		organisms_to_take_action[i]->take_action();
		organisms_to_take_action[i]->set_age(organisms_to_take_action[i]->get_age() + 1);
	}

	free(organisms_to_take_action);
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

Human *World::get_human() const {
	return this->human;
}

void World::set_organism(int x, int y, Organism *organism) {
	this->organisms[y][x] = organism;
}

std::mt19937 &World::get_rng() {
	return this->rng;
}

int World::compare_organisms(const void *a, const void *b) {
	Organism * const *oa = (Organism * const *)a;
	Organism * const *ob = (Organism * const *)b;
	Organism *organism_a = *oa;
	Organism *organism_b = *ob;

	if (organism_a->get_initiative() > organism_b->get_initiative()) {
		return -1;
	}

	if (organism_a->get_initiative() < organism_b->get_initiative()) {
		return 1;
	}

	if (organism_a->get_age() > organism_b->get_age()) {
		return -1;
	}

	if (organism_a->get_age() < organism_b->get_age()) {
		return 1;
	}

	return 0;
}

void World::add_message(std::string message) {
	this->messages.push_back(message);
}

int World::get_message_count() const {
	return this->messages.size();
}

std::string World::get_message(int index) const {
	return this->messages[index];
}

void World::set_human(Human *human) {
	this->human = human;
}

World::~World() {
	if (this->organisms == nullptr) {
		return;
	}

	for (int y = 0; y < this->world_height; y++) {
		if (this->organisms[y] != nullptr) {
			// for (int x = 0; x < this->world_width; x++) {
			// 	if (this->organisms[y][x] != nullptr) {
			// 		printf("Deleting organism at %d %d\n", x, y);
			// 		printf("Organism: %c\n", this->organisms[y][x]->get_symbol());
			// 		delete this->organisms[y][x];
			// 	}
			// }

			free(this->organisms[y]);
		}
	}

	free(this->organisms);
}
