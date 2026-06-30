#include "arreglos.h"
#include <stdio.h> //para usar printf e imprimir internamente
#include <stdlib.h> //para usar malloc

//cambio externo o remoto
//cambio interno

//comentario lina 

int sumaArreglo(int arr[], int n){ //creamos funcion para sumar
	int suma = 0;
	for (int i = 0; i < n; i++){
		suma += arr[i];
	}
	return suma;
}

int maximo(int arr[], int n){
	int max = arr[0]; //se iguala al primer elemento del arreglo
	for(int i = 1; i< n; i++){ //empieza en 1 porque se asume que el valor de la posición 0 ya esl el máximo
		if(arr[i] > max){
			max = arr[i];
		}
		#ifdef DEBUG
			printf("Maximo: %d\n", max);
		#endif
	}
	return max; //se retorna el valor maximo, en otros casos se retorna la posición
}

int minimo(int arr[], int n){
	int min = arr[0]; //se iguala al primer elemento del arreglo
	for(int i = 1; i< n; i++){ //empieza en 1 porque se asume que el valor de la posición 0 ya esl el máximo
		if(arr[i] < min){
			min = arr[i];
		}
		#ifdef DEBUG
			printf("Minimo: %d\n", min);
		#endif
	}
	return min; //se retorna el valor minimo
}

void cuadradoArreglo(int arr[], int n){ //no retorna nada
	for(int i=0; i < n; i++){
		arr[i] = CUADRADO(arr[i]);
	}
}

void imprimirArreglo(int arr[], int n){
	for(int i=0; i<n; i++){
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

//busqueda lineal, capitulo 5
int busquedaLineal(int arr[], int n, int objetivo){
	for(int i =0; i< n; i++){
		if(arr[i]== objetivo) return i; //retorno la posicion del objetivo dentro del arreglo
	}
	return -1; //el elemento no fue encontrado, el indice -1 en C no existe
}

//busqueda binaria iterativa
int busquedaBinariaIterativa(int arr[], int n, int objetivo){
	int inicio = 0, fin = n-1, mit;
	
	while(inicio <= fin){ //divide hasta obtener la respuesta
		mit = (inicio + fin) /2;
		if(arr[mit] == objetivo) return mit; //si lo que buscamos está en la mitad, se retorna ese valor
		if(arr[mit] < objetivo) inicio = mit + 1;
		else fin = mit - 1;
		
	}
	return -1;
}

//busqueda binaria recursiva
int busquedaBinariaRecursiva(int arr[], int n, int objetivo, int inicio, int fin){ //inicio y fin me ayuda si quiero buscar en una parte específica
	
	if(inicio > fin) return -1;
	
	int mit = (inicio + fin)/2;
	if(arr[mit] == objetivo) return mit;
	if(arr[mit] < objetivo) inicio = mit + 1;
	else fin = mit - 1;
	
	return busquedaBinariaRecursiva(arr, n, objetivo, inicio, fin);
}

//ordenamiento bubble
void bubbleSort(int arr[], int n){ //los arreglos se pasan por referencia
	int aux;
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j< n - i -1; j++){
			if(arr[j] > arr[j+1]){
				aux = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = aux;
			}
		}
	}
	//no retorna nada
}

//ordenamiento selección
void selectionSort(int arr[], int n){
	int min, minIdx;
	for(int i = 0; i<n-1; i++){
		min = arr[i];
		minIdx = i;
		for(int j = i+1; j < n; j++){ //cambia el inicio, se recorre hasta el final
			if(arr[j] < min){
				min = arr[j];
				minIdx = j;
			}
		}
		arr[minIdx] = arr[i];
		arr[i] = min;
	}
}

//ordenamiento por inserción
void insertionSort(int arr[], int n){
	int aux; //antes de empezar el bucle se guarda el numero en el auxiliar
	for(int i = 1; i < n; i++){
		int j = i-1;
		aux = arr[i];
		while(arr[j] > aux && j != -1){//el elemento en j sea mas grande que el del i, se repite el bucle, se usa auxiliar porque i cambia, condiciones de parada
		arr[j+1] = arr[j--]; // se está perdiendo la referencia, se debe guardar el número, j-- -> post decremento
		imprimirArreglo(arr, n); //para ver como se desplazan los elementos y como funciona el algoritmo
		// j--;
		}
		arr[j+1] = aux;
		imprimirArreglo(arr, n);
	}
}

//ordenamiento por mezcla

void merge(int arr[], int inicio, int mit, int fin){
	int i, j = 0, k = inicio;
	int n1 = mit - inicio + 1;
	int n2 = fin - mit;
	
	//se crea arreglo dinámico
	int *arrIzq = (int*) malloc(n1*sizeof(int)); //cantidad de elementos del arreglo en bytes, malloc retorna void(generico), se transforma a puntero de enteros con (int*)
	int *arrDer = (int*) malloc(n2*sizeof(int));
	//usamos for porque sabemos cuantas veces se va a repetir
	for(i = 0; i< n1; i++){
		arrIzq[i] = arr[inicio + i];
	}
	
	for(i = 0; i< n2; i++){
		arrDer[i] = arr[mit + i +1]; //se suma desde el inicio, son posiciones absolutas
	}
	
	i = 0; //inicio i, porque lo usé para mi bucle arriba
	
	while(i < n1 && j < n2){
		if(arrIzq[i] <= arrDer[j]){ //i para elementos izquierda, j para elementos derecha, k para los elementos del arreglo original
			arr[k] = arrIzq[i];
			i++;
		}else{
			arr[k] = arrDer[j];
			j++;
		}
		k++;  // se cumpla o no la condición, incrementa k
	}
	
	while(i < n1){ //si i aun no recorrió todos los elementos de la izquierda
		arr[k++] = arrIzq[i++]; //incrementa, post incremento.
	}
	while(j < n2){
		arr[k++] = arrDer[j++];
	}
	// al usar arreglos dinámicos, al final se libera la memoria
	free(arrIzq);
	free(arrDer);
}


void mergeSort(int arr[], int inicio, int fin){
	int mit = (inicio + fin) / 2;
	
	if(inicio >= fin) return;
	
	mergeSort(arr, inicio, mit);
	mergeSort(arr, mit + 1, fin);
	
	merge(arr, inicio, mit, fin);
}

//ordenamiento rapido
void intercambiar(int &a, int &b){ //paso por referencia
	int aux = a;
	a = b;
	b = aux;
}

int particionar(int arr[], int inicio, int fin){ //retorna la posición del pivote
	int pivote = arr[fin]; //el pivote es el elemento que está al final
	int i = inicio - 1; //elemento anterior
	
	for(int j = inicio; j < fin; j++){ //fin es la posición del pivote, recorrer los elementos hasta llegar al pivote
		if(arr[j] <= pivote) intercambiar(arr[++i], arr[j]); //preincremento, antes de i, se intercambia el elemento en i con el elemento en j
	}
	intercambiar(arr[++i], arr[fin]);
	imprimirArreglo(arr, fin - inicio + 1);
	return i; //posición donde quedó el pivote
}

void quickSort(int arr[], int inicio, int fin){
	int posPivote; // se declara la variable del pivote, abajo se define
	if(inicio >= fin) return;
	
	posPivote = particionar(arr, inicio, fin);
	
	quickSort(arr, inicio, posPivote - 1); //nunca se considera el pivote, arregla lado izq
	quickSort(arr, posPivote + 1, fin);
}
