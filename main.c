#include "all.h"


/*
1 - Aggiungere la possibilità di cattura pokemon
2 - Aggiungere la possibilità di scambiare pokemon tra slots
3 - Possibilità di comprare le pokeballs e magari pozioni e cose che ti fanno guadagnare più xp

*/


//--------------------------------GIOCATORE EMOJI        ------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------//
char playerEmoji[8] = "🧍"; // 4 perchè altrimenti non va(penso siano i bit)


//--------------------------------VARIABILI              ------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------//
// nomi pokemon
char *pokemonsNames[POKEMONS] = {
  // Originali
  "Pikachu", "Rattata", "Arch", "Void", "Arcanine",
  // Nuovi Pokémon
  "Bulbasaur", "Charmander", "Squirtle", "Jigglypuff", "Meowth",
  "Growlithe", "Machop", "Gastly", "Onix", "Hitmonlee",
  "Lickitung", "Chansey", "Tangela", "Kangaskhan", "Scyther",
  "Electabuzz", "Magmar", "Gyarados", "Lapras", "Eevee"
};
// cicli
int i, x, y;
// citta attuale, dove è il giocatore(mappa)
int cittaAttuale;
// Se sta giocando o no, quidni se non inserisce e
int playing = 1;
// Scelta del giocatore dove vuole muoversi
char movementChoice;

int fighting;
//--------------------------------TYPE DEF STRUCTS       ------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------//
t_pokemon pokemon[POKEMONS];
t_player player;
t_slot slot[6];
t_pokemonSelvatico pokemonSelvatico;

//--------------------------------FUNZIONI ALTRI FILE    ------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------------------------------------------//
extern void printCitta();
extern void inizializeStatsPokemon();
extern void askFirstPokemon();
extern void printMenu();
extern void selectMovement();

//--------------------------------per fare l'input senza cliccare enter ----------------------------------------------------------------//
// La funzione getch() serve.
// char = getch();
// https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
static struct termios old, current;
/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}
/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}
/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}




int main() {
  srand(time(NULL));
  //------------------------------------//
  // Da quale citta parte il giocatore
  cittaAttuale = 0;
  player.posX = 1;
  player.posY = 0;
  //------------------------------------//
  // Inizializzo i pokemon, dandogli manualmente le stats, e i nomi tramite un array.
  inizializeStatsPokemon();
  //------------------------------------//
  // Chiedo all'utente il suo primo pokemon
  askFirstPokemon();
  //------------------------------------//  
  // Il ciclo continua finchè playing è true
  while(playing){
    //------------------------------------//
    // Printo la citta, ma senza funzioni...
    printCitta();
    // Printo il menu
    printMenu();
    
    // Qui è quando l'utente mette input dove vuole muoversi. Qui calcolo le tile dove l'utente sta 
    movementChoice = getch();
    selectMovement(movementChoice);
  }//while playing
  return 0;
}