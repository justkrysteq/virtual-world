#include "../../headers/organisms/Animal.hpp"

Animal::Animal() : Organism() {
}

Animal::Animal(int strength, int initiative) : Organism(strength, initiative) {
}

Animal::Animal(int strength, int initiative, Position position) : Organism(strength, initiative, position) {
}

Animal::Animal(int strength, int initiative, char symbol, int color) : Organism(strength, initiative, symbol, color) {
}

Animal::Animal(int strength, int initiative, Position position, char symbol, int color) : Organism(strength, initiative, position, symbol, color) {
}

void Animal::take_action() {
}

void Animal::collide() {
}
