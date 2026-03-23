#include "../../../headers/organisms/animals/CyberSheep.hpp"

CyberSheep::CyberSheep() : Animal(CYBER_SHEEP_STRENGTH, CYBER_SHEEP_INITIATIVE) {
}

CyberSheep::CyberSheep(Position position) : Animal(CYBER_SHEEP_STRENGTH, CYBER_SHEEP_INITIATIVE, position) {
}

void CyberSheep::take_action() {
}
