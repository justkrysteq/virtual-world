#include "../../../headers/organisms/animals/Wolf.hpp"

Wolf::Wolf() : Animal(WOLF_STRENGTH, WOLF_INITIATIVE, WOLF_SYMBOL, PAIR_WOLF) {
}

Wolf::Wolf(Position position) : Animal(WOLF_STRENGTH, WOLF_INITIATIVE, position, WOLF_SYMBOL, PAIR_WOLF) {
}

