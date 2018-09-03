#include <stdio.h>

void hola(int opc);
void adios1(void);
void adios2(void);
void adios3(void);
void imprimirNumeroSaludos(void);
void imprimirNumeroDespedidas(void);

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
