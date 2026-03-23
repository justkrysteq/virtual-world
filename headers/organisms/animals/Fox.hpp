#include "../Animal.hpp"

#define FOX_STRENGTH 3
#define FOX_INITIATIVE 7

class Fox : public Animal {
public:
	Fox();
	Fox(Position position);

	void take_action() override;
};
