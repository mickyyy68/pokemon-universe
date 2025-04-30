#include "all.h"

extern int i;

int writeHP(int hp, int maxHP){
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

  return 0;
}