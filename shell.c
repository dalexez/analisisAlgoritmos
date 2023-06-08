// Shell Sort in C programming

#include <stdio.h>
#include <stdlib.h>

int comp=0;
int swap=0;

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

// Shell sort
void shellSort(int array[], int n) {
  // Arregla los elementos en intervalos de  n/2, n/4, n/8, ... 
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      comp++;
     // printf("\n");
     // printf("Se sumo un comp en el intervalo:  %d",interval);
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        comp++;
       // printf("\n");
       // printf("Se realizo un swap,  El numero: %d",array[j]);
        array[j] = array[j - interval];
        swap++;
       // printf(" por el numero numero: %d",array[j - interval]);
       // printf("\n");
      //printf("Se sumo un comp en el intervalo:  %d",interval);
      }
      array[j] = temp;
    }
  }
}

// Imprime el arreglo
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {

  int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);

  //int data[] = {8,12,9,10};
  //int size = sizeof(data) / sizeof(data[0]);
  printf("Arreglo desordenado\n");
  printArray(numeros,cantidad);
  shellSort(numeros, cantidad);
  printf("\n");
  printf("Arreglo ordenado: \n");
  printArray(numeros, cantidad);
  printf("El numero de comparaciones es: %d", comp);
  printf("\n");
  printf("El numero de swaps es: %d", swap);
  //printf("\n");
 // printf("El numero de size es: %d", size);
}