#include "tests.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void test1(void) {
  estudiante e1, e2, e3, e4;
  e1 = llenarDatos("Bart Simpson", "0001", 2.3);
  e2 = llenarDatos("Rafa Gorgori", "0002", 2.4);
  e3 = llenarDatos("Lisa Simpson", "0003", 5.0);
  e4 = llenarDatos("Nelson Ruffino", "0004", 2.9);
  agregarEstudiante(e1);
  agregarEstudiante(e2);
  agregarEstudiante(e3);
  printf("Numero de estudiantes: %d\n", est_matriculados);
  printf("\n");
  imprimirLista();
  removerEstudiante("0001");
  printf("\n");
  imprimirLista();
  agregarEstudiante(e4);
  //imprimirDatos(e1)
  printf("\n");
  imprimirLista();
}
