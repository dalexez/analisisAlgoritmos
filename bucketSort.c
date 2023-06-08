/*
 * C Program to Implement Bucket Sort
 */
 
#include <stdio.h>
#include<limits.h>
 
//Funcion para encontrar el elemnto maximo del arreglo
int max_element(int array[], int size) 
{  
    //Inicializando la varible maxima 
    
    int max = INT_MIN;  
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)  
        max = array[i];  
    }
    // Regresa el elemento maximo
    return max;  
}
 
//Implementando bucket sort 
void Bucket_Sort(int array[], int size) 
{  
    //Encontrar el elemento máximo de la matriz que usaremos para crear cubos
    int max = max_element(array, size); 
 
    // Creando buckets 
    int bucket[max+1];  
 
    //Initializando buckets a cero
    for (int i = 0; i <= max; i++)  
         bucket[i] = 0;  
  
    //Empujando los elementos a los buckets correspondientes 
    for (int i = 0; i < size; i++)  
        bucket[array[i]]++;
    /* Imprimir*/
    for (int i=0; i<= max; i++) 
        printf("bucket %d: %d\n",i,bucket[i]);
    // Mezcando los buckets 
    int j=0;   // j es una variable que apunta al indice que estamos actualizando
    for (int i = 0; i <= max; i++)  
    { 
         // Ejecutar el ciclo while mientras hay un elemento en el bucket
        while (bucket[i] > 0)  
        {  
            //Actualizando arreglo e incremento j 
            array[j++] = i;  
  
            //Decrementando cuenta de elemento bucket 
            bucket[i]--;   
        }  
    }  
}  
 
int main()
{
    int array[100], i, num; 
 
    printf("Tamaño del arreglo: ");   
    scanf("%d", &num);   
    printf("Entra el elemento %d para ordenar:\n",num); 
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]); 
    printf("\nEl arreglo antes de ordenar: \n");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);  
    printf("\nEl arreglo despues de ordenar: \n"); 
 
    // Bucketsort
    Bucket_Sort(array, num); 
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);   
    printf("\n");     
    return 0;
}