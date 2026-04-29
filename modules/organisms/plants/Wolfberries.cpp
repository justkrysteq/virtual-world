#include "../../../headers/World.hpp"

Wolfberries::Wolfberries(World *world, Position position) : Plant(world, position, WOLFBERRIES_SYMBOL, PAIR_WOLFBERRIES, WOLFBERRIES_STRENGTH) {
}

void Wolfberries::collide(Organism *other) {
	this->die();
	other->die();
	this->get_world()->add_message(this->get_name() + std::string(" was eaten by ") + other->get_name());
	other->get_world()->add_message(other->get_name() + std::string(" dies from eating ") + this->get_name());
}
