#include <cstdio>
#include <memory>
#include <ncurses.h>
#include "World.hpp"

class Game {
private:
	int turn_count;
	bool is_running;
	WINDOW *screen;
	WINDOW *world_window;
	std::unique_ptr<World> world;
	void update();
	void init_screen();
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
