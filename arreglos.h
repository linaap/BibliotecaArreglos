
#ifndef ARREGLOS_H //{EVITAR QUE SE LLAME más de una vez la biblioteca, solo se llama una vez
#define ARREGLOS_H

#define CUADRADO(x) ((x)*(x))

#define PI 3.1416

#define DEBUG //depurar, comprobar si hay errores, optimizar el codigo, no tiene ningún valor (no obligatorio). Si no defino no se ejecuta el DEBUG

int sumaArreglo(int arr[], int n); // se declara la función para usar luego
int maximo(int arr[], int n);
void cuadradoArreglo(int arr[], int n);
void imprimirArreglo(int arr[], int n);
int busquedaLineal(int arr[], int n, int objetivo);
int busquedaBinariaIterativa(int arr[], int n, int objetivo);
int busquedaBinariaRecursiva(int arr[], int n, int objetivo, int inicio, int fin);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge(int arr[], int inicio, int mit, int fin);
void mergeSort(int arr[], int inicio, int fin);
void intercambiar(int &a, int &b);
int particionar(int arr[], int inicio, int fin);
void quickSort(int arr[], int inicio, int fin);

#endif
