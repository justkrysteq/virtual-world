#include "../Animal.hpp"

#define CYBER_SHEEP_STRENGTH 10
#define CYBER_SHEEP_INITIATIVE 4

class CyberSheep : public Animal {
public:
	CyberSheep();
	CyberSheep(Position position);

	void take_action() override;
};
