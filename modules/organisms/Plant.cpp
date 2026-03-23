#include "../../headers/organisms/Plant.hpp"

Plant::Plant() : Organism() {
}

Plant::Plant(Position position) : Organism(position) {
}

Plant::Plant(int strength, Position position) : Organism(strength, position) {
}

Plant::Plant(int strength) : Organism(strength) {
}

void Plant::take_action() {
}

void Plant::collide() {
}
