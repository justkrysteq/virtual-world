#include <cstdio>
#include <memory>
#include <ncurses.h>
#include "World.hpp"

#define BORDER_WIDTH 1
#define HEADER_HEIGHT 1

#define KEY_QUIT 'q'
#define KEY_NEXT_TURN 'n'
#define KEY_SPECIAL_ABILITY 'e'
#define KEY_SAVE_WORLD 's'
#define KEY_LOAD_WORLD 'l'

class Game {
private:
	int turn_count;
	bool is_running;
	WINDOW *screen;
	WINDOW *world_window;
	std::unique_ptr<World> world;
	void update();
	void init_screen();
	void init_colors();
	void save_state() const;
	void load_state();
	void handle_input();
	void next_turn();
	void draw_world();
	void draw_log();
	void draw_legend();
	// void next_organism();
public:
	Game();

	void run();

	// ~Game(); // Destructor - define if any additional resources need to be freed
};
