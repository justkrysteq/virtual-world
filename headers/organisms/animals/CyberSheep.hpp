#include "../Animal.hpp"

#define CYBER_SHEEP_STRENGTH 10
#define CYBER_SHEEP_INITIATIVE 4
#define CYBER_SHEEP_SYMBOL 'C'

class CyberSheep : public Animal {
public:
	CyberSheep();
	CyberSheep(Position position);

	void take_action() override;
};
