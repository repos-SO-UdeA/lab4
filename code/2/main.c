#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "tests.h"

int est_matriculados = 0;

int main() {
  /*Variables locales */
  int opc;  // Variable asociada al menu
  int banExit = 0; // bandera para salirse del programa
  char nom[TAM_NAME]; // Nombres del estudiante
  char cc[TAM_ID]; // Identificacion del estudiante
  estudiante est; // Variable auxiliar para almacenar datos del estudiante
  int banEst;  // Bandera con la que se indica si un estudiante fue agregado a la lista
  printf("%s\n","SISTEMA PARA ADMINISTRACION DEL CURSO DE SO");
  for(;;) {
    menu();
    scanf("%d", &opc);
    switch (opc) {
      case 1:
        if(est_matriculados == 0) {
          printf("\nNo hay estudiantes matriculados. Presione [Enter] para continuar... ");
          waitForEnter();
          clear();
        }
        else {
          imprimirLista();
          printf("\n\nPresione [Enter] para continuar... ");
          waitForEnter();
          clear();
        }
        break;
      case 2:
        printf("Ingresando los datos del estudiante\n");
        printf("- Nombre: ");
        //gets(nom);
        //fgets(nom, TAM_NAME, stdin);
        //scanf("%[^\n]s", nom);  // Para poder leer espacios en el scanf
        scanf("%s", nom); // Nota: Hay un bug pues no se logran leer nombres completos
        printf("- Cedula: ");
        scanf("%s", cc);
        est = llenarDatos(nom, cc, 0.0);
        banEst = agregarEstudiante(est);
        if(banEst == TRUE) {
          printf("\nEstudiante agregado...");
        }
        else {
          printf("\nERROR!!! No hay cupos...");
        }
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 3:
        printf("Ingrese la identificacion del estudiante a eliminar: ");
        scanf("%s",cc);
        if(estudianteDisponible(cc) == FALSE) {
          printf("\nERROR!!! Estudiante no disponible...");
        }
        else {
          removerEstudiante(cc);
          printf("\nEstudiante eliminado...");
        }
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 4:
        printf("Ingrese la identificacion del estudiante: ");
        scanf("%s",cc);
        if(estudianteDisponible(cc) == FALSE) {
          printf("\nERROR!!! Estudiante no disponible...");
        }
        else {
          estudiante *ptr = obtenerEstudiante(cc);
          imprimirDatos(*ptr);
        }
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 5:
        printf("Ingrese la identificacion del estudiante: ");
        scanf("%s",cc);
        if(estudianteDisponible(cc) == FALSE) {
          printf("\nERROR!!! Estudiante no disponible...");
        }
        else {
          float nota;
          printf("Ingrese la calificacion del estudiante: ");
          scanf("%f", &nota);
          modificarNota(cc, nota);
          printf("\nNota actualizada...");
        }
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 6:
        printf("El promedio del grupo es: %.1f\n", calcularPromedio());
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 7:
        printf("Suerte es que le digo\n");
        banExit = 1;
        break;
      default:
        printf("ERROR!!! Opcion invalida. Presione enter para continuar\n");
        waitForEnter();
        clear();
    }
    if(banExit == 1) {
      break;
    }
  }
  printf("\nCerrando el programa...\n");
  waitForEnter();
  //test1();
  return 0;
}
