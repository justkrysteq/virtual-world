#include "../../headers/organisms/Plant.hpp"

Plant::Plant() : Organism() {
}

Plant::Plant(Position position) : Organism(position) {
}

Plant::Plant(int strength, Position position) : Organism(strength, position) {
}

Plant::Plant(int strength) : Organism(strength) {
}

Plant::Plant(char symbol, int color) : Organism(symbol, color) {
}

Plant::Plant(Position position, char symbol, int color) : Organism(position, symbol, color) {
}

Plant::Plant(int strength, Position position, char symbol, int color) : Organism(strength, position, symbol, color) {
}

Plant::Plant(int strength, char symbol, int color) : Organism(strength, symbol, color) {
}


void Plant::take_action() {
}

void Plant::collide() {
}
