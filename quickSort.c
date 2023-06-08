/* Algoritmo de ordenamiento: Quicksort
 * O(nlogn)
 */

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

void qs(int lista[],int limite_izq,int limite_der)
{
    int izq,der,temporal,pivote;

    izq=limite_izq;
    der = limite_der;
    pivote = lista[(izq+der)/2];

    do{
        while(lista[izq]<pivote && izq<limite_der)izq++;
        while(pivote<lista[der] && der > limite_izq)der--;
        comp++;
        if(izq <=der)
        {
            temporal= lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            swap++;
            izq++;
            der--;

        }

    }while(izq<=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}

}

void quicksort(int lista[],int n)
{
    qs(lista,0,n-1);
}

int main(int argc, const char * argv[])
{
    int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);

    //int lista[] ={100,56,0,1,-45,2,46,5,9,6,67,23,5};
    //int size = sizeof(lista)/sizeof(int);

    printf("Lista Desordenada \n");

    for (int i=0; i<cantidad; i++) {
        printf("%d",numeros[i]);
        if(i<cantidad-1)
            printf(",");
    }

    printf("\n");
    quicksort(numeros,cantidad);

    printf("Lista Ordenada \n");
    for (int i=0; i<cantidad; i++) {
        printf("%d",numeros[i]);
        if(i<cantidad-1)
            printf(",");
    }
    printf("\n");
 printf("El numero de comparaciones es: %d", comp);
 printf("\n");
 printf("El numero de swaps es: %d", swap);
    return 0;
}