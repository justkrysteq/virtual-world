#include "../../../headers/organisms/animals/Fox.hpp"

Fox::Fox() : Animal(FOX_STRENGTH, FOX_INITIATIVE) {
}

Fox::Fox(Position position) : Animal(FOX_STRENGTH, FOX_INITIATIVE, position) {
}

void Fox::take_action() {
}
