#include "../headers/Game.hpp"

Game::Game() : turn_count(0), is_running(true) {
}

void Game::run() {
	printf("Welcome to the game!\n"); // TODO: Implement that in ncurses too
	printf("Input world size (default: 20 20): ");

	int world_width, world_height;
	// if (scanf("%d %d", &world_width, &world_height) != 2) {
	// 	printf("Invalid world size!\n");
	// 	world_width = DEFAULT_WORLD_WIDTH;
	// 	world_height = DEFAULT_WORLD_HEIGHT;
	// }
	world_width = DEFAULT_WORLD_WIDTH*2;
	world_height = DEFAULT_WORLD_HEIGHT;

	if (world_width == 0 || world_height == 0) {
		this->world = std::make_unique<World>(DEFAULT_WORLD_WIDTH, DEFAULT_WORLD_HEIGHT);
	} else {
		this->world = std::make_unique<World>(world_width, world_height);
	}

	printf("World size: %d %d\n", world_width, world_height);

	this->init_screen();
	mvwprintw(this->screen, 0, 0, "Virtual World");
	this->world_window = subwin(this->screen, world_height+BORDER_WIDTH*2, world_width+BORDER_WIDTH*2, HEADER_HEIGHT, 0);

	this->draw_world();

	while (this->is_running) {
		this->handle_input();
	}

	delwin(this->world_window);
	delwin(this->screen);
	endwin();
}

void Game::init_screen() {
	this->screen = initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(this->screen, TRUE);
	this->init_colors();
}

void Game::handle_input() {
	int key = wgetch(stdscr);
	switch (key) {
		case KEY_QUIT:
			this->is_running = false;
			break;
		case KEY_NEXT_TURN:
			this->world->next_turn();
			this->draw_world();
			break;
		case KEY_SPECIAL_ABILITY:
			this->world->get_human()->activate_special_ability();
			break;
		case KEY_UP:
		case KEY_LEFT:
		case KEY_RIGHT:
		case KEY_DOWN: {
			if (this->world->get_human() == nullptr) {
				break;
			}

			if (!this->world->get_human()->get_is_alive()) {
				break;
			}

			int next_key;
			do {
				next_key = wgetch(stdscr);
			} while (next_key != KEY_UP && next_key != KEY_LEFT && next_key != KEY_RIGHT && next_key != KEY_DOWN);

			this->world->get_human()->translate_input_to_action(key, next_key);
			break;
		}
		default:
			break;
	}
}

void Game::draw_world() {
	werase(this->world_window);
	box(this->world_window, 0, 0);

	for (int y = 0; y < this->world->get_height(); y++) {
		for (int x = 0; x < this->world->get_width(); x++) {
			if (this->world->get_organism(x, y) != nullptr) {
				wattron(this->world_window, COLOR_PAIR(this->world->get_organism(x, y)->get_color()));
				mvwprintw(this->world_window, y+BORDER_WIDTH, x+BORDER_WIDTH, "%c", this->world->get_organism(x, y)->get_symbol());
				wattroff(this->world_window, COLOR_PAIR(this->world->get_organism(x, y)->get_color()));
			}
		}
	}

	wrefresh(this->world_window);
}

void Game::init_colors() {
	start_color();

	init_color(COLOR_ANTELOPE, 844, 712, 412);
	init_color(COLOR_CYBER_SHEEP, 456, 692, 999);
	init_color(COLOR_FOX, 999, 528, 0);
	init_color(COLOR_HUMAN, 999, 784, 999);
	init_color(COLOR_SHEEP, 999, 999, 999);
	init_color(COLOR_TURTLE, 0, 440, 0);
	init_color(COLOR_WOLF, 692, 692, 692);
	init_color(COLOR_DANDELION, 999, 999, 236);
	init_color(COLOR_GRASS, 552, 999, 308);
	init_color(COLOR_GUARANA, 200, 999, 708);
	init_color(COLOR_SOSNOWKIS_BORSCHT, 772, 180, 0);
	init_color(COLOR_WOLFBERRIES, 544, 0, 999);

	init_pair(PAIR_ANTELOPE, COLOR_BLACK, COLOR_ANTELOPE);
	init_pair(PAIR_CYBER_SHEEP, COLOR_BLACK, COLOR_CYBER_SHEEP);
	init_pair(PAIR_FOX, COLOR_BLACK, COLOR_FOX);
	init_pair(PAIR_HUMAN, COLOR_BLACK, COLOR_HUMAN);
	init_pair(PAIR_SHEEP, COLOR_BLACK, COLOR_SHEEP);
	init_pair(PAIR_TURTLE, COLOR_BLACK, COLOR_TURTLE);
	init_pair(PAIR_WOLF, COLOR_BLACK, COLOR_WOLF);
	init_pair(PAIR_DANDELION, COLOR_BLACK, COLOR_DANDELION);
	init_pair(PAIR_GRASS, COLOR_BLACK, COLOR_GRASS);
	init_pair(PAIR_GUARANA, COLOR_BLACK, COLOR_GUARANA);
	init_pair(PAIR_SOSNOWKIS_BORSCHT, COLOR_BLACK, COLOR_SOSNOWKIS_BORSCHT);
	init_pair(PAIR_WOLFBERRIES, COLOR_BLACK, COLOR_WOLFBERRIES);
}
