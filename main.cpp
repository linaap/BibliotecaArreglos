#include <iostream>
#include "arreglos.h"

using namespace std;

int main(){
//	int numeros[] = {6, 7, 67};
	int numeros[] = {5, 8, 10, 15, 20, 32};
	int arreglo[] = {10,12,11,4,8};
	const double euler = 2.7182; //definimos una variable temporal aparte dentro del main
	// euler = 2; -> no se compila, es una constante
	
	cout << "Suma del arreglo: " << sumaArreglo(numeros, 3) << endl;
	
	cout << "El maximo del arreglo: " << maximo(numeros, sizeof(int)) << endl; //el sizeof se usa en arreglos dinamicos
	
	cout << "Valor de PI: " << PI << endl; //comprobamos que se puede usar la constante
	cout << "Valor de euler: " << euler << endl;
	
	cout << "Cuadrado del arreglo: " << endl;
	cuadradoArreglo(numeros, 3);
	imprimirArreglo(numeros, 3);
	
	cout << "La posicion de su elemento es: " << busquedaLineal(numeros, 6, 20) << endl;
	
	cout << "La posicion de su elemento es: " << busquedaBinariaIterativa(numeros, 6, 20) <<endl;
	
	cout << "La posicion de su elemento es: " << busquedaBinariaRecursiva(numeros, 6, 20, 0, 6) <<endl; 
	
	cout << "Arreglo desordenado: " << endl;
	imprimirArreglo(arreglo, 5);
	
//	bubbleSort(arreglo,6);
//	cout << "Arreglo ordenado: " << endl;
//	imprimirArreglo(arreglo, 6);
	
//	selectionSort(arreglo, 6);
//	cout << "Arreglo ordenado: " << endl;
//	imprimirArreglo(arreglo, 6);

//	insertionSort(arreglo, 5);
//	cout << "Arreglo ordenado: " << endl;
//	imprimirArreglo(arreglo, 5);
	
//	mergeSort(arreglo, 0, 4);
//	cout << "Arreglo ordenado: " << endl;
//	imprimirArreglo(arreglo, 5);
	
	quickSort(arreglo, 0, 4);
	cout << "Arreglo ordenado: " << endl;
	imprimirArreglo(arreglo, 5);
	
	return 0;
}

void complejidadConstante(int arr[]){
	// complejidad O(3), complejidad de 3
	arr[0] += arr[1]; //operaciones simples,
	arr[1] += arr[2];
	arr[2] += arr[3];
}
