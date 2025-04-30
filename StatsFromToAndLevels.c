#include "all.h"
extern t_pokemon pokemon[POKEMONS];
extern t_slot slot[7];
extern int i;
extern t_pokemonSelvatico pokemonSelvatico;

int xpTotali; // xp del pokemon

int copyStatsFromToSlot(int fromPokemon, int livello, int slotScelto){
  strcpy(slot[slotScelto].nome, pokemon[fromPokemon].nome);
  slot[slotScelto].index = pokemon[fromPokemon].index;
  // prima metto le statistiche base
  slot[slotScelto].maxHP = pokemon[fromPokemon].maxHP;
  slot[slotScelto].hp = pokemon[fromPokemon].hp;
  slot[slotScelto].atk = pokemon[fromPokemon].atk;
  slot[slotScelto].def = pokemon[fromPokemon].def;
  slot[slotScelto].spd = pokemon[fromPokemon].spd;
  // e poi aggiungo 1/20 delle statistiche base per ogni livello.
  for(i = 1; i <= livello; i++){
    slot[slotScelto].maxHP += pokemon[fromPokemon].maxHP / 20;
    slot[slotScelto].hp += pokemon[fromPokemon].hp / 20;
    slot[slotScelto].atk += pokemon[fromPokemon].atk / 20;
    slot[slotScelto].def += pokemon[fromPokemon].def / 20;
    slot[slotScelto].spd += pokemon[fromPokemon].spd / 20; 
  }
  // infine gli metto il livello al pokemonTo
  slot[slotScelto].livello = livello;
  slot[slotScelto].catchRate = pokemon[fromPokemon].catchRate;
  return 0;
}

// Per i pokemon selvatici(metto anche l'xp)
int copyStatsToPokemonSelvatico(int fromPokemon, int livello){
  
  strcpy(pokemonSelvatico.nome, pokemon[fromPokemon].nome);
  pokemonSelvatico.maxHP = pokemon[fromPokemon].maxHP;
  pokemonSelvatico.hp = pokemon[fromPokemon].hp;
  pokemonSelvatico.atk = pokemon[fromPokemon].atk;
  pokemonSelvatico.def = pokemon[fromPokemon].def;
  pokemonSelvatico.spd = pokemon[fromPokemon].spd;
  xpTotali = pokemon[fromPokemon].xp;
  for(i = 1; i <= livello; i++){
    pokemonSelvatico.maxHP += pokemon[fromPokemon].maxHP / 20;
    pokemonSelvatico.hp += pokemon[fromPokemon].hp / 20;
    pokemonSelvatico.atk += pokemon[fromPokemon].atk / 20;
    pokemonSelvatico.def += pokemon[fromPokemon].def / 20;
    pokemonSelvatico.spd += pokemon[fromPokemon].spd / 20;
    xpTotali += pokemon[fromPokemon].xp;
  }
  pokemonSelvatico.xp = xpTotali;
  pokemonSelvatico.livello = livello;
  pokemonSelvatico.catchRate = pokemon[fromPokemon].catchRate;
}




int copyName, copyIndex, copyMaxHp, copyHp, copyAtk, copyDef, copySpd, copyLvl;
int boolCopyStatsFromToSlot(int indexPokemon, int livello, int slotScelto, int copyName, int copyIndex, int copyMaxHp, int copyHp, int copyAtk, int copyDef, int copySpd, int copyLvl){
  if(copyName)
    strcpy(slot[slotScelto].nome, pokemon[indexPokemon].nome);
  if(copyIndex)
    slot[slotScelto].index = pokemon[indexPokemon].index;
  // prima metto le statistiche base
  if(copyMaxHp)
    slot[slotScelto].maxHP = pokemon[indexPokemon].maxHP;
  if(copyHp)
    slot[slotScelto].hp = pokemon[indexPokemon].hp;
  if(copyAtk)
    slot[slotScelto].atk = pokemon[indexPokemon].atk;
  if(copyDef)
    slot[slotScelto].def = pokemon[indexPokemon].def;
  if(copySpd)
    slot[slotScelto].spd = pokemon[indexPokemon].spd;
  // e poi aggiungo 1/20 delle statistiche base per ogni livello.
  for(i = 1; i < livello; i++){
    if(copyMaxHp)
      slot[slotScelto].maxHP += pokemon[indexPokemon].maxHP / 20;
    if(copyHp)
      slot[slotScelto].hp += pokemon[indexPokemon].hp / 20;
    if(copyAtk)  
      slot[slotScelto].atk += pokemon[indexPokemon].atk / 20;
    if(copyDef)
      slot[slotScelto].def += pokemon[indexPokemon].def / 20;
    if(copySpd)
      slot[slotScelto].spd += pokemon[indexPokemon].spd / 20; 
  }
  // infine gli metto il livello al pokemonTo
  if(copyLvl)
    slot[slotScelto].livello = livello;
  return 0;
}






