# Ejemplo multiarchivo

## Comandos de compilacion y enlazado

### Compilando y enlazando por pasos

En este caso se compila cada uno de los archivos fuente generando archivos objeto para luego unir estos ultimos y generar el ejecutable

```
gcc -I. -c -Wall cortesia.c
gcc -I. -c -Wall main.c
gcc -lm cortesia.o main.o -o main.out
```

### Compilando y enlazando por pasos pero usando comodines

```
gcc -I. -c -Wall *.c
gcc -lm *.o -o main.out
```

### Compilando y enlazando por pasos en un solo paso

```
gcc -I. -Wall -lm *.c -o main.out
```

## Ejecución

```
./main.out
```
