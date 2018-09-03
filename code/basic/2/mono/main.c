#include <math.h>
#include <stdio.h>

void hola(int);
void todobien(void);
double potencia2(double);


int main() {
  printf("Hola...\n");
  hola(1);
  hola(2);
  todobien();
  double p = potencia2(10);
  printf("2^10 = %.1lf\n",p);
  return 0;
}

void hola(int opc) {
  if(opc == 1) {
    printf("Hola!!!\n");
  }
  else if(opc == 2) {
    printf("Hi!!!\n");
  }
  else {
    printf("ERROR: Opcion invalida!!!\n");
  }
}

void todobien(void) {
  printf("Todo bien, todo bonito!!!\n");
}

double potencia2(double x) {
  return pow(2,x);
}