int slotSwapFrom, slotSwapTo;
// SERVE PER GLI SWAP DEI POKEMON
int swappingPokemons(int slotSwapFrom, int slotSwapTo){
  strcpy(slot[slotSwapTo].nome, slot[slotSwapFrom].nome);
  slot[slotSwapTo].index = slot[slotSwapFrom].index;
  slot[slotSwapTo].maxHP = slot[slotSwapFrom].maxHP;
  slot[slotSwapTo].hp = slot[slotSwapFrom].hp;
  slot[slotSwapTo].atk = slot[slotSwapFrom].atk;
  slot[slotSwapTo].def = slot[slotSwapFrom].def;
  slot[slotSwapTo].spd = slot[slotSwapFrom].spd;
  slot[slotSwapTo].xp = slot[slotSwapFrom].xp;
  slot[slotSwapTo].livello = slot[slotSwapFrom].livello;
}



void swapPokemons(){
  clear;
  cyan;
  printf("Slot 1\n");
  resetcolor;
  printf("%s", slot[0].nome);
  cyan;
  printf("\nSlot 2\n");
  resetcolor;
  printf("%s", slot[1].nome);
  cyan;
  printf("\nSlot 3\n");
  resetcolor;
  printf("%s", slot[2].nome);
  cyan;
  printf("\nSlot 4\n");
  resetcolor;
  printf("%s", slot[3].nome);
  cyan;
  printf("\nSlot 5\n");
  resetcolor;
  printf("%s", slot[4].nome);
  cyan;
  printf("\nSlot 6\n");
  resetcolor;
  printf("%s", slot[5].nome);
  printf("\n\n");
  printf("Chi vorresti scambiare?");
  printf("\nDa slot n°: ");
  scanf("%d", &slotSwapFrom);
  printf("A slot n°: ");
  scanf("%d", &slotSwapTo);
  swappingPokemons(slotSwapFrom-1, 6); // variabile temporanea
  swappingPokemons(slotSwapTo-1, slotSwapFrom-1); // ora sposto lo slot 1 allo slot 0
  swappingPokemons(6, slotSwapTo-1); // ora sposto lo slot 7(aka 0) allo slot 1
  slot[slotSwapFrom-1].slotPieno = 1;
  slot[slotSwapTo-1].slotPieno = 1;
  
  
  // -1 perchè se tipo l'utente sceglie slot 1, io facendo 1-1 fa 0 e infatti lo slot 1 è in realtà lo slot 0
  
  /* COME ERA PRIMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
  // Variabile temporanea
  copyStatsFromToSlot(slot[slotSwapFrom].index, slot[slotSwapFrom].livello, 6);
  slot[6].xp = slot[slotSwapFrom].xp;

  // Sposto allo slot 0
  copyStatsFromToSlot(slot[slotSwapTo].index, slot[slotSwapTo].livello, 0);
  slot[slotSwapTo].xp = slot[6].xp;
  // Sposto allo slot 1
  copyStatsFromToSlot(slot[6].index, slot[6].livello, 1);
  slot[1].xp = slot[6].xp;
  // Funziona, ma devo riscrivere un'altra volta la roba delle copyStats perchè altrimenti gli hp li resetta. Potrei fare delle variabili bool per quello. Se tipo CopyHp = True, copio gli hp, se CopyAtk = true, copio gli atk e cosi via...
  */

}

// https://bulbapedia.bulbagarden.net/wiki/Catch_rate