#include "../Plant.hpp"

#define DANDELION_SYMBOL 'd'

class Dandelion : public Plant {
public:
	Dandelion(World *world, Position position);

	void take_action() override;
};
