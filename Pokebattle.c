#include "all.h"

extern int cittaAttuale;
extern int copyStatsToPokemonSelvatico();
extern int copyStatsFromToSlot();
extern void writeHP();
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

void pokeBattle() {

  // OGNI CITTA I PROPRI POKEMON E I PROPRI LIVELLI!!!!!
  if (cittaAttuale == 0) {
    // Napoli - Pokémon base (Livelli 1-5)
    livelloPokemonSelvatico = (rand() % 5) + 1;
    int pokemonPossibili[] = {0, 1, 2, 3, 4};
    pokemonSelvatico.index = pokemonPossibili[rand() % 5];
  } else if (cittaAttuale == 1) {
    // Arcipelago - Pokémon di tipo acqua e alcuni base (Livelli 5-15)
    livelloPokemonSelvatico = (rand() % 11) + 5;
    int pokemonPossibili[] = {
        1, 7, 9, 22, 23}; // Rattata, Squirtle, Meowth, Gyarados, Lapras
    pokemonSelvatico.index = pokemonPossibili[rand() % 5];
  } else if (cittaAttuale == 2) {
    // Montagna - Pokémon di tipo roccia/lotta (Livelli 10-25)
    livelloPokemonSelvatico = (rand() % 16) + 10;
    int pokemonPossibili[] = {11, 13, 14, 18,
                              24}; // Machop, Onix, Hitmonlee, Kangaskhan, Eevee
    pokemonSelvatico.index = pokemonPossibili[rand() % 5];
  } else if (cittaAttuale == 3) {
    // Foresta - Pokémon di tipo erba/insetto (Livelli 15-30)
    livelloPokemonSelvatico = (rand() % 16) + 15;
    int pokemonPossibili[] = {
        5, 8, 17, 19, 24}; // Bulbasaur, Jigglypuff, Tangela, Scyther, Eevee
    pokemonSelvatico.index = pokemonPossibili[rand() % 5];
  } else if (cittaAttuale == 4) {
    // Deserto - Pokémon di tipo normale/terra (Livelli 20-35)
    livelloPokemonSelvatico = (rand() % 16) + 20;
    int pokemonPossibili[] = {
        9, 15, 16, 18, 19}; // Meowth, Lickitung, Chansey, Kangaskhan, Scyther
    pokemonSelvatico.index = pokemonPossibili[rand() % 5];
  } else if (cittaAttuale == 5) {
    // Vulcano - Pokémon di tipo fuoco/elettro (Livelli 25-40)
    livelloPokemonSelvatico = (rand() % 16) + 25;
    int pokemonPossibili[] = {
        4, 6, 10, 20,
        21}; // Arcanine, Charmander, Growlithe, Electabuzz, Magmar
    pokemonSelvatico.index = pokemonPossibili[rand() % 5];
  } else if (cittaAttuale == 6) {
    // Grotta - Pokémon rari e spettro (Livelli 30-45)
    livelloPokemonSelvatico = (rand() % 16) + 30;
    int pokemonPossibili[] = {
        12, 14, 20, 22, 23}; // Gastly, Hitmonlee, Electabuzz, Gyarados, Lapras
    pokemonSelvatico.index = pokemonPossibili[rand() % 5];
  }
  clear;

  fighting = 1;

  if (fighting)
    // Do le stats al pokemon selvatico
    copyStatsToPokemonSelvatico(pokemonSelvatico.index,
                                livelloPokemonSelvatico);

  // xp che andrà a guadagnare il pokemon
  xpGained = ((pokemonSelvatico.livello * pokemonSelvatico.xp) / 7);

  int won = 0;
  printf("Hai trovato un %s selvatico!\n", pokemonSelvatico.nome);

  // Aggiorna il Pokedex quando vedi un pokemon
  extern void updatePokedex(int indexPokemon, int catturato);
  updatePokedex(pokemonSelvatico.index, 0);

  do {
    // PRINTO LE STATISTICHE DEL POKEMON IN BATTAGLIA
    printf("┏━━━━━━━━━━ IL TUO POKÉMON ━━━━━━━━━━┓\n");
    bold;
    printf("┃ %s - Livello %d", slot[0].nome, slot[0].livello);
    int spazi = 35 - strlen(slot[0].nome) - 11;
    for (int i = 0; i < spazi; i++)
      printf(" ");
    printf("┃\n");
    resetcolor;
    printf("┃ ");
    writeHP(slot[0].hp, slot[0].maxHP);
    printf(" ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    printf("Id pokemon%d", pokemonSelvatico.index);
    // PRINTO LE STATISTICHE DEL POKEMON SELVATICO
    printf("\n┏━━━━━━━━━ POKÉMON SELVATICO ━━━━━━━━━┓\n");
    cyan;
    bold;
    printf("┃ %s - Livello %d", pokemonSelvatico.nome,
           pokemonSelvatico.livello);
    spazi = 35 - strlen(pokemonSelvatico.nome) - 11;
    for (int i = 0; i < spazi; i++)
      printf(" ");
    printf("┃\n");
    resetcolor;
    printf("┃ ");
    writeHP(pokemonSelvatico.hp, pokemonSelvatico.maxHP);
    printf(" ┃\n");
    printf("┃ 🔫 Atk: %-3d | 🛡️ Def: %-3d | 🏃 Spd: %-3d ┃\
           n ",
           pokemonSelvatico.atk, pokemonSelvatico.def, pokemonSelvatico.spd);
    printf("┃ 🧿 XP da guadagnare: %-3d              ┃\n", xpGained);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    // CHIEDO ALL'UTENTE COSA VUOLE FARE
    printf("┏━━━━━━━━━━━━ AZIONI ━━━━━━━━━━━━┓\n");
    printf("┃ [1] 🔫 Attacca    [2] 🎒 Borsa  ┃\n");
    printf("┃ [3] 💬 Parla      [4] 🏃 Fuga   ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n-> ");
    scanf(" %c", &pokeBattleChoice);
    switch (pokeBattleChoice) {
    case '1':
      clear;
      // Chi è piu veloce attacca per primo

      // se il tuo pokemon è più veloce
      if (slot[0].spd >= pokemonSelvatico.spd) {
        red;
        printf("Hai fatto %d danni\n", slot[0].atk);
        pokemonSelvatico.hp -= slot[0].atk;
        resetcolor;
        // Fight
        if (pokemonSelvatico.hp > 0) {
          cyan;
          printf("Ti ha tolto %d di vita.\n", pokemonSelvatico.atk);
          resetcolor;
          slot[0].hp -= pokemonSelvatico.atk;
        }
      }
      // se il pokemon selvatico è piu veloce...
      else if (slot[0].spd < pokemonSelvatico.spd) {
        cyan;
        printf("Ti ha tolto %d di vita.\n", pokemonSelvatico.atk);
        slot[0].hp -= pokemonSelvatico.atk;
        resetcolor;
        if (slot[0].hp > 0) {
          red;
          printf("Hai fatto %d danni\n", slot[0].atk);
          resetcolor;
          pokemonSelvatico.hp -= slot[0].atk;
        }
      }
      // Hai vinto il fight
      if (pokemonSelvatico.hp <= 0) {
        clear;
        printf("Hai sconfitto il pokemon!\n");
        fighting = 0;
        won = 1;
      }
      // Hai perso il fight
      else if (slot[0].hp <= 0) {
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
  } while (fighting);

  if (won == 1) {
    slot[0].xp += xpGained * 1.5; // xpGained è un'altra formula presa, che
                                  // calcolo sopra(xpGained dal pokemon)
  }

  for (i = 1; i <= 100; i++) {
    ///////////////////////////////////////////////////////////////////
    // CHECK SE DEVO SALIRE DI LIVELLO!!!!!!!!!
    // la formula 5 * i...  è una formula presa dal sito:
    // https://bulbapedia.bulbagarden.net/wiki/Experience#:~:text=In%20the%20core%20series%20games,level%2C%20as%20well%20as%20species.
    // ho preso la formula slow.
    // i = livello qui(n nella formula)
    // x lo uso solo se tipo l'utente sale magari 2 volte di livello in 1 sola
    // botta
    for (x = 0; x <= 100; x++) {
      if (slot[0].xp >= ((5 * (i * i * i)) / 4) && slot[0].livello == i) {
        slot[0].livello = i + 1;
        printf("\nSei salito di livello!");
        copyStatsFromToSlot(slot[0].index, slot[0].livello, 0);
        printf("\nSei salito al livello: %d - %d\n", slot[0].livello,
               5 * (i * i * i) / 4);
        sleep(1);
      }
    }
  }
  sleep(1);
}