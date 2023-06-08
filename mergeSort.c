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

void merge(int *array, int p, int q, int r)
{
    // Declaracion de variables
    int i, j, k;
    int n_1 = (q - p) + 1;
    int n_2 = (r - q);
    int *L, *R;

    // Asignacion de memoria
    L = (int*)malloc(n_1 * sizeof(int));
    R = (int*)malloc(n_2 * sizeof(int));

    // Copia de datos del arreglo A en los subarreglos L y R
    for (i = 0; i < n_1; i++)
    {
        L[i] = *(array + p + i);
    }

    for (j = 0; j < n_2; j++)
    {
        R[j] = *(array + q + j + 1);
    }

    i = 0;
    j = 0;

    // Fusion de datos respetando el valor minimos entre dos arreglos
    for (k = p; k < r + 1; k++)
    {
        comp++;
        if (i == n_1)
        {
            *(array + k) = *(R + j);
            j =  j+ 1;
            //swap++;
        }
        else if(j == n_2)
        {
            *(array + k) = *(L + i);
            i = i + 1;
            //swap++;
        }
        else
        {
            if (*(L + i) <= *(R + j))
            {
                *(array + k) = *(L + i);
                i = i + 1;
                //swap++;
            }
            else
            {
                *(array + k) = *(R + j);
                j = j + 1;
                swap++;
            }
        }
    }
}

void merge_sort(int *array, int p, int r)
{
    if (p < r)
    {
        // Dividir el problema en subproblemas
        int q = (p + r)/2;
        
        // Resolver el problema de manera recursiva hasta llegar a una solucion trivial
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        
        // Fusion de resultados parciales
        merge(array, p, q, r);
    }
}

int main()
{
    int i;
    //int A[] = {2, 4, 5, 7, 1, 2, 3, 6};
    //int r = sizeof(A)/sizeof(A[0]) - 1
    int p = 0;

    int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);


    merge_sort(numeros, p, cantidad);

    for (i = 0; i < cantidad; i++)
    {
        printf(" %i ", *(numeros + i));
    }
    printf("\n");
 printf("El numero de comparaciones es: %d", comp);
 printf("\n");
 printf("El numero de swaps es: %d", swap);
}