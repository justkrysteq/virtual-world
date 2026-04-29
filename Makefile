COMPILER = g++
CFLAGS = -c -Wall -Wextra -Wpedantic -Werror -Wstrict-overflow=5 -Wimplicit-fallthrough=3 -Warray-bounds=2 -Wstringop-overflow=4 -Wformat=2 -Wformat-security -D_FORTIFY_SOURCE=3 -fstack-protector-strong -fstack-clash-protection -fPIE -pie -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -fno-strict-overflow -fno-strict-aliasing -fsanitize=address -fsanitize=undefined -fsanitize=leak -fno-omit-frame-pointer
CFLAGS = -c
# LDFLAGS = -lasan -lubsan -lncurses
LDFLAGS = -lncurses

SRCS = main.cpp $(wildcard modules/*.cpp) $(wildcard modules/organisms/*.cpp) $(wildcard modules/organisms/animals/*.cpp) $(wildcard modules/organisms/plants/*.cpp)
OBJS = ${SRCS:.cpp=.o}

all: virtual-world

virtual-world: ${OBJS}
	${COMPILER} -o $@ $^ ${LDFLAGS}
	rm -f ${OBJS}

main.o: main.cpp
	${COMPILER} ${CFLAGS} main.cpp

clean:
	rm -f ${OBJS} virtual-world
