/*
 * Insertion sort O(n^2)
 */

#include <stdio.h>
#include <stdlib.h>
#define N 5

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


void InsertionSort(int A[],int n)
{
  int i,j,x;

  for (int i=1; i<n; i++)
  {
    j=i-1;
    x=A[i];
    while((j>-1) && (A[j]>x))
    {
     comp++;
     A[j+1]=A[j];
     j--;
    }
    A[j+1]=x;
    swap++;
  }
}

int main()
{

    int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);
  //int A[]={8,5,7,3,2};

  for (int i=0; i < cantidad; i++)
      printf("%d ",numeros[i]);
  printf("\n");

  InsertionSort(numeros,cantidad);

  for (int i=0; i < cantidad; i++)
      printf("%d ",numeros[i]);
  printf("\n");
  printf("\n");
  printf("El numero de comparaciones es: %d", comp);
  printf("\n");
  printf("El numero de swaps es: %d", swap);

}
