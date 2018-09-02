#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void menu(void) {
  printf("OPCIONES\n");
  printf("1. Imprimir Lista\n");
  printf("2. Agregar Estudiante\n");
  printf("3. Eliminar estudiante\n");
  printf("4. Obtener datos de un estudiante\n");
  printf("5. Modificar la nota de un estudiante\n");
  printf("6. Obtener el promedio del grupo\n");
  printf("7. Salir\n");
  printf("\nSeleccione una opcion: ");
}

void waitForEnter(void) {
  while(getchar()!='\n'); // option TWO to clean stdin
  getchar(); // wait for ENTER
}

estudiante llenarDatos(char *nom, char *id, float nota) {
  estudiante e;
  strcpy(e.nom, nom);
  strcpy(e.id, id);
  e.nota = nota;
  return e;
}

int estudianteDisponible(char *id) {
  for(int i = 0; i < est_matriculados; i++) {
    if(strcmp(id,grupo[i].id) == 0) {
      // Estudiante encontrado
      return TRUE;
    }
  }
  // Estudiante no encontrado
  return FALSE;
}

estudiante *obtenerEstudiante(char *id) {
  /* Requerimientos: Asume que el estudiante se encuentra en la lista */
  for(int i = 0; i < est_matriculados; i++) {
    if(strcmp(id,(grupo + i)->id) == 0) {
      return (grupo + i);
    }
  }
  return NULL;
}

void imprimirDatos(estudiante e) {
  printf("** DATOS DEL ESTUDIANTE **\n");
  printf("-> Nombre: %s\n",e.nom);
  printf("-> Identificacion: %s\n",e.id);
  printf("-> Nota: %.1f\n",e.nota);
}

float calcularPromedio(void) {
  float avg = 0;
  if(est_matriculados != 0) {
    for(int i = 0; i < est_matriculados; i++) {
      avg += (*(grupo + i)).nota;  //   avg += grupo[i].nota;  <--> avg += (grupo + i)->nota;
    }
    avg /= est_matriculados;
    return avg;
  }
  else {
    return 0;
  }
}

int agregarEstudiante(estudiante e) {
  if (est_matriculados <= MAX_EST) {
    // Aun hay cupos
    *(grupo + est_matriculados) = e;
    est_matriculados++;
    return TRUE; // Estudiante matriculado con exito
  }
  else {
    return FALSE;  // No se pudo matricular el estudiante
  }
}

int removerEstudiante(char *id) {
  if (est_matriculados == 0) {
    // No se puede remover estudiante
    return FALSE;
  }
  else {
    int pos = 0;
    for(int i = 0; i < est_matriculados; i++) {
      if(strcmp(id,(grupo + i)->id) == 0) {
        break;
      }
      pos++;
    }
    for(int i = pos; i < est_matriculados - 1; i++) {
      *(grupo + i) = *(grupo + (i + 1));
    }
    est_matriculados--;
    return TRUE;
  }
}

void imprimirLista(void) {
  printf("%-4s %-20s %-50s %5s\n", "#","IDENTIFICACION","NOMBRE","CEDULA");
  for(int i = 0; i < est_matriculados; i++) {
    printf("%-4d %-20s %-50s %-5.1f\n", i, grupo[i].id, (grupo + i)->nom, (*(grupo + i)).nota);
  }
}

void modificarNota(char *id, float nota) {
  for(int i = 0; i < est_matriculados; i++) {
    if(strcmp(id,(grupo + i)->id) == 0) {
      (grupo + i)->nota = nota;
    }
  }
}
