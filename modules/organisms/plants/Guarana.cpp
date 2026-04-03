#include "../../../headers/organisms/plants/Guarana.hpp"

Guarana::Guarana(World *world, Position position) : Plant(world, position, GUARANA_SYMBOL, PAIR_GUARANA) {
}

void Guarana::collide(Organism *other) {
	other->set_strength(other->get_strength() + 3);

	Plant::collide(other);
}
