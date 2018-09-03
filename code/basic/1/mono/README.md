# Ejemplo monoarchivo

## Comandos de compilacion

### Forma 1. Compilando y enlazando por pasos

```
gcc -c -Wall main.c
gcc main.o -o main.out
```

### Forma 2. Compilando y enlazando en un solo comando

```
gcc -Wall main.c -o main.out
```

## Ejecución

```
./main.out
```
