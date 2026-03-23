#include "../headers/Game.hpp"

Game::Game() : turn_count(0) {
}

void Game::run() {
	printf("Welcome to the game!\n");
	printf("Input world size (default: 20 20): ");

	int world_width, world_height;
	if (scanf("%d %d", &world_width, &world_height) != 2) {
		printf("Invalid world size!\n");
		world_width = DEFAULT_WORLD_WIDTH;
		world_height = DEFAULT_WORLD_HEIGHT;
	}

	if (world_width == 0 || world_height == 0) {
		this->world = std::make_unique<World>(DEFAULT_WORLD_WIDTH, DEFAULT_WORLD_HEIGHT);
	} else {
		this->world = std::make_unique<World>(world_width, world_height);
	}

	printf("World size: %d %d\n", world_width, world_height);

	// initscr();
	// cbreak();
	// noecho();
	//
	// bool is_running = true;
	// while (is_running) {
	// 	this->handle_input(&is_running);
	// }
}

void Game::handle_input(bool *is_running) {
	char key = (char) wgetch(stdscr);
	switch (key) {
		case 'q':
			*is_running = false;
			break;
		case 'w':
			this->world->next_turn();
			break;
		default:
			break;
	}
}
