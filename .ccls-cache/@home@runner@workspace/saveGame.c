
#include "all.h"
#include <sys/stat.h>

extern t_player player;
extern t_slot slot[7];
extern int cittaAttuale;
extern char *pokemonsNames[POKEMONS];

// Funzione per creare un percorso di file
char* getFilePath(const char* fileName) {
  static char filePath[256];
  sprintf(filePath, "%s", fileName);
  return filePath;
}

// Verifica se un file esiste
int fileExists(const char* fileName) {
  struct stat buffer;
  return (stat(fileName, &buffer) == 0);
}

// Salva la partita su file
void saveGame() {
  clear;
  FILE *file;
  char fileName[50];
  char filePath[256];
  
  cyan; bold;
  printf("┏━━━━━━━━━━━━━━━━ SALVATAGGIO PARTITA ━━━━━━━━━━━━━━━━┓\n");
  resetcolor;
  printf("┃                                                     ┃\n");
  printf("┃ Inserisci il nome del salvataggio:                  ┃\n");
  printf("┃                                                     ┃\n");
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
  
  printf("Nome: ");
  scanf("%s", fileName);
  
  sprintf(filePath, "games/%s.json", fileName);
  
  // Crea la directory games se non esiste
  mkdir("games", 0777);
  
  file = fopen(filePath, "w");
  if (file == NULL) {
    red;
    printf("Errore nell'apertura del file per il salvataggio!\n");
    resetcolor;
    sleep(2);
    return;
  }
  
  // Inizio JSON
  fprintf(file, "{\n");
  
  // Salva i dati del giocatore
  fprintf(file, "  \"player\": {\n");
  fprintf(file, "    \"posX\": %d,\n", player.posX);
  fprintf(file, "    \"posY\": %d,\n", player.posY);
  fprintf(file, "    \"borsa\": {\n");
  fprintf(file, "      \"soldi\": %d,\n", player.borsa.soldi);
  fprintf(file, "      \"pokeBalls\": %d,\n", player.borsa.pokeBalls);
  fprintf(file, "      \"greatBalls\": %d,\n", player.borsa.greatBalls);
  fprintf(file, "      \"ultraBalls\": %d\n", player.borsa.ultraBalls);
  fprintf(file, "    }\n");
  fprintf(file, "  },\n");
  
  // Salva la città attuale
  fprintf(file, "  \"cittaAttuale\": %d,\n", cittaAttuale);
  
  // Salva i dati dei Pokémon negli slot
  fprintf(file, "  \"slots\": [\n");
  for (int i = 0; i < 6; i++) {
    fprintf(file, "    {\n");
    fprintf(file, "      \"nome\": \"%s\",\n", slot[i].nome);
    fprintf(file, "      \"index\": %d,\n", slot[i].index);
    fprintf(file, "      \"maxHP\": %d,\n", slot[i].maxHP);
    fprintf(file, "      \"hp\": %d,\n", slot[i].hp);
    fprintf(file, "      \"atk\": %d,\n", slot[i].atk);
    fprintf(file, "      \"def\": %d,\n", slot[i].def);
    fprintf(file, "      \"spd\": %d,\n", slot[i].spd);
    fprintf(file, "      \"livello\": %d,\n", slot[i].livello);
    fprintf(file, "      \"xp\": %d,\n", slot[i].xp);
    fprintf(file, "      \"catchRate\": %d,\n", slot[i].catchRate);
    fprintf(file, "      \"slotPieno\": %d\n", slot[i].slotPieno);
    if (i < 5) {
      fprintf(file, "    },\n");
    } else {
      fprintf(file, "    }\n");
    }
  }
  fprintf(file, "  ]\n");
  
  // Fine JSON
  fprintf(file, "}\n");
  
  fclose(file);
  
  green;
  printf("\nPartita salvata con successo come '%s'!\n", fileName);
  resetcolor;
  sleep(2);
  clear;
}

