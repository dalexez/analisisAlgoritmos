// Radix Sort in C Programming

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
//#define N 10000

//int A[N]={5151,8982,105,3826,180,9869,47,631,7056,8428,3244,1717,4102,8483,7150,99,3410,1045,9038,485,5080,7996,6287,6998,1393,6864,9545,5001,1771,920,4204,3326,4682,3270,9041,9055,370,6381,2128,1098,5048,1289,5848,2450,162,2793,1764,3281,4227,6798,6969,2393,409,5913,8801,2869,1999,2222,3643,1948,3683,5249,8157,2022,3483,4247,3113,1974,3713,3704,2270,1030,9878,939,8957,5008,6258,3240,9653,7765,2242,2110,4455,4743,8556,9951,1366,7183,7670,166,1120,8753,8392,4086,7127,2796,192,7607,6842,7217,4502,8206,3379,9900,6205,4350,486,8306,6595,8805,358,7577,802,8959,3764,5103,2890,4359,8359,534,3098,4806,5081,3648,3858,8973,214,1006,4571,3310,3006,6343,3481,3082,8534,6663,5994,5528,2140,5423,127,8057,834,2819,5028,5290,951,6262,1529,4041,8793,1302,3046,43,5828,4560,24,8274,6693,8735,922,8349,937,606,609,9411,2687,9120,2335,7216,9412,3604,551,4686,8202,6906,6697,6083,3095,5173,3510,6253,6326,1175,640,4695,5749,3578,6048,3768,3240,9666,4674,4629,5463,2661,5061,7861,8202,5612,5624,892,522,2549,6955,265,3166,8265,2122,6759,5534,8483,8144,605,4788,7919,6308,139,9960,5250,2006,4059,3940,8031,1322,9383,5198,381,6932,2514,7609,561,9085,4012,5777,6123,8700,8726,4897,4165,3218,7005,161,9767,7368,123,9885,4313,1603,962,2895,2758,5487,5636,1989,1372,1960,7519,7016,3042,6589,7046,2551,639,4307,1056,5446,5118,6069,6348,1677,2423,7496,776,4361,6762,6160,1891,1962,1977,2620,485,1719,1741,7763,2871,757,7780,4987,978,1579,2373,2558,245,4844,4120,184,2482,9117,21,8561,2830,1960,1399,5296,2471,9311,4135,7651,879,1537,315,6579,6300,150,297,6557,2492,8251,3121,9926,4909,3342,5978,875,3261,944,9828,9499,7483,1872,2717,418,1930,3310,0,7032,3518,1677,1776,9720,9942,3772,2039,767,1965,7401,9628,4337,816,2652,7637,3604,1491,9483,4974,5729,7889,7480,1600,4044,3988,2583,312,6804,8054,6228,8740,1474,1318,213,5443,6692,7051,1230,5938,2542,5311,1999,1685,7258,7575,4017,8287,3975,8878,973,3582,1585,2749,7424,7645,9505,1429,1145,4079,2096,728,5857,4850,7467,4774,3637,6116,6583,7006,5590,8579,386,7373,5207,2588,7921,2087,9809,9167,767,3957,8100,1249,8299,9877,6688,8423,1631,3507,8477,6686,8185,9069,9217,2700,6682,1527,9984,8941,4914,782,4231,7079,86,3453,4836,7089,6441,6031,9368,3859,365,2356,1117,8819,6001,8133,8589,469,1776,4361,991,6026,2346,2840,3496,1676,9156,7954,7252,5989,892,3420,3641,7394,5792,4827,4195,5160,1085,1730,4970,4788,3692,6733,4066,2357,5742,7025,5554,864,1356,5165,7186,4153,6607,4163,528,1708,2227,1933,8291,9027};
int b=0;
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

// Funcion para obtener el elemento mas grande de un arreglo
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Uso de Counting Sort para ordenar los elementos en funcion de 
// los lugares significativos 

void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  
  //Poner en 0 los elementos
  int count[max + 1];
  for (int i = 0; i <= max; ++i)
    count[i] = 0;

  // Calcular el recuento de elementos
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
    operaciones++;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
  for (int i=0; i<size; i++)
      printf("%d ",array[i]);
  printf("\n");
}

// Funcion principal para implementar radix sort

void radixsort(int array[], int size) {
  // Obtener el elemento maximo
  int max = getMax(array, size);

  // Aplica Counting Sort según su valor posicional
  
  for (int place = 1; max / place > 0; place *= 10){
    b++;//cantidad de digitos que tiene el numero mas grande
    countingSort(array, size, place);
  }  
}

// Imprimir un arreglo
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Codigo principal
int main() {
  int cantidad;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo a leer: ");
    scanf("%s", nombreArchivo);

    int* numeros = leerArchivoNumeros(nombreArchivo, &cantidad);  
  //int array[] = {4,1,1,10,8,1,3,3,4,7,1,0,5,8,7,4,3,7,4,6,10,3,3,2,4,4,9,5,6,5,5,0,5,7,5,10,2,4,7,6,9,7,8,6,8,2,9,8,8,9,7,6,6,2,6,9,8,3,3,1,8,3,0,5,0,7,2,8,5,3,8,7,1,0,4,7,10,9,9,8,9,5,3,5,3,3,8,2,1,4,9,6,4,10,8,8,4,6,9,5,9,10,5,8,0,4,3,5,1,7,4,4,8,5,2,9,10,5,5,0,1,9,4,5,3,7,4,6,1,2,5,8,0,1,6,0,3,6,3,3,7,4,5,7,0,2,7,3,3,2,7,3,4,9,6,3,4,5,3,2,3,10,5,10,0,7,9,1,4,0,5,2,4,0,0,6,2,0,4,8,2,10,1,10,1,3,4,6,10,3,8,3,9,10,10,10,10,1,0,6,5,0,7,9,0,8,10,5,5,10,5,1,3,7,3,2,5,0,0,10,3,8,2,7,3,4,2,0,2,0,9,10,2,9,0,5,4,4,8,5,9,3,8,3,7,0,1,9,0,6,8,3,2,6,9,3,8,1,2,4,2,4,10,10,5,5,1,9,0,8,7,0,9,9,1,7,0,5,2,8,2,4,6,5,5,10,1,9,4,1,4,9,10,7,10,5,3,10,1,6,2,2,1,7,8,2,5,1,6,0,1,8,2,9,6,5,1,2,0,5,8,9,4,2,2,6,5,5,8,8,6,5,8,6,10,10,8,1,7,1,2,3,6,8,9,0,0,2,6,5,0,2,3,9,6,8,4,1,2,9,6,6,5,2,6,6,10,3,7,8,2,0,2,8,0,8,10,10,7,2,3,9,1,3,4,5,10,8,0,7,7,7,3,9,4,1,7,9,5,7,8,5,3,3,3,6,0,0,4,4,8,3,0,8,6,1,6,10,5,0,6,10,2,2,10,8,5,9,6,10,7,0,5,4,2,5,1,3,1,8,5,1,0,1,8,2,5,10,7,2,9,6,1,2,4,8,6,5,9,9,7,0,7,10,8,5,1,4,9,5,8,4,10,6,7,9,6,3,9,2,8,1,5,3,6,8,9,8,5,10,7,2,9,3,3,9,0,5,2,6};
  //int n = sizeof(array) / sizeof(array[0]);
  radixsort(numeros, cantidad);
  printArray(numeros, cantidad);
  printf("\n");
 printf("El numero de operaciones es: %d", operaciones);
 printf("\n");
 printf("El numero de digitos del numero mayor ('b') es: %d", b);
 
}