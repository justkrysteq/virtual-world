#include "../../../headers/organisms/plants/Wolfberries.hpp"

Wolfberries::Wolfberries() : Plant(WOLFBERRIES_STRENGTH) {
}

Wolfberries::Wolfberries(Position position) : Plant(WOLFBERRIES_STRENGTH, position) {
}

void Wolfberries::collide() {
}
