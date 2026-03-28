#include "../../../headers/organisms/plants/Grass.hpp"

Grass::Grass() : Plant(GRASS_SYMBOL, PAIR_GRASS) {
}

Grass::Grass(Position position) : Plant(position, GRASS_SYMBOL, PAIR_GRASS) {
}
