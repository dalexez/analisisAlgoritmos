#include <stdio.h>
#include <stdlib.h>

int comp=0;
int swapC=0;

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


// Función para intercambiar dos elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
    swapC++;
}

// Función que toma el último elemento como pivote,
// coloca el elemento pivote en la posición correcta
// en el arreglo ordenado y coloca todos los elementos
// menores que el pivote a su izquierda y los mayores
// que el pivote a su derecha.
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // seleccionamos el último elemento como pivote
    int i = (low - 1); // índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        comp++;
        // Si el elemento actual es más pequeño que el pivote
        if (arr[j] < pivot) {
            i++; // incrementamos el índice del elemento más pequeño
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función principal que implementa QuickSort
// arr[] --> arreglo a ser ordenado,
// low --> índice inicial,
// high --> índice final
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi es la partición del índice, arr[p] ahora está en su posición correcta
        int pi = partition(arr, low, high);

        // Ordenamos los elementos por separado antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Ejemplo de uso
int main() {
    int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);
    //int arr[] = { 10, 7, 8, 9, 1, 5 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo original:\n");
    printArray(numeros, cantidad);
    quickSort(numeros, 0, cantidad - 1);
    printf("Arreglo ordenado:\n");
    printArray(numeros, cantidad);
    printf("\n");
 printf("El numero de comparaciones es: %d", comp);
 printf("\n");
 printf("El numero de swaps es: %d", swapC);
 
    return 0;
}
