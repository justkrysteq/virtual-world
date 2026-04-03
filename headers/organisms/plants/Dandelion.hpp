#include "../Plant.hpp"

#define DANDELION_SYMBOL 'd'
#define DANDELION_SPREAD_TRIES 3

class Dandelion : public Plant {
public:
	Dandelion(World *world, Position position);

	void take_action() override;
};
