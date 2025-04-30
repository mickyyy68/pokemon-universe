//--------------------------------ATTENZIONE!       ------------------------------------------------------------------------------------//
// Su all.h non posso mettere le variabili, altrimenti da problemi che l'ho inizializzata troppe volte

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#define POKEMONS 25
#define clear system("clear");
    
// COLORI
// Colori
#define red printf("\033[1;31m")
#define yellow printf("\033[1;33m")
#define resetcolor printf("\033[0m")
#define cyan printf("\033[0;36m")
#define green printf("\033[1;32m")
#define blue printf("\033[1;34m")
#define magenta printf("\033[1;35m")
#define bold printf("\e[1m")
#define unbold printf("\e[0m")

// LEVELUP STATISTICHE
#define HP_LEVELUP 10
#define ATK_LEVELUP 5
#define DEF_LEVELUP 5
#define SPD_LEVELUP 5


typedef struct{
  char nome[20];
  int index;
  int maxHP;
  int hp;
  int atk;
  int def;
  int spd; 
  int livello;
  int xp;
  int catchRate;

}t_pokemon;

typedef struct{
  char nome[20];
  int index;
  int maxHP;
  int hp;
  int atk;
  int def;
  int spd; 
  int livello;
  int xp;
  int catchRate;

  int slotPieno;
}t_slot; 


typedef struct{
  char nome[20];
  int index;
  int maxHP;
  int hp;
  int atk;
  int def;
  int spd;
  int xp;
  int livello;
  int catchRate;
}t_pokemonSelvatico;

// t_slot sono i pokemon che ho io, nei rispettivi slot.

struct t_borsa{
  int soldi;
  int pokeBalls;
  int greatBalls;
  int ultraBalls;
};

typedef struct{
  // Per la mappa da disegnare
  int posX;
  int posY;

  // Il resto...

  struct t_borsa borsa;
}t_player;


#define CITTA_RIGHE 10
#define CITTA_COLONNE 15





