#include "../../../headers/organisms/plants/Guarana.hpp"

Guarana::Guarana() : Plant(GUARANA_SYMBOL, PAIR_GUARANA) {
}

Guarana::Guarana(Position position) : Plant(position, GUARANA_SYMBOL, PAIR_GUARANA) {
}

void Guarana::collide() {
}
