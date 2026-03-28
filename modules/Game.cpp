#include "../headers/Game.hpp"

Game::Game() : turn_count(0), is_running(true) {
}

void Game::run() {
	printf("Welcome to the game!\n"); // TODO: Implement that in ncurses too
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

	this->init_screen();
	this->world_window = subwin(this->screen, world_height+1, world_width+1, 0, 0);
	box(this->world_window, 0, 0);
	wrefresh(this->world_window);

	while (this->is_running) {
		this->handle_input();
	}

	delwin(this->screen);
	endwin();
}

void Game::init_screen() {
	this->screen = initscr();
	cbreak();
	noecho();
}

void Game::handle_input() {
	char key = (char) wgetch(stdscr);
	switch (key) {
		case 'q':
			this->is_running = false;
			break;
		case 'w':
			this->world->next_turn();
			break;
		default:
			break;
	}
}
