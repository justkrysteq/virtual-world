#include "../../../headers/organisms/animals/Fox.hpp"

Fox::Fox() : Animal(FOX_STRENGTH, FOX_INITIATIVE, FOX_SYMBOL, PAIR_FOX) {
}

Fox::Fox(Position position) : Animal(FOX_STRENGTH, FOX_INITIATIVE, position, FOX_SYMBOL, PAIR_FOX) {
}

void Fox::take_action() {
}
