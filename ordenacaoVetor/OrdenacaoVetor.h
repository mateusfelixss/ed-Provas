#ifndef ORDENAVETOR_H
#define ORDENAVETOR_H

// Aluna: Karine Ennalian Martins Laurindo  				Matrícula: 403160
// Aluno: Mateus Felix de Souza Silva					    Matrícula: 499053


class OrdenacaoVetor{
public:
    void swapSelection(int *xp, int *yp);

    void selectionSort(int arr[], int n); 

    void insertionSort(int arr[], int n); 

    void merge(int arr[], int left, int middle, int right);

    void mergeSort(int arr[],int left,int right); 

    void swapQuick(int* a, int* b);

    int partition (int arr[], int low, int high);

    void quickSort(int arr[], int low, int high); 

    int getNextGap(int gap);

    void combSort(int a[], int n); 

    void gera_dados(int num_iteracoes, const int vetor_tam[]);

    void ler_dados(int n, int A[], const char *nomeArquivo);

};
#endif