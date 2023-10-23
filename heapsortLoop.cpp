#include <iostream>
using namespace std;

/* Función que ejecuta el intercambio de datos
   entre dos posiciones de un Arreglo.         */
void swap(int* A, int a, int b){
    if( a != b ){
        int temp = A[a];
        A[a] = A[b];
        A[b] = temp;
    }
}

/*
  Función para mostrar el contenido de un arreglo de enteros
*/
void show_array(int* A, int n){
    //Se abre un bracket para el arreglo
    cout << "[ ";
    //Se recorre el arreglo
    for(int i = 0; i < n; i++)
        //Se imprime la posición actual seguida de un espacio
        cout << A[i] << " ";
    //Se cierra el bracket del arreglo
    cout << "]\n";
}

/*
  Funciones para ordenar un arreglo de enteros utilizando el
  Heapsort
*/
//Función para obtener, dado el índice de un nodo, el índice de su padre
int parent(int i){
    return (i-1)/2; //El floor se ejecuta automáticamente por devolverse como int
}

//Función para obtener, dado el índice de un nodo, el índice de su hijo izquierdo
int left(int i){
    return 2*i + 1;
}

//Función para obtener, dado el índice de un nodo, el índice de su hijo derecho
int right(int i){
    return 2*i + 2;
}

//Función que, si la relación entre un nodo y sus hijos no cumple las especificaciones
//de un montículo   de máximos, corrige la situación poniendo como padre al dato más
//grande de los tres


void max_heapify(int* A, int i, int heap_size){
    while (true) {
        int largest, temp;

        int l = left(i);
        int r = right(i);   

        if( l < heap_size && A[l] > A[i] )
            largest = l;
        else
            largest = i;

        if( r < heap_size && A[r] > A[largest] )
            largest = r;

        if( largest != i ){
            swap(A, i, largest);
        } else break;

        i = largest;
    }
}

//Función que transforma el contenido de un arreglo en un montículo
//En este caso se trabaja con un montículo de máximos
void build_max_heap(int* A, int heap_size){
    //Se corrige el contenido del arreglo para que cumpla las propiedades de un montículo de máximos
    //Se trabaja desde la mitad del arreglo en reversa, ya que la segunda mitad son las hojas del montículo
    //(lo anterior es una propiedad demostrable, si el lector está interesado puede consultarlo con el docente)
    for(int i = heap_size/2-1; i >= 0; i--) //El floor se ejecuta automáticamente por almacenarse en un int
        max_heapify(A, i, heap_size);
}

//Algoritmo que realiza el proceso de ordenamiento
void heapsort(int* A, int n){
    //Tamaño inicial del montículo es la longitud del arreglo
    int heap_size = n;

    //Se transforma el arreglo en un montículo de máximos
    build_max_heap(A, heap_size);
    cout << "After max_heap: ";
    show_array(A, heap_size); cout << "\n";

    //Se hace un recorrido en reversa, para ir colocando los datos más grande hacia el final
    for(int i = n-1; i > 0; i--){
        //El dato en la raíz del montículo es el más grande de todos, por lo que se manda al final
        swap(A, 0, i);

        //Se reduce el tamaño del montículo en 1, ya que el dato del final actual ya está ordenado
        heap_size--;

        //Se corrige el montículo antes de proceder
        max_heapify(A, 0, heap_size);
    }
}

int main(void){
    //Arreglo de prueba
    int size = 8, A[size] = {5, 2,4,6,1,3,9,7};

    cout << "Arreglo antes de ordenar: ";
    show_array(A,size); cout << "\n";

    //Se ejecuta el ordenamiento
    heapsort(A,size);
    
    cout << "Arreglo después de ordenar: ";
    show_array(A,size);

    return 0;
}