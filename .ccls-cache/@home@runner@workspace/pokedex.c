
#include "all.h"

extern t_pokemon pokemon[POKEMONS];
extern t_player player;

// Array per tracciare quali pokemon sono stati visti o catturati
extern int pokemonVisti[POKEMONS];
extern int pokemonCatturati[POKEMONS];

void updatePokedex(int indexPokemon, int catturato) {
  // Segna il pokemon come visto
  pokemonVisti[indexPokemon] = 1;

  // Se è stato catturato, lo segniamo anche come catturato
  if (catturato) {
    pokemonCatturati[indexPokemon] = 1;
  }
}

void mostraPokedex() {
  clear;
  int numVisti = 0;
  int numCatturati = 0;

  // Conta quanti Pokémon sono stati visti e catturati
  for (int i = 0; i < POKEMONS; i++) {
    if (pokemonVisti[i])
      numVisti++;
    if (pokemonCatturati[i])
      numCatturati++;
  }

  cyan;
  bold;
  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("┃            POKÉDEX                 ┃\n");
  printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
  resetcolor;
  printf("┃ Pokémon visti: %-3d/%-3d            ┃\n", numVisti, POKEMONS);
  printf("┃ Pokémon catturati: %-3d/%-3d         ┃\n", numCatturati, POKEMONS);
  printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");

  // Mostra l'elenco dei Pokémon
  for (int i = 0; i < POKEMONS; i++) {
    if (pokemonVisti[i]) {
      // Se è stato catturato, mostriamo tutti i dettagli
      if (pokemonCatturati[i]) {
        green;
        printf("┃ #%-2d %-10s - Catturato!          ┃\n", i, pokemon[i].nome);
        resetcolor;
      } else {
        // Se è stato solo visto, mostriamo meno informazioni
        yellow;
        printf("┃ #%-2d %-10s - Visto               ┃\n", i, pokemon[i].nome);
        resetcolor;
      }
    } else {
      // Se non è stato visto, mostriamo solo ???
      printf("┃ #%-2d ???                           ┃\n", i);
    }
  }
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

  printf("\nPremi un tasto per tornare al gioco...");
  getchar(); // aspetta input
  clear;
}
