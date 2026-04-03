#pragma once

#include "../Animal.hpp"

#define ANTELOPE_STRENGTH 4
#define ANTELOPE_INITIATIVE 4
#define ANTELOPE_SYMBOL 'A'
#define ANTELOPE_OFFSET_COUNT OFFSET_COUNT*2

class Antelope : public Animal {
public:
	inline static constexpr Position antelope_offsets[ANTELOPE_OFFSET_COUNT] = {{-2, -2}, {-2, -1}, {-2, 0}, {-2, 1}, {-2, 2}, {-1, -2}, {-1, 2}, {0, -2}, {0, 2}, {1, -2}, {1, 2}, {2, -2}, {2, -1}, {2, 0}, {2, 1}, {2, 2}};

	Antelope(World *world, Position position);

	void take_action() override;
	void collide(Organism *other) override;
};
