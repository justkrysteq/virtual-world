#include "../../../headers/organisms/plants/Wolfberries.hpp"

Wolfberries::Wolfberries(World *world, Position position) : Plant(world, position, WOLFBERRIES_SYMBOL, PAIR_WOLFBERRIES, WOLFBERRIES_STRENGTH) {
}

void Wolfberries::collide(Organism *organism) {
}
