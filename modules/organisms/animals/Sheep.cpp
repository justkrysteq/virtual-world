#include "../../../headers/organisms/animals/Sheep.hpp"

Sheep::Sheep() : Animal(SHEEP_STRENGTH, SHEEP_INITIATIVE) {
}

Sheep::Sheep(Position position) : Animal(SHEEP_STRENGTH, SHEEP_INITIATIVE, position) {
}
