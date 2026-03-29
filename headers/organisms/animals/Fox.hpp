#include "../Animal.hpp"

#define FOX_STRENGTH 3
#define FOX_INITIATIVE 7
#define FOX_SYMBOL 'F'

class Fox : public Animal {
public:
	Fox(World *world, Position position);

	void take_action() override;
};
