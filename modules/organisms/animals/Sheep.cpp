#include "../../../headers/organisms/animals/Sheep.hpp"

Sheep::Sheep() : Animal(SHEEP_STRENGTH, SHEEP_INITIATIVE, SHEEP_SYMBOL, PAIR_SHEEP) {
}

Sheep::Sheep(Position position) : Animal(SHEEP_STRENGTH, SHEEP_INITIATIVE, position, SHEEP_SYMBOL, PAIR_SHEEP) {
}
