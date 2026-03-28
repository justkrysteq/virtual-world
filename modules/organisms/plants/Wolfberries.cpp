#include "../../../headers/organisms/plants/Wolfberries.hpp"

Wolfberries::Wolfberries() : Plant(WOLFBERRIES_STRENGTH, WOLFBERRIES_SYMBOL, PAIR_WOLFBERRIES) {
}

Wolfberries::Wolfberries(Position position) : Plant(WOLFBERRIES_STRENGTH, position, WOLFBERRIES_SYMBOL, PAIR_WOLFBERRIES) {
}

void Wolfberries::collide() {
}
