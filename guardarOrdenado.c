#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* leerArchivoNumeros(const char* nombreArchivo, int* cantidad) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return NULL;
    }

    int* numeros = NULL;
    int capacidad = 10; // Capacidad inicial del arreglo
    int contador = 0;   // Contador de elementos leídos

    numeros = (int*)malloc(capacidad * sizeof(int));
    if (numeros == NULL) {
        printf("Error de asignación de memoria.\n");
        fclose(archivo);
        return NULL;
    }

    int numero;
    while (fscanf(archivo, "%d", &numero) == 1) {
        // Si se alcanza la capacidad del arreglo, se duplica
        if (contador == capacidad) {
            capacidad *= 2;
            numeros = (int*)realloc(numeros, capacidad * sizeof(int));
            if (numeros == NULL) {
                printf("Error de asignación de memoria.\n");
                fclose(archivo);
                return NULL;
            }
        }

        numeros[contador] = numero;
        contador++;
    }

    fclose(archivo);
    *cantidad = contador;
    return numeros;
}

void guardarEnArchivo(const char* nombreArchivo, int* numeros, int cantidad) {
    FILE* archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        fprintf(archivo, "%d\n", numeros[i]);
    }

    fclose(archivo);
    printf("El archivo se ha guardado correctamente.\n");
}

int main() {
    int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s.txt", nombreArchivo);
    strcat(nombreArchivo, ".txt");

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);

    if (numeros == NULL) {
        return 0;
    }

    int i, j, temp;
    int comp = 0;
    int swap = 0;

    for (i = 0; i < cantidad; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    for (i = 0; i < cantidad - 1; i++) {
        for (j = 0; j < cantidad - 1 - i; j++) {
            comp++;
            if (numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
                swap++;
            }
        }
    }

    for (i = 0; i < cantidad; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    printf("El número de comparaciones es: %d\n", comp);
    printf("El número de swaps es: %d\n", swap);

    printf("Ingrese el nombre del archivo para guardar los números ordenados: ");
    scanf("%s.txt", nombreArchivo);
    strcat(nombreArchivo, ".txt");

    guardarEnArchivo(nombreArchivo, numeros, cantidad);

    free(numeros);

    return 0;
}
