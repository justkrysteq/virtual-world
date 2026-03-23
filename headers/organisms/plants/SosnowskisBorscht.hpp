#include "../Plant.hpp"

#define SOSNOWKIS_BORSCHT_STRENGTH 10

class SosnowskisBorscht : public Plant {
public:
	SosnowskisBorscht();
	SosnowskisBorscht(Position position);

	void take_action() override;
	void collide() override;
};
