#ifndef CORTESIA_H_
#define CORTESIA_H_

#include <stdio.h>

void hola(int opc);
void adios1(void);
void adios2(void);
void adios3(void);
void imprimirNumeroSaludos(void);
void imprimirNumeroDespedidas(void);

/* Ejemplo donde se emplean variables globales */
extern int numSaludos;
extern int numDespedidas;

#endif
