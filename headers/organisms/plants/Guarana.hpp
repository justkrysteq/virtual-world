#include "../Plant.hpp"

class Guarana : public Plant {
public:
	Guarana();
	Guarana(Position position);

	void collide() override;
};
