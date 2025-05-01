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
  // Pokémon Originali (0-4)
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
  
  // Nuovi Pokémon (5-24)
  // Bulbasaur (5) - Tipo Erba
  pokemon[5].maxHP = 110;
  pokemon[5].hp = 110;
  pokemon[5].atk = 15;
  pokemon[5].def = 25;
  pokemon[5].spd = 15;
  pokemon[5].xp = 12;
  pokemon[5].catchRate = 180;
  
  // Charmander (6) - Tipo Fuoco
  pokemon[6].maxHP = 95;
  pokemon[6].hp = 95;
  pokemon[6].atk = 22;
  pokemon[6].def = 18;
  pokemon[6].spd = 25;
  pokemon[6].xp = 12;
  pokemon[6].catchRate = 180;
  
  // Squirtle (7) - Tipo Acqua
  pokemon[7].maxHP = 105;
  pokemon[7].hp = 105;
  pokemon[7].atk = 18;
  pokemon[7].def = 28;
  pokemon[7].spd = 20;
  pokemon[7].xp = 12;
  pokemon[7].catchRate = 180;
  
  // Jigglypuff (8) - Tipo Normale
  pokemon[8].maxHP = 150;
  pokemon[8].hp = 150;
  pokemon[8].atk = 12;
  pokemon[8].def = 10;
  pokemon[8].spd = 8;
  pokemon[8].xp = 10;
  pokemon[8].catchRate = 210;
  
  // Meowth (9) - Tipo Normale
  pokemon[9].maxHP = 90;
  pokemon[9].hp = 90;
  pokemon[9].atk = 18;
  pokemon[9].def = 12;
  pokemon[9].spd = 35;
  pokemon[9].xp = 8;
  pokemon[9].catchRate = 230;
  
  // Growlithe (10) - Tipo Fuoco
  pokemon[10].maxHP = 95;
  pokemon[10].hp = 95;
  pokemon[10].atk = 25;
  pokemon[10].def = 16;
  pokemon[10].spd = 27;
  pokemon[10].xp = 14;
  pokemon[10].catchRate = 190;
  
  // Machop (11) - Tipo Lotta
  pokemon[11].maxHP = 115;
  pokemon[11].hp = 115;
  pokemon[11].atk = 35;
  pokemon[11].def = 18;
  pokemon[11].spd = 15;
  pokemon[11].xp = 16;
  pokemon[11].catchRate = 170;
  
  // Gastly (12) - Tipo Spettro
  pokemon[12].maxHP = 80;
  pokemon[12].hp = 80;
  pokemon[12].atk = 25;
  pokemon[12].def = 10;
  pokemon[12].spd = 32;
  pokemon[12].xp = 18;
  pokemon[12].catchRate = 150;
  
  // Onix (13) - Tipo Roccia
  pokemon[13].maxHP = 130;
  pokemon[13].hp = 130;
  pokemon[13].atk = 15;
  pokemon[13].def = 45;
  pokemon[13].spd = 18;
  pokemon[13].xp = 20;
  pokemon[13].catchRate = 120;
  
  // Hitmonlee (14) - Tipo Lotta
  pokemon[14].maxHP = 100;
  pokemon[14].hp = 100;
  pokemon[14].atk = 40;
  pokemon[14].def = 20;
  pokemon[14].spd = 30;
  pokemon[14].xp = 22;
  pokemon[14].catchRate = 100;
  
  // Lickitung (15) - Tipo Normale
  pokemon[15].maxHP = 140;
  pokemon[15].hp = 140;
  pokemon[15].atk = 20;
  pokemon[15].def = 22;
  pokemon[15].spd = 12;
  pokemon[15].xp = 18;
  pokemon[15].catchRate = 120;
  
  // Chansey (16) - Tipo Normale
  pokemon[16].maxHP = 200;
  pokemon[16].hp = 200;
  pokemon[16].atk = 8;
  pokemon[16].def = 10;
  pokemon[16].spd = 18;
  pokemon[16].xp = 25;
  pokemon[16].catchRate = 90;
  
  // Tangela (17) - Tipo Erba
  pokemon[17].maxHP = 120;
  pokemon[17].hp = 120;
  pokemon[17].atk = 22;
  pokemon[17].def = 30;
  pokemon[17].spd = 14;
  pokemon[17].xp = 20;
  pokemon[17].catchRate = 110;
  
  // Kangaskhan (18) - Tipo Normale
  pokemon[18].maxHP = 135;
  pokemon[18].hp = 135;
  pokemon[18].atk = 30;
  pokemon[18].def = 25;
  pokemon[18].spd = 25;
  pokemon[18].xp = 25;
  pokemon[18].catchRate = 80;
  
  // Scyther (19) - Tipo Insetto
  pokemon[19].maxHP = 110;
  pokemon[19].hp = 110;
  pokemon[19].atk = 35;
  pokemon[19].def = 22;
  pokemon[19].spd = 38;
  pokemon[19].xp = 28;
  pokemon[19].catchRate = 70;
  
  // Electabuzz (20) - Tipo Elettro
  pokemon[20].maxHP = 115;
  pokemon[20].hp = 115;
  pokemon[20].atk = 32;
  pokemon[20].def = 20;
  pokemon[20].spd = 36;
  pokemon[20].xp = 30;
  pokemon[20].catchRate = 60;
  
  // Magmar (21) - Tipo Fuoco
  pokemon[21].maxHP = 115;
  pokemon[21].hp = 115;
  pokemon[21].atk = 34;
  pokemon[21].def = 22;
  pokemon[21].spd = 32;
  pokemon[21].xp = 30;
  pokemon[21].catchRate = 60;
  
  // Gyarados (22) - Tipo Acqua
  pokemon[22].maxHP = 140;
  pokemon[22].hp = 140;
  pokemon[22].atk = 40;
  pokemon[22].def = 28;
  pokemon[22].spd = 30;
  pokemon[22].xp = 40;
  pokemon[22].catchRate = 45;
  
  // Lapras (23) - Tipo Acqua/Ghiaccio
  pokemon[23].maxHP = 160;
  pokemon[23].hp = 160;
  pokemon[23].atk = 28;
  pokemon[23].def = 32;
  pokemon[23].spd = 22;
  pokemon[23].xp = 35;
  pokemon[23].catchRate = 50;
  
  // Eevee (24) - Tipo Normale
  pokemon[24].maxHP = 105;
  pokemon[24].hp = 105;
  pokemon[24].atk = 22;
  pokemon[24].def = 20;
  pokemon[24].spd = 28;
  pokemon[24].xp = 20;
  pokemon[24].catchRate = 140;
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
  printf("[0] -> Pikachu (Elettro)\n");
  printf("[1] -> Bulbasaur (Erba)\n");
  printf("[2] -> Charmander (Fuoco)\n");
  printf("[3] -> Squirtle (Acqua)\n");
  printf("[4] -> Eevee (Normale)\n-> ");
  resetcolor;
  do{
    scanf(" %d", &firstPokemonChoice);
  }while(firstPokemonChoice < 0 || firstPokemonChoice > 4);
  clear;
  cyan;
  // Mappa le scelte ai Pokémon effettivi
  int pokemonEffettivo;
  switch(firstPokemonChoice) {
    case 0: pokemonEffettivo = 0; break; // Pikachu
    case 1: pokemonEffettivo = 5; break; // Bulbasaur
    case 2: pokemonEffettivo = 6; break; // Charmander
    case 3: pokemonEffettivo = 7; break; // Squirtle
    case 4: pokemonEffettivo = 24; break; // Eevee
  }
  firstPokemonChoice = pokemonEffettivo;
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


