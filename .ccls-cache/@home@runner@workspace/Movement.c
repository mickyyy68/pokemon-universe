#include "all.h"
extern t_player player;
extern int disegnoCitta[2][CITTA_RIGHE][CITTA_COLONNE];
extern int cittaAttuale;
extern t_slot slot[7];
extern int i;
extern t_pokemon pokemon[POKEMONS];

extern void swapPokemons();
extern void pokeBattle();
extern void pokeMarket();

int selectMovement(char movementChoice) {
  // ALTO
  if (movementChoice == 'w') {
    clear;
    // La spiegazione dell'if la trovi quando ti sposti a destra(più sotto qui
    // nel code)
    if (player.posY > 0 &&
        disegnoCitta[cittaAttuale][player.posY - 1][player.posX] != 1)
      player.posY--;
  }
  // DESTRA
  else if (movementChoice == 'd') {
    clear;
    // Se a destra hai spazio vai, e se a destra non hai un blocco verde( != 1
    // --> blocco verde(1))
    if (player.posX < CITTA_COLONNE - 1 &&
        disegnoCitta[cittaAttuale][player.posY][player.posX + 1] != 1)
      player.posX++;
  } else if (movementChoice == 'a') {
    clear;
    if (player.posX > 0 &&
        disegnoCitta[cittaAttuale][player.posY][player.posX - 1] != 1)
      player.posX--;
  } else if (movementChoice == 's') {
    clear;
    if (player.posY < CITTA_RIGHE - 1 &&
        disegnoCitta[cittaAttuale][player.posY + 1][player.posX] != 1)
      player.posY++;
  } else if (movementChoice == 'p') {
    swapPokemons();
  }
  //--------------------------------COSA SUCCEDE IN OGNI TILE
  //---------------------------------------------------------------------//
  //-------------------------------------------------------------------------------------------------------------------------------------------//

  // Se entri nell'erba(robo arancione) incontri un pokemon
  if (disegnoCitta[cittaAttuale][player.posY][player.posX] == 2) {
    // POKEMON //////////////////////
    clear;
    // hai il 30% di incontrare un pokemon, e se il pokemon in slot 0 ha più di
    // 0 di vita
    if (rand() < 0.3 * ((double)RAND_MAX + 1.0) && slot[0].hp > 0) {
      pokeBattle();
    }
    // se il pokemon è morto glielo dico
    if (slot[0].hp <= 0) {
      clear;
      red;
      printf("Il tuo pokemon è esausto...\n");
      resetcolor;
    }
  }

  // Per interagire con ospedale o negozio ora serve premere 'E'
  else if (movementChoice == 'e' || movementChoice == 'E') {
    // Se si trova nell'ospedale
    if (disegnoCitta[cittaAttuale][player.posY][player.posX] == 3) {
      clear;
      green;
      printf("Benvenuto al Centro Pokémon!\n");
      printf("I tuoi Pokémon sono stati curati completamente.\n");
      resetcolor;
      for (i = 0; i < 6; i++)
        slot[i].hp = slot[i].maxHP;
      sleep(1);
    }
    // Se si trova nel pokemarket
    else if (disegnoCitta[cittaAttuale][player.posY][player.posX] == 4) {
      pokeMarket();
    }
  }

  // SE VUOLE CAMBIARE MAPPA
  else if (disegnoCitta[cittaAttuale][player.posY][player.posX] == 5) {
    if (cittaAttuale < 6) {
      cittaAttuale++;
      player.posX = 1;
      player.posY = 3;
    }
  } else if (disegnoCitta[cittaAttuale][player.posY][player.posX] == 6) {
    if (cittaAttuale > 0) {
      cittaAttuale--;
      player.posX = 13;
      player.posY = 3;
    }
  }
}