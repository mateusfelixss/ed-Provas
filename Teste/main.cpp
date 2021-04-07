#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;


// Comandos para compilar e executar codigos por linhas de comando:
//     --> gcc (ou gpp) seucodigo.c -o seuprograma.
//     --> ./seuprograma

void swapSelection(int *xp, int *yp) 
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
  
        // SwapSelection the found minimum element with the first element 
        swapSelection(&arr[min_idx], &arr[i]); 
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


void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void swapQuick(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swapQuick(&arr[i], &arr[j]);
        }
    }
    swapQuick(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;
 
    if (gap < 1)
        return 1;
    return gap;
}
 
// Function to sort a[0..n-1] using Comb Sort
void combSort(int a[], int n)
{
    // Initialize gap
    int gap = n;
 
    // Initialize swapped as true to make sure that
    // loop runs
    bool swapped = true;
 
    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = getNextGap(gap);
 
        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;
 
        // Compare all elements with current gap
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
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
    
    int valor = 20;
    int vetor3[valor] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 33, 44, 0, -5, 2, 11, 12, 5, 7};
    int arr_size = sizeof(vetor3) / sizeof(vetor3[0]);
    
    int valor2 = 15;
    int vetor4[valor2] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 33, 44, 0, -5};
    int valor4 = 20;
    int vetor5[valor4] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 33, 44, 0, -5, 2, 11, 12, 5, 7};
    int arr_size2 = sizeof(vetor5) / sizeof(vetor5[0]);
    int arr_size3 = sizeof(vetor4) / sizeof(vetor4[0]);

    int qtd1 = 15;
    int vetorCombo1[qtd1] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 33, 44, 0, -5};
    int qtd2 = 20;
    int vetorCombo2[qtd2] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 20, 33, 44, 0, -5, 2, 11, 12, 5, 7};

    cout << "Insertion Sort" << endl;
    printArray(vetor, n);

    insertionSort(vetor, n);

    printArray(vetor, n);

    cout << "Selection Sort" << endl;
    printArray(vetor2, m);

    selectionSort(vetor2, m);

    printArray(vetor2, m);

//quando o vetor tem algoritmo repetido, faz aluns elementos sumirem ERRRRRRO
    cout << "Merge Sort" << endl;
    printArray(vetor3, valor);

    mergeSort(vetor3, 0, arr_size);

    printArray(vetor3, valor);

    cout << "vetor3: "<< sizeof(vetor3) << endl;
    cout << "vetor3[0]: "<< sizeof(vetor3[0]) << endl;



//Funcionando de boinha

    cout << "Quick Sort" << endl;
    printArray(vetor4, valor2);

    quickSort(vetor4, 0, arr_size3 - 1);

    printArray(vetor4, valor2);

    cout << "Segundo Round do Quick Sort" << endl;

    printArray(vetor5, valor4);

    quickSort(vetor5, 0, arr_size2 - 1);

    printArray(vetor5, valor4);


//ComboSort
    cout << "Combo Sort" << endl;
    printArray(vetorCombo1, qtd1);

    combSort(vetorCombo1, qtd1);

    printArray(vetorCombo1, qtd1);

    cout << "Segundo Round do Combo Sort" << endl;

    printArray(vetorCombo2, qtd2);

    combSort(vetorCombo2, qtd2);

    printArray(vetorCombo2, qtd2);
}