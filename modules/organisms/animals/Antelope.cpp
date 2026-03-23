#include "../../../headers/organisms/animals/Antelope.hpp"

Antelope::Antelope() : Animal(ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE) {
}

Antelope::Antelope(Position position) : Animal(ANTELOPE_STRENGTH, ANTELOPE_INITIATIVE, position) {
}

void Antelope::take_action() {
}

void Antelope::collide() {
}
