#include "../Plant.hpp"

class Dandelion : public Plant {
public:
	Dandelion();
	Dandelion(Position position);

	void take_action() override;
};
