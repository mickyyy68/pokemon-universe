#include "all.h"

extern int cittaAttuale;
extern int copyStatsToPokemonSelvatico();
extern int copyStatsFromToSlot();
extern int writeHP();
extern t_pokemonSelvatico pokemonSelvatico;
extern t_slot slot[7];
extern int i, x;
extern t_player player;

// xp del pokemon selvatico(xp che ti da lui)
int xpGained;
int livelloPokemonSelvatico;
char pokeBattleChoice;
extern int fighting;

extern void catchPokemon();



void pokeBattle(){

  // OGNI CITTA I PROPRI POKEMON E I PROPRI LIVELLI!!!!!
  if(cittaAttuale == 0){
    livelloPokemonSelvatico = (rand() % 5) + 1;
    pokemonSelvatico.index = (rand() % POKEMONS);
  }
  else if(cittaAttuale == 1){
    livelloPokemonSelvatico = (rand() % 15) + 1;
    pokemonSelvatico.index = (rand() % POKEMONS);
  }
  else if(cittaAttuale == 2){
    livelloPokemonSelvatico = (rand() % 20) + 10;
    pokemonSelvatico.index = (rand() % POKEMONS);
  }
  else if(cittaAttuale == 3){
    livelloPokemonSelvatico = (rand() % 20) + 15;
    pokemonSelvatico.index = (rand() % POKEMONS);
  }
  else if(cittaAttuale == 4){
    livelloPokemonSelvatico = (rand() % 20) + 20;
    pokemonSelvatico.index = (rand() % POKEMONS);
  }
  else if(cittaAttuale == 5){
    livelloPokemonSelvatico = (rand() % 20) + 25;
    pokemonSelvatico.index = (rand() % POKEMONS);
  }
  else if(cittaAttuale == 6){
    livelloPokemonSelvatico = (rand() % 20) + 30;
    pokemonSelvatico.index = (rand() % POKEMONS);
  }
  clear;


  // Do le stats al pokemon selvatico
  copyStatsToPokemonSelvatico(pokemonSelvatico.index, livelloPokemonSelvatico);
  // xp che andrà a guadagnare il pokemon
  xpGained = ((pokemonSelvatico.livello * pokemonSelvatico.xp) / 7);

  fighting = 1;
  int won = 0;
  printf("Hai trovato un %s selvatico!\n", pokemonSelvatico.nome);


  do{
    // PRINTO LE STATISTICHE DEL POKEMON IN BATTAGLIA
    printf("%s - %d\n", slot[0].nome, slot[0].livello);
    writeHP(slot[0].hp, slot[0].maxHP);
    // PRINTO LE STATISTICHE DEL POKEMON SELVATICO
    printf("\n\n%s - %d - %d\n", pokemonSelvatico.nome, pokemonSelvatico.livello, xpGained);
    writeHP(pokemonSelvatico.hp, pokemonSelvatico.maxHP);
    printf("Atk: %d\nDef: %d\nSpd: %d\n",pokemonSelvatico.atk, pokemonSelvatico.def, pokemonSelvatico.spd);

    // CHIEDO ALL'UTENTE COSA VUOLE FARE
    printf("[1] -> Attacca  [2] -> Borsa\n[3] -> Boh      [4] -> Fuga\n\n-> ");
    scanf(" %c", &pokeBattleChoice);
    switch(pokeBattleChoice){
      case '1':
        clear;
        // Chi è piu veloce attacca per primo

        // se il tuo pokemon è più veloce
        if(slot[0].spd >= pokemonSelvatico.spd){
          red;
          printf("Hai fatto %d danni\n", slot[0].atk);
          pokemonSelvatico.hp -= slot[0].atk;
          resetcolor;
          // Fight
          if(pokemonSelvatico.hp > 0){
            cyan;
            printf("Ti ha tolto %d di vita.\n", pokemonSelvatico.atk);
            resetcolor;
            slot[0].hp -= pokemonSelvatico.atk;
          }
        }
        // se il pokemon selvatico è piu veloce...
        else if(slot[0].spd < pokemonSelvatico.spd){
          cyan;
          printf("Ti ha tolto %d di vita.\n", pokemonSelvatico.atk);
          slot[0].hp -= pokemonSelvatico.atk;
          resetcolor;
          if(slot[0].hp > 0){
            red;
            printf("Hai fatto %d danni\n", slot[0].atk);
            resetcolor;
            pokemonSelvatico.hp -= slot[0].atk;
          }
        }
        // Hai vinto il fight
        if(pokemonSelvatico.hp <= 0){
          clear;
          printf("Hai sconfitto il pokemon!\n");
          fighting = 0;
          won = 1;
        }
        // Hai perso il fight
        else if(slot[0].hp <= 0){
          clear;
          red;
          printf("Il pokemon ti ha sconfitto!\n");
          resetcolor;
          sleep(1);
          fighting = 0;
        }
        break;




      
      // BORSAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
      case '2':
          // catch
          catchPokemon();
        break;





      
      
      // FUGA
      case '4':
        clear;
        fighting = 0;
        red;
        printf("Sei riuscito a scappare...\n");
        resetcolor;
        break;

      default:
        clear;
        break;
    }
  }while(fighting);
    
  if(won == 1){
    slot[0].xp += xpGained*1.5; // xpGained è un'altra formula presa, che calcolo sopra(xpGained dal pokemon)
  }

  
  for(i = 1; i <= 100; i++){
    ///////////////////////////////////////////////////////////////////
    // CHECK SE DEVO SALIRE DI LIVELLO!!!!!!!!!
    // la formula 5 * i...  è una formula presa dal sito: 
    // https://bulbapedia.bulbagarden.net/wiki/Experience#:~:text=In%20the%20core%20series%20games,level%2C%20as%20well%20as%20species.
    // ho preso la formula slow.
    // i = livello qui(n nella formula)
    // x lo uso solo se tipo l'utente sale magari 2 volte di livello in 1 sola botta
    for(x = 0; x <= 100; x++){
      if(slot[0].xp >= ((5 * (i * i * i)) / 4) && slot[0].livello == i){
          slot[0].livello = i+1;
          printf("\nSei salito di livello!");
          copyStatsFromToSlot(slot[0].index, slot[0].livello, 0);
          printf("\nSei salito al livello: %d - %d\n", slot[0].livello, 5 * (i * i * i) / 4);
          sleep(1);
      }
    }
  }
  sleep(1);
}