// Carica una partita precedentemente salvata
int loadGame(const char* fileName) {
  FILE *file;
  char buffer[1024];
  int i = 0;
  char filePath[256];
  
  sprintf(filePath, "games/%s.json", fileName);
  
  file = fopen(filePath, "r");
  if (file == NULL) {
    red;
    printf("Errore nell'apertura del file '%s'!\n", fileName);
    resetcolor;
    sleep(2);
    return 0;
  }
  
  // Leggi il file manualmente, poiché non abbiamo una libreria JSON
  // Questo è un parser molto semplificato che cerca i valori specifici
  
  while (fgets(buffer, sizeof(buffer), file)) {
    // Leggi i dati del giocatore
    if (strstr(buffer, "\"posX\":")) {
      sscanf(buffer, "    \"posX\": %d,", &player.posX);
    }
    else if (strstr(buffer, "\"posY\":")) {
      sscanf(buffer, "    \"posY\": %d,", &player.posY);
    }
    else if (strstr(buffer, "\"soldi\":")) {
      sscanf(buffer, "      \"soldi\": %d,", &player.borsa.soldi);
    }
    else if (strstr(buffer, "\"pokeBalls\":")) {
      sscanf(buffer, "      \"pokeBalls\": %d,", &player.borsa.pokeBalls);
    }
    else if (strstr(buffer, "\"greatBalls\":")) {
      sscanf(buffer, "      \"greatBalls\": %d,", &player.borsa.greatBalls);
    }
    else if (strstr(buffer, "\"ultraBalls\":")) {
      sscanf(buffer, "      \"ultraBalls\": %d", &player.borsa.ultraBalls);
    }
    // Leggi la città attuale
    else if (strstr(buffer, "\"cittaAttuale\":")) {
      sscanf(buffer, "  \"cittaAttuale\": %d,", &cittaAttuale);
    }
    // Leggi i dati dei Pokémon
    else if (strstr(buffer, "\"nome\":") && i < 6) {
      char tempNome[20];
      sscanf(buffer, "      \"nome\": \"%[^\"]", tempNome);
      strcpy(slot[i].nome, tempNome);
    }
    else if (strstr(buffer, "\"index\":") && i < 6) {
      sscanf(buffer, "      \"index\": %d,", &slot[i].index);
    }
    else if (strstr(buffer, "\"maxHP\":") && i < 6) {
      sscanf(buffer, "      \"maxHP\": %d,", &slot[i].maxHP);
    }
    else if (strstr(buffer, "\"hp\":") && i < 6) {
      sscanf(buffer, "      \"hp\": %d,", &slot[i].hp);
    }
    else if (strstr(buffer, "\"atk\":") && i < 6) {
      sscanf(buffer, "      \"atk\": %d,", &slot[i].atk);
    }
    else if (strstr(buffer, "\"def\":") && i < 6) {
      sscanf(buffer, "      \"def\": %d,", &slot[i].def);
    }
    else if (strstr(buffer, "\"spd\":") && i < 6) {
      sscanf(buffer, "      \"spd\": %d,", &slot[i].spd);
    }
    else if (strstr(buffer, "\"livello\":") && i < 6) {
      sscanf(buffer, "      \"livello\": %d,", &slot[i].livello);
    }
    else if (strstr(buffer, "\"xp\":") && i < 6) {
      sscanf(buffer, "      \"xp\": %d,", &slot[i].xp);
    }
    else if (strstr(buffer, "\"catchRate\":") && i < 6) {
      sscanf(buffer, "      \"catchRate\": %d,", &slot[i].catchRate);
    }
    else if (strstr(buffer, "\"slotPieno\":") && i < 6) {
      sscanf(buffer, "      \"slotPieno\": %d", &slot[i].slotPieno);
      i++; // Incrementa il contatore degli slot dopo aver letto l'ultimo campo
    }
  }
  
  fclose(file);
  return 1;
}

// Mostra i salvataggi disponibili e permette di caricarne uno
int showSaves() {
  clear;
  FILE *pipe;
  char buffer[1024];
  char command[256];
  int saveCount = 0;
  char saves[20][50]; // Massimo 20 salvataggi, con nomi lunghi fino a 50 caratteri
  
  // Crea la directory games se non esiste
  mkdir("games", 0777);
  
  // Lista tutti i file JSON nella cartella games
  sprintf(command, "ls -1 games/*.json 2>/dev/null | sed 's|games/||g' | sed 's|.json||g'");
  pipe = popen(command, "r");
  if (pipe == NULL) {
    red;
    printf("Errore nell'esecuzione del comando!\n");
    resetcolor;
    sleep(2);
    return 0;
  }
  
  cyan; bold;
  printf("┏━━━━━━━━━━━━━━━━ CARICA PARTITA ━━━━━━━━━━━━━━━━┓\n");
  resetcolor;
  printf("┃                                                 ┃\n");
  
  // Leggi i nomi dei file di salvataggio
  while (fgets(buffer, sizeof(buffer), pipe)) {
    // Rimuovi il newline
    buffer[strcspn(buffer, "\n")] = '\0';
    
    if (strlen(buffer) > 0) {
      strcpy(saves[saveCount], buffer);
      printf("┃ [%d] %-40s ┃\n", saveCount + 1, buffer);
      saveCount++;
    }
  }
  
  pclose(pipe);
  
  if (saveCount == 0) {
    printf("┃ Nessun salvataggio disponibile                  ┃\n");
  }
  
  printf("┃                                                 ┃\n");
  printf("┃ [0] Torna al menu principale                    ┃\n");
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
  
  int choice;
  printf("\nSeleziona un salvataggio: ");
  scanf("%d", &choice);
  
  if (choice == 0) {
    clear;
    return 0;
  }
  
  if (choice < 1 || choice > saveCount) {
    red;
    printf("\nScelta non valida!\n");
    resetcolor;
    sleep(2);
    return 0;
  }
  
  // Carica il salvataggio selezionato
  if (loadGame(saves[choice - 1])) {
    green;
    printf("\nPartita '%s' caricata con successo!\n", saves[choice - 1]);
    resetcolor;
    sleep(2);
    return 1;
  }
  
  return 0;
}
