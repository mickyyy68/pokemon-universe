#include "all.h"


extern t_player player;
extern int disegnoCitta[2][CITTA_RIGHE][CITTA_COLONNE];
extern int cittaAttuale;
extern int i;
extern t_slot slot[7];
extern int writeHP();
extern t_player player;


extern void swapSlotToSlot();


//--------------------------------PRINTO IL MENU              -------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------//
void printMenu(){
  
  printf("\n\n");
  printf("[w] - [a] - [s] - [d]\n");
  red;
  printf("\n%s:\n", slot[0].nome);
  resetcolor;
  // SCRIVO LA VITA DEL POKEMON SLOT 0 /////////
  if(slot[0].hp > 0){
    writeHP(slot[0].hp, slot[0].maxHP);  
  // altrimenti no
  }else{
    red;
    printf("Il pokemon è esausto...\n");
    resetcolor;
  }
  
  // Statistiche pokemon slot 1
  printf("🔷 | Lvl: %d\n", slot[0].livello);
  printf("🧿 | XP:  %d\n", slot[0].xp);
  printf("🔫 | Atk: %d\n", slot[0].atk);
  printf("🛡️  | Def: %d\n", slot[0].def);
  printf("🏃 | Spd: %d\n", slot[0].spd);
  printf("◓  | Pokeballs: %d\n", player.borsa.pokeBalls);
  printf("PosX: %d\nPosY: %d\n", player.posX, player.posY);
  printf("MaxHP: %d\n", slot[0].maxHP);
}