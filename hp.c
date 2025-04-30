#include "all.h"
extern int i, x;


int writeHP(int hp, int maxHP){
  // Scrivi i cosi verdi solo se ha più di 0 di hp
  if(hp > 0){
    int vitaVerdeCounter = 0;
    int vitaArancioneCounter = 0;
    int  vitaRossaCounter = 0;
    int vitaVerde = 0;
    int vitaArancione = 0;
    int vitaRossa = 0;
       // Per ogni 10% di hp metto un pallino, fino al max di 10 pallini 
    for(i = 10; i <= 100; i += 10){ 
      float vita = (maxHP * i) / 100;
      if(vita <= hp && i > 50){
          vitaVerdeCounter++;
          vitaVerde = 1;
        }
      else if(vita <= hp && i <= 50 && i >= 30){
        vitaArancioneCounter++;
        vitaArancione = 1;
      }
      else if(vita <= hp && i <= 30 && i > 0){
        vitaRossaCounter++;
        vitaRossa = 1;
      }
    }
    if(vitaVerde == 1){
      for(i = vitaVerdeCounter; i > 0; i--)
        printf("🟢");
      for(i = vitaArancioneCounter; i > 0; i--)
        printf("🟢");
      for(i = vitaRossaCounter; i > 0; i--)
        printf("🟢");
    }
    else if(vitaArancione == 1){
      for(i = vitaVerdeCounter; i > 0; i--)
        printf("🟠");
      for(i = vitaArancioneCounter; i > 0; i--)
        printf("🟠");
      for(i = vitaRossaCounter; i > 0; i--)
        printf("🟠");
    }
    else if(vitaRossa == 1){
      for(i = vitaVerdeCounter; i > 0; i--)
        printf("🔴");
      for(i = vitaArancioneCounter; i > 0; i--)
        printf("🔴");
      for(i = vitaRossaCounter; i > 0; i--)
        printf("🔴");
    }
    else if(vitaRossaCounter == 0)
        printf("🔴");
    printf(" | %d\n", hp);
  }
}