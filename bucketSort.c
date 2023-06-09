/*
 * C Program to Implement Bucket Sort
 */
 
#include <stdio.h>
#include<limits.h>
#include <stdlib.h>
//#define N 10000

//int A[N]={5151,8982,105,3826,180,9869,47,631,7056,8428,3244,1717,4102,8483,7150,99,3410,1045,9038,485,5080,7996,6287,6998,1393,6864,9545,5001,1771,920,4204,3326,4682,3270,9041,9055,370,6381,2128,1098,5048,1289,5848,2450,162,2793,1764,3281,4227,6798,6969,2393,409,5913,8801,2869,1999,2222,3643,1948,3683,5249,8157,2022,3483,4247,3113,1974,3713,3704,2270,1030,9878,939,8957,5008,6258,3240,9653,7765,2242,2110,4455,4743,8556,9951,1366,7183,7670,166,1120,8753,8392,4086,7127,2796,192,7607,6842,7217,4502,8206,3379,9900,6205,4350,486,8306,6595,8805,358,7577,802,8959,3764,5103,2890,4359,8359,534,3098,4806,5081,3648,3858,8973,214,1006,4571,3310,3006,6343,3481,3082,8534,6663,5994,5528,2140,5423,127,8057,834,2819,5028,5290,951,6262,1529,4041,8793,1302,3046,43,5828,4560,24,8274,6693,8735,922,8349,937,606,609,9411,2687,9120,2335,7216,9412,3604,551,4686,8202,6906,6697,6083,3095,5173,3510,6253,6326,1175,640,4695,5749,3578,6048,3768,3240,9666,4674,4629,5463,2661,5061,7861,8202,5612,5624,892,522,2549,6955,265,3166,8265,2122,6759,5534,8483,8144,605,4788,7919,6308,139,9960,5250,2006,4059,3940,8031,1322,9383,5198,381,6932,2514,7609,561,9085,4012,5777,6123,8700,8726,4897,4165,3218,7005,161,9767,7368,123,9885,4313,1603,962,2895,2758,5487,5636,1989,1372,1960,7519,7016,3042,6589,7046,2551,639,4307,1056,5446,5118,6069,6348,1677,2423,7496,776,4361,6762,6160,1891,1962,1977,2620,485,1719,1741,7763,2871,757,7780,4987,978,1579,2373,2558,245,4844,4120,184,2482,9117,21,8561,2830,1960,1399,5296,2471,9311,4135,7651,879,1537,315,6579,6300,150,297,6557,2492,8251,3121,9926,4909,3342,5978,875,3261,944,9828,9499,7483,1872,2717,418,1930,3310,0,7032,3518,1677,1776,9720,9942,3772,2039,767,1965,7401,9628,4337,816,2652,7637,3604,1491,9483,4974,5729,7889,7480,1600,4044,3988,2583,312,6804,8054,6228,8740,1474,1318,213,5443,6692,7051,1230,5938,2542,5311,1999,1685,7258,7575,4017,8287,3975,8878,973,3582,1585,2749,7424,7645,9505,1429,1145,4079,2096,728,5857,4850,7467,4774,3637,6116,6583,7006,5590,8579,386,7373,5207,2588,7921,2087,9809,9167,767,3957,8100,1249,8299,9877,6688,8423,1631,3507,8477,6686,8185,9069,9217,2700,6682,1527,9984,8941,4914,782,4231,7079,86,3453,4836,7089,6441,6031,9368,3859,365,2356,1117,8819,6001,8133,8589,469,1776,4361,991,6026,2346,2840,3496,1676,9156,7954,7252,5989,892,3420,3641,7394,5792,4827,4195,5160,1085,1730,4970,4788,3692,6733,4066,2357,5742,7025,5554,864,1356,5165,7186,4153,6607,4163,528,1708,2227,1933,8291,9027};
int comp=0;
int operaciones=0;

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
    // for (int i=0; i<= max; i++) 
    //     printf("bucket %d: %d\n",i,bucket[i]);
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
            operaciones++;   
        }  
    }  
}  
 
int main()
{

    int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);

    //int array[100], i, num; 
 
    // printf("Tamaño del arreglo: ");   
    // scanf("%d", &num);   
    // printf("Entra el elemento %d para ordenar:\n",num); 
    // for (i = 0; i < num; i++)
    //     scanf("%d", &array[i]); 
    // printf("\nEl arreglo antes de ordenar: \n");
    // for (i = 0; i < num; i++)
    //     printf("%d ", array[i]);  
    // printf("\nEl arreglo despues de ordenar: \n"); 
 
    // Bucketsort
    Bucket_Sort(numeros, cantidad); 
    for (int i = 0; i < cantidad; i++)
        printf("%d ", numeros[i]);   
    printf("\n");     
    
    printf("\n");
 printf("El numero de swaps es: %d", operaciones);
 return 0;

}