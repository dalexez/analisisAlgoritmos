// Counting sort en C

#include <stdio.h>
#include <stdlib.h>

int comp=0;
int swap=0;
int max=0;

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

void countingSort(int A[], int size) {
  int B[size];

  // Encuentra el elemnto mas grande del arreglo
   max = A[0];
  for (int i = 1; i < size; i++) {
    if (A[i] > max)
      max = A[i];
  }

  int C[max];

  //Inicializa el arreglo count con ceros 
  for (int i = 0; i <= max; ++i) {
    C[i] = 0;
  }

  // Almacena la cuenta de cada elemento
  for (int i = 0; i < size; i++) {
    C[A[i]]++;
    comp++;
  }

  // Almacena la cuenta acumulativa de cada arreglo 
  for (int i = 1; i <= max; i++) {
    C[i] += C[i - 1];
  }
  // Encuentra el índice de cada elemento de la matriz original
  // en la matriz de conteo y coloca los elementos en la matriz de salida
  for (int i = size - 1; i >= 0; i--) {
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }

  // Copia los elementos ordenados en el arreglo original 
  for (int i = 0; i < size; i++) {
    A[i] = B[i];
  }
}

// Function to print an array
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
  
  //int array[] = {3, 6, 4, 1, 3, 4, 1, 4};
  //int n = sizeof(array) / sizeof(array[0]);
  countingSort(numeros, cantidad);
  printArray(numeros, cantidad);
 printf("\n");
 //sumo el valor de max a los swap para contemplarlo en su complejidad que esta
 //dada por  O(n+k) donde k es el valor del maximo valor de los elementos "n"
 printf("El numero de operaciones es: %d", comp + max);
}