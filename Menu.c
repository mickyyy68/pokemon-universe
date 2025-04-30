#include "all.h"

extern t_player player;
extern int disegnoCitta[2][CITTA_RIGHE][CITTA_COLONNE];
extern int cittaAttuale;
extern int i;
extern t_slot slot[7];
extern int writeHP();
extern t_player player;

extern void swapSlotToSlot();

//--------------------------------PRINTO IL MENU
//-------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------//
void printMenu() {
  printf("\n");

  // Controlli di gioco in un box
  printf("┏━━━━━━━━━━━ CONTROLLI ━━━━━━━━━━━┓\n");
  printf("┃ Movimento: [W]↑ [A]← [S]↓ [D]→  ┃\n");
  printf("┃ Interagisci: [E] su 🏥/🏪       ┃\n");
  printf("┃ Scambia Pokémon: [P]            ┃\n");
  printf("┃ Durante battaglia: 1-4 per azioni┃\n");
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

  // Box con info Pokémon attivo
  printf("\n┏━━━━━━━━━━ POKÉMON ATTIVO ━━━━━━━━━━┓\n");

  // Nome Pokémon con colore
  bold;
  red;
  printf("┃ %s", slot[0].nome);
  // Aggiungo spazi per allineare la box
  int spazi = 35 - strlen(slot[0].nome);
  for (int i = 0; i < spazi; i++)
    printf(" ");
  printf("┃\n");
  resetcolor;

  // Stato HP
  printf("┃ ");
  if (slot[0].hp > 0) {
    writeHP(slot[0].hp, slot[0].maxHP);
    // Calcolo gli spazi rimanenti e li aggiungo
    int hpLength = 15; // Lunghezza media della barra HP con testo
    int hpSpaces = 35 - hpLength;
    for (int i = 0; i < hpSpaces; i++)
      printf(" ");
  } else {
    red;
    printf("Pokemon esausto! Vai all'ospedale");
    resetcolor;
  }
  printf(" ┃\n");

  // Box statistiche a due colonne
  printf("┣━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━┫\n");
  printf("┃ 🔷 Livello: %-3d   ┃ 🧿 XP: %-9d  ┃\n", slot[0].livello, slot[0].xp);
  printf("┃ 🔫 Attacco: %-3d   ┃ 🛡️  Difesa: %-3d   ┃\n", slot[0].atk, slot[0].def);
  printf("┃ 🏃 Velocità: %-3d  ┃ ❤️  Max HP: %-3d   ┃\n", slot[0].spd, slot[0].maxHP);
  printf("┗━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┛\n");

  // Inventario e posizione
  printf("\n┏━━━━━━━━━━━ INVENTARIO ━━━━━━━━━━━┓\n");
  printf("┃ 🔴 Pokeball: %-3d                 ┃\n", player.borsa.pokeBalls);
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

  // Posizione attuale
  printf("\n📍 Posizione: X=%d, Y=%d (Città: %d)\n", player.posX, player.posY, cittaAttuale);
}