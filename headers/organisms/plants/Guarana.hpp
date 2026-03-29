#include "../Plant.hpp"

#define GUARANA_SYMBOL 'g'

class Guarana : public Plant {
public:
	Guarana(World *world, Position position);

	void collide() override;
};
