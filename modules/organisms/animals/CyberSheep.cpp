#include "../../../headers/organisms/animals/CyberSheep.hpp"

CyberSheep::CyberSheep() : Animal(CYBER_SHEEP_STRENGTH, CYBER_SHEEP_INITIATIVE, CYBER_SHEEP_SYMBOL, PAIR_CYBER_SHEEP) {
}

CyberSheep::CyberSheep(Position position) : Animal(CYBER_SHEEP_STRENGTH, CYBER_SHEEP_INITIATIVE, position, CYBER_SHEEP_SYMBOL, PAIR_CYBER_SHEEP) {
}

void CyberSheep::take_action() {
}
