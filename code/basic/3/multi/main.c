#include <stdio.h>
#include "cortesia.h"

/* Ejemplo donde se emplean variables globales */
int numSaludos = 0;
int numDespedidas = 0;

int main() {
  imprimirNumeroSaludos();
  imprimirNumeroDespedidas();
  printf("\n");
  printf("Saludos: \n");
  hola(1);
  hola(2);
  hola(3);
  printf("\n");
  imprimirNumeroSaludos();
  imprimirNumeroDespedidas();
  printf("\n");
  printf("\nDespedidas: \n");
  adios1();
  adios2();
  adios3();
  printf("\n");
  imprimirNumeroSaludos();
  imprimirNumeroDespedidas();
  printf("\n");
  return 0;
}
