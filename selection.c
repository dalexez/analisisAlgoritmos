/*
 * Selection sort O(n^2)
 */

#include <stdio.h>
#include <stdlib.h>
#define N 6


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


void SelectionSort(int numeros[],int n)
{
  for (int i=0; i<n-1; i++)
  {
    int iMin=i;  //i-esima posicion,elementos desde i hasta n-1 que son candidatos
    for (int j=i+1; j<n; j++)
    {
      comp++;  
      if (numeros[j] < numeros[iMin])
         iMin = j;       // Actualiza el indice del elemento minimo
    }
    int temp = numeros[i];
    numeros[i] = numeros[iMin];
    numeros[iMin] = temp;
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


  //int numeros[]={2,7,4,1,5,3};

  for (int i=0; i < cantidad; i++)
      printf("%d ",numeros[i]);
  printf("\n");

  SelectionSort(numeros,cantidad);

  for (int i=0; i < cantidad; i++)
      printf("%d ",numeros[i]);
  printf("\n");
  printf("El numero de comparaciones es: %d", comp);
  printf("\n");
  printf("El numero de swaps es: %d", swap);

}