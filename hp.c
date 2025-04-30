#include "all.h"

extern int i;

void writeHP(int hp, int maxHP){
  // Calcola la percentuale di salute
  float percentuale = (float)hp / maxHP * 100;

  // Massimo 10 pallini per la barra HP
  const int MAX_PALLINI = 10;

  // Calcola quanti pallini mostrare (massimo MAX_PALLINI)
  int palliniDaMostrare = (int)(percentuale / 10);
  if (palliniDaMostrare > MAX_PALLINI) palliniDaMostrare = MAX_PALLINI;

  // Determina il colore in base alla percentuale di salute
  if(hp <= 0){
    // Assuming red and resetcolor are defined elsewhere, likely in all.h
    red;
    printf("ESAUSTO!");
    resetcolor;
    return 0;
  }

  // Colori diversi in base alla percentuale di salute
  if(percentuale > 50){
    // Verde per salute > 50%
    for(i = 0; i < palliniDaMostrare; i++)
      printf("🟢");
  }
  else if(percentuale > 20){
    // Arancione per salute tra 20% e 50%
    for(i = 0; i < palliniDaMostrare; i++)
      printf("🟠");
  }
  else {
    // Rosso per salute <= 20%
    for(i = 0; i < palliniDaMostrare; i++)
      printf("🔴");
  }

  // Aggiungi la percentuale numerica accanto alla barra
  printf(" %d/%d HP", hp, maxHP);

  return;
}

// This function is commented out to avoid duplicate definition
/*
// Stampa una barra di HP colorata
void writeHP(int hp, int maxHP) {
  // Calcola la percentuale di HP rimanente
  float percentage = (float)hp / maxHP;
  
  // Scegli il colore in base alla percentuale
  if (percentage > 0.5) {
    green; // Verde per HP > 50%
  } else if (percentage > 0.2) {
    yellow; // Giallo per HP tra 20% e 50%
  } else {
    red; // Rosso per HP < 20%
  }
  
  // Stampa gli HP come testo
  printf("HP: %3d/%-3d ", hp, maxHP);
  
  // Stampa la barra grafica
  int barLength = 10;
  int filledLength = (int)(percentage * barLength);
  
  printf("[");
  for (int i = 0; i < barLength; i++) {
    if (i < filledLength) {
      printf("■");
    } else {
      printf("□");
    }
  }
  printf("]");
  
  resetcolor;
}
*/
