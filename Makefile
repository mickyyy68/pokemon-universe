CC = clang
override CFLAGS += -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
OBJS = $(patsubst %.c, %.o, $(SRCS))

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

clean:
	rm -f $(OBJS) main

pokeMarket.o: pokeMarket.c all.h
	gcc -c pokeMarket.c

swapPokemons.o: swapPokemons.c all.h
	gcc -c swapPokemons.c

saveGame.o: saveGame.c all.h
	gcc -c saveGame.c

mainMenu.o: mainMenu.c all.h
	gcc -c mainMenu.c