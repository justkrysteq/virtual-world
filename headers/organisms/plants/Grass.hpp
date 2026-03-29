#include "../Plant.hpp"

#define GRASS_SYMBOL '_'

class Grass : public Plant {
public:
	Grass(World *world, Position position);
};
