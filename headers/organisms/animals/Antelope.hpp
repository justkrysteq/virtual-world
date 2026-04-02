#include "../Animal.hpp"

#define ANTELOPE_STRENGTH 4
#define ANTELOPE_INITIATIVE 4
#define ANTELOPE_SYMBOL 'A'

class Antelope : public Animal {
public:
	Antelope(World *world, Position position);

	void take_action() override;
	void collide(Organism *other) override;
};
