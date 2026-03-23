#include "../../headers/organisms/Animal.hpp"

Animal::Animal() : Organism() {
}

Animal::Animal(int strength, int initiative) : Organism(strength, initiative) {
}

Animal::Animal(int strength, int initiative, Position position) : Organism(strength, initiative, position) {
}

void Animal::take_action() {
}

void Animal::collide() {
}
