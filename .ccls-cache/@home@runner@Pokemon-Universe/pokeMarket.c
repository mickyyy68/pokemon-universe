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
  printf("Benvenuto nel pokemarket.\n");
  sleep(1);
  while(shopping == 1){
    // Pokemarket della prima città:
    if(cittaAttuale == 0){
      clear;
      printf("Cosa vorresti comprare?\n");
      // Printo lo shop
      red;
      printf("[1]-> Pokeball $%d\n", prezzoPokeball);
      resetcolor;
      
      cyan;
      printf("[2]-> Greatball $%d\n", prezzoGreatball);
      resetcolor;
  
      printf("[e]-> Esci dal pokemarket\n");
      
      printf("-> ");
      // Scelta del giocatore
      scanf(" %c", &sceltaPokeMarket);
  
  
      
      // Processo...
      switch(sceltaPokeMarket){
        
        // Pokeball
        case '1':{
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
  
        case '2':{
          
          break;
        }
  
        case 'e':{
          shopping = 0;
          player.posY--;
          break;
        }
        
        default:{
        }
        
      }
    }
  }
}
