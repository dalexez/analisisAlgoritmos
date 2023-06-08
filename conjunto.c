#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generarArchivoNumeros(int cantidad, int rango, const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }
  
    srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios
  
    for (int i = 0; i < cantidad; i++) {
        int numero = rand() % (rango + 1);
        fprintf(archivo, "%d\n", numero);
    }
  
    fclose(archivo);
    printf("Archivo creado exitosamente.\n");
}

int main() {
    int cantidad, rango;
    char nombreArchivo[100];

    printf("Ingrese el cantidad del conjunto de números: ");
    scanf("%d", &cantidad);

    printf("Ingrese el rango máximo de los números: ");
    scanf("%d", &rango);

    printf("Ingrese el nombre del archivo: ");
    scanf("%s.txt", nombreArchivo);
    strcat(nombreArchivo, ".txt");

    generarArchivoNumeros(cantidad, rango, nombreArchivo);

    return 0;
}
