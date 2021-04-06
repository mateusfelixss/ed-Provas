#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;


// Comandos para compilar e executar codigos por linhas de comando:
//     --> gcc (ou gpp) seucodigo.c -o seuprograma.
//     --> ./seuprograma

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << endl;
}

int main(){
    int n = 15;
    int vetor[n] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 33, 44, 0, -5};
    int m = 15;
    int vetor2[m] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 33, 44, 0, -5};
    
    cout << "Insertion Sort" << endl;
    printArray(vetor, n);

    insertionSort(vetor, n);

    printArray(vetor, n);

    cout << "Selection Sort" << endl;
    printArray(vetor2, m);

    selectionSort(vetor2, m);

    printArray(vetor2, m);
}