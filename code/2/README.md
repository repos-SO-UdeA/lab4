# Sobre el codigo

El codigo es multiarchivo. Por lo que las instrucciones para compilar son:

**Forma 1: Por partes:**

```
gcc -I. -c tests.c
gcc -I. -c funciones.c
gcc -I. -c main.c
gcc test.o funciones.o main.o -o admin_clase.out
```

**Forma 2: Mas abreviado (empleando comodines)**:

```
gcc -I. -c *.c
gcc *.o -o admin_clase.out
```

La ejecucion para ambos casos es la misma:

```
./admin_clase.out
```
