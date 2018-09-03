#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/* Declaraciones asociadas al programa */

# define TAM_NAME 51   /* Tamaño de la cadena que almacena el nombre del estudiante */
# define TAM_ID 16     /* Tamaño de la cadena que almacena el ID del estudiante */
# define MAX_EST 10

typedef struct estudiante {
  char nom[TAM_NAME];
  char id[TAM_ID];
  float nota;
} estudiante;

int est_matriculados = 0;

estudiante grupo[MAX_EST];

#define TRUE 1
#define FALSE 0

/* Prototipos de las funciones */

// Funcion con implementada como macro con #define
#define clear() printf("\033[H\033[J")

/* Funciones que implementan el despliegue de la interfaz*/

void menu(void);
void waitForEnter(void);

/* Funciones que implementan la logica de la aplicacion */

estudiante llenarDatos(char *nom, char *id, float nota);
int estudianteDisponible(char *id);
estudiante *obtenerEstudiante(char *id);
void imprimirDatos(estudiante e);
float calcularPromedio(void);
int agregarEstudiante(estudiante e);
int removerEstudiante(char *id);
void imprimirLista(void);
void modificarNota(char *id, float nota);

/* Funciones de test */

void test1(void);

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
