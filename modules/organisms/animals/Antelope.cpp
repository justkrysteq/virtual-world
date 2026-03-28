#include "../../../headers/organisms/animals/Antelope.hpp"

Antelope::Antelope() : Animal(ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE, ANTELOPE_SYMBOL, PAIR_ANTELOPE) {
}

Antelope::Antelope(Position position) : Animal(ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE, position, ANTELOPE_SYMBOL, PAIR_ANTELOPE) {
}

void Antelope::take_action() {
}

void Antelope::collide() {
}
