#include "cortesia.h"

void hola(int opc) {
  if(opc == 1) {
    printf("Hola!!!\n");
    numSaludos++;
  }
  else if(opc == 2) {
    printf("Hi!!!\n");
    numSaludos++;
  }
  else {
    printf("ERROR: Opcion invalida!!!\n");
  }
}

void adios1(void) {
  printf("Adios!!!\n");
  numDespedidas++;
}

void adios2(void) {
  printf("Bye!!!\n");
  numDespedidas++;
}

void adios3(void) {
  printf("Ciao!!!\n");
  numDespedidas++;
}

void imprimirNumeroSaludos(void) {
  printf("Numero de saludos hasta el momento: %d\n", numSaludos);
}


void imprimirNumeroDespedidas(void) {
  printf("Numero de despedidas hasta el momento: %d\n", numDespedidas);
}
