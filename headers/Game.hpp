#include <cstdio>
#include <memory>
#include <ncurses.h>
#include "World.hpp"

class Game {
private:
	int turn_count;
	std::unique_ptr<World> world;
	void update();
	void save_state() const;
	void load_state();
	void handle_input(bool *is_running);
	void next_turn();
	// void next_organism();
public:
	Game();

	void run();

	// ~Game(); // Destructor - define if any additional resources need to be freed
};
