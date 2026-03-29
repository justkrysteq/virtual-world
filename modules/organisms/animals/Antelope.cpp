#include "../../../headers/organisms/animals/Antelope.hpp"

Antelope::Antelope(World *world, Position position) : Animal(world, position, ANTELOPE_SYMBOL, PAIR_ANTELOPE, ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE) {
}

void Antelope::take_action() {
}

void Antelope::collide(Organism *organism) {
}
