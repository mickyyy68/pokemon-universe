
#include "all.h"

extern t_slot slot[7];
extern int i;

void swapPokemons() {
  clear;
  int from = -1, to = -1;
  int exit = 0;

  do {
    // Interfaccia grafica migliorata
    cyan; bold;
    printf("┏━━━━━━━━━━━━━━━━━ SCAMBIO POKÉMON ━━━━━━━━━━━━━━━━━┓\n");
    resetcolor;
    
    // Mostra i Pokémon disponibili
    printf("┃                                                     ┃\n");
    for (i = 0; i < 6; i++) {
      if (slot[i].slotPieno) {
        // Se lo slot è pieno, mostra le informazioni del Pokémon
        if (i == 0) {
          green; bold; // Evidenzia Pokémon attivo
        }
        printf("┃ [%d] %-10s - Lv.%-3d  HP: %3d/%-3d  Attacco: %-3d ┃\n", 
               i, slot[i].nome, slot[i].livello, slot[i].hp, slot[i].maxHP, slot[i].atk);
        resetcolor;
      } else {
        // Se lo slot è vuoto
        printf("┃ [%d] Slot vuoto                                    ┃\n", i);
      }
    }
    printf("┃                                                     ┃\n");
    printf("┃ [9] Torna al gioco                                  ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    
    // Istruzioni chiare
    if (from == -1) {
      printf("\nSeleziona il Pokémon da spostare (0-5): ");
      scanf("%d", &from);
      
      // Controlla input valido
      if (from == 9) {
        exit = 1;
        break;
      }
      
      if (from < 0 || from > 5) {
        red;
        printf("Selezione non valida. Riprova.\n");
        resetcolor;
        sleep(1);
        from = -1;
        clear;
        continue;
      }
      
      // Verifica che lo slot selezionato contenga un Pokémon
      if (!slot[from].slotPieno) {
        red;
        printf("Questo slot è vuoto! Seleziona uno slot con un Pokémon.\n");
        resetcolor;
        sleep(1);
        from = -1;
        clear;
        continue;
      }
      
      printf("Hai selezionato %s (Slot %d)\n", slot[from].nome, from);
      
    } else {
      printf("\nSeleziona lo slot di destinazione (0-5): ");
      scanf("%d", &to);
      
      // Controlla input valido
      if (to == 9) {
        exit = 1;
        break;
      }
      
      if (to < 0 || to > 5) {
        red;
        printf("Selezione non valida. Riprova.\n");
        resetcolor;
        sleep(1);
        to = -1;
        clear;
        continue;
      }
      
      // Controlla se è lo stesso slot
      if (to == from) {
        yellow;
        printf("Hai selezionato lo stesso slot! Operazione annullata.\n");
        resetcolor;
        sleep(1);
        from = -1;
        to = -1;
        clear;
        continue;
      }
      
      // Conferma lo scambio
      printf("Vuoi scambiare %s (Slot %d) con ", slot[from].nome, from);
      if (slot[to].slotPieno) {
        printf("%s (Slot %d)?\n", slot[to].nome, to);
      } else {
        printf("uno slot vuoto (Slot %d)?\n", to);
      }
      
      printf("[1] Sì | [0] No: ");
      int conferma;
      scanf("%d", &conferma);
      
      if (conferma == 1) {
        // Scambia i Pokémon
        t_slot temp = slot[to];
        slot[to] = slot[from];
        slot[from] = temp;
        
        green;
        printf("\nScambio completato con successo!\n");
        resetcolor;
        sleep(1);
      } else {
        yellow;
        printf("\nOperazione annullata.\n");
        resetcolor;
        sleep(1);
      }
      
      // Reset per un nuovo scambio
      from = -1;
      to = -1;
      clear;
    }
  } while (!exit);

  clear;
}
