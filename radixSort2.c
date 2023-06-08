#include <stdio.h>

// Función auxiliar para encontrar el máximo elemento en un arreglo
int encontrarMaximo(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Función para realizar el ordenamiento Radix Sort
void radixSort(int arr[], int n) {
    int max = encontrarMaximo(arr, n); // Encontrar el máximo elemento en el arreglo

    // Realizar el conteo de frecuencias para cada dígito
    for (int exp = 1; max/exp > 0; exp *= 10) {
        int conteo[10] = {0}; // Inicializar el arreglo de conteo de frecuencias
        int resultado[n]; // Arreglo para almacenar los elementos ordenados

        // Contar la frecuencia de cada dígito en la posición actual
        for (int i = 0; i < n; i++) {
            conteo[(arr[i] / exp) % 10]++;
        }

        // Calcular las posiciones actuales de los elementos en el arreglo ordenado
        for (int i = 1; i < 10; i++) {
            conteo[i] += conteo[i - 1];
        }

        // Colocar los elementos en el arreglo ordenado según las posiciones calculadas
        for (int i = n - 1; i >= 0; i--) {
            resultado[conteo[(arr[i] / exp) % 10] - 1] = arr[i];
            conteo[(arr[i] / exp) % 10]--;
        }

        // Copiar los elementos ordenados al arreglo original
        for (int i = 0; i < n; i++) {
            arr[i] = resultado[i];
        }
    }
}

// Función auxiliar para imprimir un arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función principal
int main() {
    int arr[] = {4,1,1,10,8,1,3,3,4,7,1,0,5,8,7,4,3,7,4,6,10,3,3,2,4,4,9,5,6,5,5,0,5,7,5,10,2,4,7,6,9,7,8,6,8,2,9,8,8,9,7,6,6,2,6,9,8,3,3,1,8,3,0,5,0,7,2,8,5,3,8,7,1,0,4,7,10,9,9,8,9,5,3,5,3,3,8,2,1,4,9,6,4,10,8,8,4,6,9,5,9,10,5,8,0,4,3,5,1,7,4,4,8,5,2,9,10,5,5,0,1,9,4,5,3,7,4,6,1,2,5,8,0,1,6,0,3,6,3,3,7,4,5,7,0,2,7,3,3,2,7,3,4,9,6,3,4,5,3,2,3,10,5,10,0,7,9,1,4,0,5,2,4,0,0,6,2,0,4,8,2,10,1,10,1,3,4,6,10,3,8,3,9,10,10,10,10,1,0,6,5,0,7,9,0,8,10,5,5,10,5,1,3,7,3,2,5,0,0,10,3,8,2,7,3,4,2,0,2,0,9,10,2,9,0,5,4,4,8,5,9,3,8,3,7,0,1,9,0,6,8,3,2,6,9,3,8,1,2,4,2,4,10,10,5,5,1,9,0,8,7,0,9,9,1,7,0,5,2,8,2,4,6,5,5,10,1,9,4,1,4,9,10,7,10,5,3,10,1,6,2,2,1,7,8,2,5,1,6,0,1,8,2,9,6,5,1,2,0,5,8,9,4,2,2,6,5,5,8,8,6,5,8,6,10,10,8,1,7,1,2,3,6,8,9,0,0,2,6,5,0,2,3,9,6,8,4,1,2,9,6,6,5,2,6,6,10,3,7,8,2,0,2,8,0,8,10,10,7,2,3,9,1,3,4,5,10,8,0,7,7,7,3,9,4,1,7,9,5,7,8,5,3,3,3,6,0,0,4,4,8,3,0,8,6,1,6,10,5,0,6,10,2,2,10,8,5,9,6,10,7,0,5,4,2,5,1,3,1,8,5,1,0,1,8,2,5,10,7,2,9,6,1,2,4,8,6,5,9,9,7,0,7,10,8,5,1,4,9,5,8,4,10,6,7,9,6,3,9,2,8,1,5,3,6,8,9,8,5,10,7,2,9,3,3,9,0,5,2,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original: ");
    imprimirArreglo(arr, n);

    radixSort(arr, n);

    printf("Arreglo ordenado: ");
    imprimirArreglo(arr, n);

    return 0;
}
