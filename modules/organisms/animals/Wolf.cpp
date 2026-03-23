#include "../../../headers/organisms/animals/Wolf.hpp"

Wolf::Wolf() : Animal(WOLF_STRENGTH, WOLF_INITIATIVE) {
}

Wolf::Wolf(Position position) : Animal(WOLF_STRENGTH, WOLF_INITIATIVE, position) {
}

