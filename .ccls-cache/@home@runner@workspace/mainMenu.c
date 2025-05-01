
#include "all.h"

extern t_player player;
extern int cittaAttuale;
extern t_slot slot[7];
extern int i;
extern void inizializeStatsPokemon();
extern void askFirstPokemon();
extern int showSaves();

// Menu principale del gioco
int mainMenu() {
  int choice = 0;

  while (1) {
    clear;

    // Stampa il titolo del gioco
    magenta;
    bold;
    printf("\n");
    printf(
        "  ██████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ ██████╗ ███╗   ██╗\n");
    printf(
        "  ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔═══██╗████╗  ██║\n");
    printf(
        "  ██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║\n");
    printf(
        "  ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║\n");
    printf(
        "  ██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║\n");
    printf(
        "  ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝\n");
    printf(
        "  ██╗   ██╗███╗   ██╗██╗██╗   ██╗███████╗██████╗ ███████╗███████╗\n");
    printf(
        "  ██║   ██║████╗  ██║██║██║   ██║██╔════╝██╔══██╗██╔════╝██╔════╝\n");
    printf(
        "  ██║   ██║██╔██╗ ██║██║██║   ██║█████╗  ██████╔╝███████╗█████╗  \n");
    printf(
        "  ██║   ██║██║╚██╗██║██║╚██╗ ██╔╝██╔══╝  ██╔══██╗╚════██║██╔══╝  \n");
    printf(
        "  ╚██████╔╝██║ ╚████║██║ ╚████╔╝ ███████╗██║  ██║███████║███████╗\n");
    printf(
        "   ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝\n");
    resetcolor;

    // Stampa il nome dell'autore
    printf("\n                       di Michael Aristarco\n\n");

    // Menu opzioni
    cyan;
    bold;
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    resetcolor;
    printf("┃                                                     ┃\n");
    printf("┃  [1] Nuova partita                                  ┃\n");
    printf("┃  [2] Carica partita                                 ┃\n");
    printf("┃  [0] Esci dal gioco                                 ┃\n");
    printf("┃                                                     ┃\n");
    cyan;
    bold;
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    resetcolor;

    printf("\nInserisci la tua scelta: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      // Nuova partita
      clear;
      // Inizializza i valori di gioco
      cittaAttuale = 0;
      player.posX = 1;
      player.posY = 0;
      player.borsa.soldi = 1000;
      player.borsa.pokeBalls = 5;
      player.borsa.greatBalls = 0;
      player.borsa.ultraBalls = 0;

      // Inizializza i pokemon
      inizializeStatsPokemon();

      // Chiedi all'utente il primo pokemon
      askFirstPokemon();
      return 1;

    case 2:
      // Carica partita
      if (showSaves()) {
        inizializeStatsPokemon();
        return 1;
      }
      break;

    case 0:
      // Esci dal gioco
      printf("\nGrazie per aver giocato a Pokemon Universe!\n");
      sleep(2);
      clear;
      return 0;

    default:
      red;
      printf("\nScelta non valida! Riprova.\n");
      resetcolor;
      sleep(1);
    }
  }

  return 0;
}
