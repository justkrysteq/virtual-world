#include "../Animal.hpp"

#define SHEEP_STRENGTH 4
#define SHEEP_INITIATIVE 4
#define SHEEP_SYMBOL 'S'

class Sheep : public Animal {
public:
	Sheep();
	Sheep(Position position);
};
