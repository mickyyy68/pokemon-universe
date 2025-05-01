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

void catchPokemon(){
  catching = 1;
  do{
    
    printf("\n");
    printf("◓ | Pokeballs: %d\n", player.borsa.pokeBalls);
    printf("Cosa vuoi usare?");
    printf("\n1 - Pokeball");
    printf("\n2 - Megaball");
    printf("\n3 - Ultraball\n");
    printf("-> ");
    do{
      scanf("%d", &borsaChoice);
    }while(borsaChoice != 1 && borsaChoice != 2 && borsaChoice != 3);


    // Se ha scelto una ball da lanciare ma non le ha
    red;
    // Pokeball
    if(borsaChoice == 1 && player.borsa.pokeBalls <= 0){
      printf("Non hai pokeball!\n\n");
      clear;
    }
    // GreatBall(Megaball)
    else if(borsaChoice == 2 && player.borsa.greatBalls <= 0){
      printf("Non hai megaball!\n\n");
      clear;
    }
    // Ultraball
    else if(borsaChoice == 3 && player.borsa.ultraBalls <= 0){
      printf("Non hai ultraball!\n\n");
      clear;
    }
    resetcolor;
    
    // Se ha lanciato una pokeball
    if(borsaChoice == 1 && player.borsa.pokeBalls > 0){
      player.borsa.pokeBalls -= 1;
      // Se cattura il pokemon con una probabilita
      if(rand() <  0.25 * ((double)RAND_MAX + 1.0)){
        printf("Lo hai catturato!\n");
        sleep(1);
        
        // Aggiorna il Pokedex
        extern void updatePokedex(int indexPokemon, int catturato);
        updatePokedex(pokemonSelvatico.index, 1);
        
        if(slot[0].slotPieno == 0)
          slotLibero = 0;
        else if(slot[1].slotPieno == 0)
          slotLibero = 1;
        else if(slot[2].slotPieno == 0)
          slotLibero = 2;
        else if(slot[3].slotPieno == 0)
          slotLibero = 3;
        else if(slot[4].slotPieno == 0)
          slotLibero = 4;
        else if(slot[5].slotPieno == 0)
          slotLibero = 5;
        else{
          printf("Ma non hai potuto metterlo da nessuna parte!\nSLOT PIENI.(PC WORK IN PROGRESS...)");
          slotLibero = 392318;
        }
        slotLibero = 2;
        
        // Copio le statistiche del pokemon nello slot.
        strcpy(slot[slotLibero].nome, pokemonSelvatico.nome);
        slot[slotLibero].index = pokemonSelvatico.index;
        slot[slotLibero].maxHP = pokemonSelvatico.maxHP;
        slot[slotLibero].hp = pokemonSelvatico.hp;
        slot[slotLibero].atk = pokemonSelvatico.atk;
        slot[slotLibero].def = pokemonSelvatico.def;
        slot[slotLibero].spd = pokemonSelvatico.spd;
        slot[slotLibero].livello = pokemonSelvatico.livello;
        
        fighting = 0;
      }
      clear;
    }
    catching = 0;
  }while(catching == 1);
}