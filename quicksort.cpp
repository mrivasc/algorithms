#include <iostream>
#include <climits>

using namespace std;
/*
  Función para mostrar el contenido de un arreglo de enteros
*/
void show_array(int* A, int n){
    cout << "[ ";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "]\n";
}

//{1,3,5,6,7,9};
//Función que calcula el punto de partición en el arreglo
int partition(int* A, int p, int r){
    int temp;

    //Se toma como pivote el último dato
    int pivot = A[r];

    //Se toma como primera posición de referencia una antes
    //del primer dato
    int i = p-1; //-1

    //Desde el inicio y hasta la penúltima posición
    for(int j = p; j < r; ++j) //3
        if(A[j] <= pivot){
            ++i; //0
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    
    //Se mueve el pivote a su nueva posición (a la derecha de la última posición de referencia)
    temp = A[r];
    A[r] = A[i+1];
    A[i+1] = temp;

    //Se retorna la posición a la derecha de la última referencia como el punto de corte
    cout << "i: " << i << endl;
    return i+1;
}
        
void quicksort(int* A, int p, int r){
    //Si p == r, solo hay un dato.
    //Si p > r, es un arreglo no válido.
    if(p < r){
        //Se calcula el punto de corte
        int q = partition(A, p, r);

        //Se ordena la mitad izquierda
        quicksort(A, p, q-1);
        
        //Se ordena la mitad derecha
        quicksort(A, q+1, r);
    }
}

int main(void){
    int size = 8, A[size] = {8,7,6,5,4,3,2,1};
    cout << "Arreglo antes de ordenar: ";
    show_array(A,size);

    //Se ejecuta el ordenamiento
    quicksort(A,0,size-1);
    
    cout << "Arreglo después de ordenar: ";
    show_array(A,size);

    return 0;
}