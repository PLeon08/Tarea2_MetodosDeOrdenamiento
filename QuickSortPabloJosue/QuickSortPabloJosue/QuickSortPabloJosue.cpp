#include<iostream> 
using namespace std;
#include <stdio.h>
// intercambia dos elementos 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// pdivide usando el ultimo elemento como pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        //si el elemento actual es mas pequeño que el pivot, incrementar el elemento
        //intercambiar i y j
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//QuickSort metodo principal
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //pdivide el arreglo
        int pivot = partition(arr, low, high);

        //ordena independientemente cada mitad
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
} 

void mostrarArreglo(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<"\t";
     
}

int main()
{
    int arreglo[] = { 10,8,21,15,33,44,23,35,37,11,24,43,41,39,2,9,3,99,55,49,86,77,67 };
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    
    printf("Este es el arreglo sin ordenar.\n") ;
    mostrarArreglo(arreglo, n);
    quickSort(arreglo, 0, n - 1);
    printf("\nEste es el arreglo ordenado por el metodo QuickSort.\n");
    mostrarArreglo(arreglo, n);

    return 0;
}