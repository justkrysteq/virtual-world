#include "../Plant.hpp"

#define GUARANA_SYMBOL 'g'

class Guarana : public Plant {
public:
	Guarana();
	Guarana(Position position);

	void collide() override;
};
