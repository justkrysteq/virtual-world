#include "../Plant.hpp"

#define DANDELION_SYMBOL 'd'

class Dandelion : public Plant {
public:
	Dandelion();
	Dandelion(Position position);

	void take_action() override;
};
