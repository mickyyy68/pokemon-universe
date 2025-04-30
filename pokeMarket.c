#include "all.h"

extern int cittaAttuale;
extern t_pokemonSelvatico pokemonSelvatico;
extern t_slot slot[7];
extern int i, x;
extern t_player player;

int prezzoPokeball = 100;
int prezzoGreatball = 250;
int quantitaShop;
int costoTotale;
int shopping;

char sceltaPokeMarket;

void pokeMarket(){
  clear;
  shopping = 1;
  do{
    clear;
    green; bold;
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃       BENVENUTO AL POKEMARKET       ┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    resetcolor;
    printf("┃ Soldi disponibili: $%-16d ┃\n", player.borsa.soldi);
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃ ARTICOLI DISPONIBILI:              ┃\n");
    printf("┃                                    ┃\n");
    printf("┃ [A] 🔴 Pokeball ($%-3d) - Hai: %-3d    ┃\n", prezzoPokeball, player.borsa.pokeBalls);
    printf("┃ [B] 🔵 Greatball ($%-3d) - Non in stock┃\n", prezzoGreatball);
    printf("┃                                    ┃\n");
    printf("┃ [Q] ❌ Esci dal negozio              ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    printf("-> ");
    // Scelta del giocatore
    scanf(" %c", &sceltaPokeMarket);



    // Processo...
    switch(toupper(sceltaPokeMarket)){ //toupper added for case insensitivity

      // Pokeball
      case 'A':{
        clear;
        printf("Quante ne vorresti comprare?\n-> ");
        scanf("%d", &quantitaShop);
        costoTotale = prezzoPokeball * quantitaShop;
        if(costoTotale > player.borsa.soldi)
            printf("Non hai abbastanza soldi...\n");
        else{
          player.borsa.soldi -= costoTotale;
          player.borsa.pokeBalls += quantitaShop;
          printf("Hai comprato %d pokeball!\n", quantitaShop);
        }
        break;
      }//pokeball

      case 'B':{
        printf("Greatball non disponibili al momento.\n");
        break;
      }

      case 'Q':{
        shopping = 0;
        //player.posY--;  Removed as it's unclear from context where this should apply
        break;
      }

      default:{
        printf("Scelta non valida.\n");
      }

    }
  }while(shopping == 1);
}