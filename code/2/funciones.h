#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/* Declaraciones asociadas al programa */

# define TAM_NAME 51   /* Tamaño de la cadena que almacena el nombre del estudiante */
# define TAM_ID 16     /* Tamaño de la cadena que almacena el ID del estudiante */
# define MAX_EST 10

typedef struct estudiante {
  char nom[TAM_NAME];
  char id[TAM_ID];
  float nota;
} estudiante;

extern int est_matriculados;
/*
El extern evita el siguiente error al enlazar:

$ gcc *.c

/tmp/ccWt4e8G.o:(.bss+0x0): multiple definition of `est_matriculados'
/tmp/ccfoopdM.o:(.bss+0x0): first defined here
collect2: error: ld returned 1 exit status
*/

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

#endif
