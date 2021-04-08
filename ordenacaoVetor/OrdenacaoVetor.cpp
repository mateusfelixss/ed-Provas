#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include "OrdenacaoVetor.h"
using namespace std;

// Aluna: Karine Ennalian Martins Laurindo  				Matrícula: 403160
// Aluno: Mateus Felix de Souza Silva					    Matrícula: 499053

void OrdenacaoVetor:: swapSelection(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void OrdenacaoVetor:: selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < n-1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swapSelection(&arr[min_idx], &arr[i]); 
    } 
}


void OrdenacaoVetor:: insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void OrdenacaoVetor:: merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
 

    int L[n1], R[n2];
 

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
 
 
    int i = 0;

    int j = 0;

    int k = left;
 
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
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void OrdenacaoVetor:: mergeSort(int arr[],int left,int right){
    if(left >= right){
        return;
    }
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr,middle + 1, right);
    merge(arr, left, middle, right);
}

void OrdenacaoVetor:: swapQuick(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int OrdenacaoVetor:: partition (int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++){

        if (arr[j] < pivot){
            swapQuick(&arr[i], &arr[j]);
        }
    }
    swapQuick(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void OrdenacaoVetor:: quickSort(int arr[], int low, int high){
    if (low < high){
    
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int OrdenacaoVetor:: getNextGap(int gap){

    gap = (gap * 10) / 13;
 
    if (gap < 1)
        return 1;
    return gap;
}
 
//algoritmo de ordenao: comboSort
void OrdenacaoVetor:: combSort(int a[], int n){
    
    int gap = n;

    bool swapped = true;
 
    while (gap != 1 || swapped == true){
         
        gap = getNextGap(gap);
 
        swapped = false;
 
        for (int i = 0; i < n - gap; i++){
            if (a[i] > a[i + gap]){
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}


void OrdenacaoVetor:: gera_dados(int num_iteracoes, const int vetor_tam[]) 
{
	for(int n = 0; n < num_iteracoes; n++) {
		// para cada tamanho n, sao gerados 5 vetores de tamanho n aleatorios
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "dados/random"+std::to_string(n)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[n];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); // gera numero aleatorio
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

// ------------------------------------------------------------------

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binario de mesmo nome que a 
 * string nomeArquivo
 */
void OrdenacaoVetor:: ler_dados(int n, int A[], const char *nomeArquivo) 
{	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++) 
	{
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor A
	}
	fin.close(); // fecha o arquivo de leitura
}