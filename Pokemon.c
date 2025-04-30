#include "all.h"

extern t_pokemon pokemon[POKEMONS];
extern t_slot slot[7];
extern t_player player;
extern int i;
extern char *pokemonsNames[POKEMONS];
extern int copyStatsFromToSlot();
extern int copyStatsToPokemonSelvatico();
int firstPokemonChoice;


void inizializeStatsPokemon(){
//--------------------------------Qui metto manualmente le stats    ------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------//
  // Le graffe sono facoltative, ma cosi ho più controllo
  // Qui setto manualmente le stats ai pokemon(base stats)
  {
  // Pikachu
  pokemon[0].maxHP = 100;
  pokemon[0].hp = 100;
  pokemon[0].atk = 20;
  pokemon[0].def = 15;
  pokemon[0].spd = 30;
  pokemon[0].xp = 10;
  pokemon[0].catchRate = 190;

  // Rattata
  pokemon[1].maxHP = 100;
  pokemon[1].hp = 100;
  pokemon[1].atk = 5;
  pokemon[1].def = 5;
  pokemon[1].spd = 10;
  pokemon[1].xp = 5;
  pokemon[1].catchRate = 255;

  // Arch
  pokemon[2].maxHP = 100;
  pokemon[2].hp = 100;
  pokemon[2].atk = 30;
  pokemon[2].def = 30;
  pokemon[2].spd = 15;
  pokemon[2].xp = 25;
  pokemon[2].catchRate = 75;
    
  // Void
  pokemon[3].maxHP = 90;
  pokemon[3].hp = 90;
  pokemon[3].atk = 30;
  pokemon[3].def = 15;
  pokemon[3].spd = 20;
  pokemon[3].xp = 50;
  pokemon[3].catchRate = 50;
    
  // Arcanine
  pokemon[4].maxHP = 100;
  pokemon[4].hp = 100;
  pokemon[4].atk = 30;
  pokemon[4].def = 20;
  pokemon[4].spd = 50;
  pokemon[4].xp = 15;
  pokemon[4].catchRate = 75;
  }

//--------------------------------Qui metto i nomi ai pokemons    ------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------//
  // Metto le statistiche ai pokemon //////////////////////
  for(i = 0; i < POKEMONS; i++){
    strcpy(pokemon[i].nome, pokemonsNames[i]);
    pokemon[i].index = i;
  }
}


void askFirstPokemon(){
  red;
  printf("Quale pokemon vuoi scegliere?\n");
  resetcolor;
  cyan;
  printf("[0] -> Pikachu\n[1] -> Arcanine\n-> ");
  resetcolor;
  do{
    scanf(" %d", &firstPokemonChoice);
  }while(firstPokemonChoice != 0 && firstPokemonChoice != 1);
  clear;
  cyan;
  if(firstPokemonChoice == 1)
    firstPokemonChoice = 4; // setto l'index del pokemon, cosi posso printare il nome del pokemon giusto.
  printf("Hai scelto %s!\n", pokemon[firstPokemonChoice].nome);
  resetcolor;
  
  // Ora al mio slot 0, quindi ai pokemon che ho, lo inserisco, mettendo le statistiche del pokemon scelto al mio slot 
  // 1° Pokemon
  copyStatsFromToSlot(firstPokemonChoice, 5, 0); // 5 è il livello, 0 è lo slot, FirstPokemonChoice è l'index del pokemon
  // 2° Pokemon
  copyStatsFromToSlot(0, 4, 1); // 4 è il livello, 1 è lo slot
  slot[0].slotPieno = 1;
  slot[1].slotPieno = 1;
  slot[2].slotPieno = 0;
  slot[3].slotPieno = 0;
  slot[4].slotPieno = 0;
  slot[5].slotPieno = 0;

  player.borsa.soldi = 500;
  player.borsa.pokeBalls = 5;
}


