#include "../../../headers/organisms/plants/Guarana.hpp"
#include "../../../headers/World.hpp"

Guarana::Guarana(World *world, Position position) : Plant(world, position, GUARANA_SYMBOL, PAIR_GUARANA) {
}

void Guarana::collide(Organism *other) {
	other->set_strength(other->get_strength() + 3);

	Plant::collide(other);
	other->get_world()->add_message(other->get_name() + std::string(" gained 3 strength from eating ") + this->get_name());
}
