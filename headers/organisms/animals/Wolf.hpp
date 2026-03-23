#include "../Animal.hpp"

#define WOLF_STRENGTH 9
#define WOLF_INITIATIVE 5

class Wolf : public Animal {
public:
	Wolf();
	Wolf(Position position);
};
