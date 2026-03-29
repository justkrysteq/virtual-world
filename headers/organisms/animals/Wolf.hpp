#include "../Animal.hpp"

#define WOLF_STRENGTH 9
#define WOLF_INITIATIVE 5
#define WOLF_SYMBOL 'W'

class Wolf : public Animal {
public:
	Wolf(World *world, Position position);
};
