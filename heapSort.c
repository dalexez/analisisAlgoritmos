#include <stdio.h>
#include <stdlib.h> 
// almacena el tamaño del heap
int end;

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
 
void swap(int *x, int *y) {
    *x = (*x**y) / (*y = *x);
    swapC++;
}
 
// devuelve el hijo izquierdo de 'A[i]'
int LEFT(int i) {
    return (2*i + 1);
}
 
// devuelve el hijo derecho de 'A[i]'
int RIGHT(int i) {
    return (2*i + 2);
}
 
// Algoritmo recursivo heapify-down
// el nodo en el índice 'i' y sus dos hijos directos
// viola la propiedad del heap
void heapify(int A[], int i)
{
    // obtener el hijo izquierdo y derecho del nodo en el índice 'i'
    int left = LEFT(i);
    int right = RIGHT(i);
 
    // compara 'A[i]' con su hijo izquierdo y derecho
    // y encontrar el mayor valor
    int largest = i;
    comp++;
 
    if (left < end && A[left] > A[i]) {
        largest = left;
    }
 
    if (right < end && A[right] > A[largest]) {
        largest = right;
    }
 
    // intercambiar con un hijo que tenga mayor valor y
    // llamar a heapify en el hijo
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, largest);
    }
}
 
// Reorganizar los elementos de la array para construir max-heap
void BuildHeap(int A[])
{
    // llamar a heapify comenzando desde el último nodo interno todos los
    // camino hacia el nodo raíz
    int i = (end - 2) / 2;
    while (i >= 0) {
        heapify(A, i--);
    }
}
 
void heapsort(int A[], int n)
{
    // inicializa el tamaño del heap como el número total de elementos en la array
    end = n;
 
    // reorganizar elementos de array para construir max-heap
    BuildHeap(A);
 
    /* El siguiente ciclo mantiene que `A[0, end-1]`
       es un heap y cada elemento más allá del final es mayor que
       todo lo anterior (entonces `A[end: n-1]` está en orden) */
 
    // hacer hasta que solo quede un elemento en el heap
    while (end != 1)
    {
        // mueve el siguiente elemento mayor al final del
        // array (lo mueve delante de los elementos ordenados)
        
        swap(&A[0], &A[end - 1]);
        printf("despues de Intercambia\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
        //disminuir el tamaño del heap en 1
        end--;
 
        // llamar a heapify en el nodo raíz cuando el intercambio se destruyó
        // la propiedad del heap
        heapify(A, 0);
        printf("despues de heapify 0\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}
 
// Implementación del algoritmo Heapsort en C
int main(void)
{
    int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);
    //int A[] = { 6, 4, 7, 1, 9, -2 };
    //int A[] = {2, 8, 5, 3, 9, 1};
    //int n = sizeof(A) / sizeof(A[0]);
 
    // realizar heapsort en la array
    heapsort(numeros, cantidad);
 
    // imprime la array ordenada
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    printf("\n");
 printf("El numero de comparaciones es: %d", comp);
 printf("\n");
 printf("El numero de swaps es: %d", swapC);
 
    return 0;
}