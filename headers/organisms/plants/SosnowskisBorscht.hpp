#include "../Plant.hpp"

#define SOSNOWKIS_BORSCHT_STRENGTH 10
#define SOSNOWKIS_BORSCHT_SYMBOL 's'

class SosnowskisBorscht : public Plant {
public:
	SosnowskisBorscht(World *world, Position position);

	void take_action() override;
	void collide(Organism *organism) override;
};
