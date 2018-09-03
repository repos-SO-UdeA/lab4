# Ejemplo multiarchivo

## Comandos de compilacion y enlazado

### Compilando y enlazando por pasos

En este caso se compila cada uno de los archivos fuente generando archivos objeto para luego unir estos ultimos y generar el ejecutable

```
gcc -Wall -I. -c tests.c
gcc -Wall -I. -c funciones.c
gcc -Wall -I. -c main.c
gcc test.o funciones.o main.o -o admin_clase.out
```

### Compilando y enlazando por pasos pero usando comodines

```
gcc -I. -c -Wall *.c
gcc *.o -o admin_clase.out
```

### Compilando y enlazando por pasos en un solo paso

```
gcc -I. -Wall *.c -o admin_clase.out
```

## Ejecución

```
./admin_clase.out
```
