#include "../Animal.hpp"

#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4

class Human : public Animal {
public:
	Human();
	Human(Position position);

	void take_action() override;
	void collide() override;
};
