#include "all.h"

extern t_player player;
extern int cittaAttuale;
extern t_slot slot[7];
extern int i;
extern t_pokemon pokemon[POKEMONS];
extern t_pokemonSelvatico pokemonSelvatico;

extern void swapPokemons();
extern void pokeBattle();

int borsaChoice;
int catching; // bool
int slotLibero;
extern int fighting;

int trovaSlotLibero() {
  for (int i = 0; i < 6; i++)
    if (slot[i].slotPieno == 0)
      return i;
  return -1;
}

void catchPokemon() {
  catching = 1;
  do {

    printf("\n");
    printf("◓ | Pokeballs: %d\n", player.borsa.pokeBalls);
    printf("Cosa vuoi usare?");
    printf("\n1 - Pokeball");
    printf("\n2 - Megaball");
    printf("\n3 - Ultraball\n");
    printf("-> ");
    do {
      scanf("%d", &borsaChoice);
    } while (borsaChoice != 1 && borsaChoice != 2 && borsaChoice != 3);

    // Se ha scelto una ball da lanciare ma non le ha
    red;
    // Pokeball
    if (borsaChoice == 1 && player.borsa.pokeBalls <= 0) {
      printf("Non hai pokeball!\n\n");
      clear;
    }
    // GreatBall(Megaball)
    else if (borsaChoice == 2 && player.borsa.greatBalls <= 0) {
      printf("Non hai megaball!\n\n");
      clear;
    }
    // Ultraball
    else if (borsaChoice == 3 && player.borsa.ultraBalls <= 0) {
      printf("Non hai ultraball!\n\n");
      clear;
    }
    resetcolor;

    // Se ha lanciato una pokeball
    if (borsaChoice == 1 && player.borsa.pokeBalls > 0) {
      player.borsa.pokeBalls -= 1;
      // Se cattura il pokemon con una probabilita
      if (rand() < 0.25 * ((double)RAND_MAX + 1.0)) {
        printf("Lo hai catturato!\n");
        sleep(1);

        // Aggiorna il Pokedex
        extern void updatePokedex(int indexPokemon, int catturato);
        updatePokedex(pokemonSelvatico.index, 1);

        int slotLibero = trovaSlotLibero();

        // Copio le statistiche del pokemon nello slot.
        strcpy(slot[slotLibero].nome, pokemonSelvatico.nome);
        slot[slotLibero].index = pokemonSelvatico.index;
        slot[slotLibero].maxHP = pokemonSelvatico.maxHP;
        slot[slotLibero].hp = pokemonSelvatico.hp;
        slot[slotLibero].atk = pokemonSelvatico.atk;
        slot[slotLibero].def = pokemonSelvatico.def;
        slot[slotLibero].spd = pokemonSelvatico.spd;
        slot[slotLibero].livello = pokemonSelvatico.livello;
        slot[slotLibero].slotPieno = 1;

        fighting = 0;
      }
      clear;
    }
    catching = 0;
  } while (catching == 1);
}