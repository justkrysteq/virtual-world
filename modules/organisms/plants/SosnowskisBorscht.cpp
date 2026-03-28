#include "../../../headers/organisms/plants/SosnowskisBorscht.hpp"

SosnowskisBorscht::SosnowskisBorscht() : Plant(SOSNOWKIS_BORSCHT_STRENGTH, SOSNOWKIS_BORSCHT_SYMBOL, PAIR_SOSNOWKIS_BORSCHT) {
}

SosnowskisBorscht::SosnowskisBorscht(Position position) : Plant(SOSNOWKIS_BORSCHT_STRENGTH, position, SOSNOWKIS_BORSCHT_SYMBOL, PAIR_SOSNOWKIS_BORSCHT) {
}

void SosnowskisBorscht::take_action() {
}

void SosnowskisBorscht::collide() {
}
