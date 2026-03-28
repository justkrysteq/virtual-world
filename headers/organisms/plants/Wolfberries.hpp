#include "../Plant.hpp"

#define WOLFBERRIES_STRENGTH 99
#define WOLFBERRIES_SYMBOL 'w'

class Wolfberries : public Plant {
public:
	Wolfberries();
	Wolfberries(Position position);

	void collide() override;
};
