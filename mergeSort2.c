#include <stdio.h>

int swap=0;
int comp=0;

// Función para combinar dos subarreglos ordenados en uno solo
void merge(int arr[], int left[], int right[], int leftLength, int rightLength) {
    int i = 0, j = 0, k = 0;

    // Combinar los elementos de los subarreglos en orden ascendente
    while (i < leftLength && j < rightLength) {
        comp++;
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            swap++;
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes del subarreglo izquierdo, si los hay
    while (i < leftLength) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes del subarreglo derecho, si los hay
    while (j < rightLength) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Función recursiva para ordenar el arreglo usando MergeSort
void mergeSort(int arr[], int length) {
    if (length < 2) {
        return;  // Caso base: el arreglo está vacío o tiene un solo elemento
    }

    int mid = length / 2;

    // Crear subarreglos para la mitad izquierda y la mitad derecha del arreglo
    int left[mid];
    int right[length - mid];

    // Copiar elementos a los subarreglos
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < length; i++) {
        right[i - mid] = arr[i];
    }

    // Llamadas recursivas para ordenar los subarreglos
    mergeSort(left, mid);
    mergeSort(right, length - mid);

    // Combinar los subarreglos ordenados
    merge(arr, left, right, mid, length - mid);
}

// Función para imprimir el arreglo ordenado
void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 7, 5, 1, 2, 3, 6};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original: ");
    printArray(arr, length);

    mergeSort(arr, length);

    printf("Arreglo ordenado: ");
    printArray(arr, length);

    printf("\n");
    printf("El numero de swaps es: %d", swap);

    printf("\n");
    printf("El numero de comparaciones es: %d", comp);

    return 0;
}
