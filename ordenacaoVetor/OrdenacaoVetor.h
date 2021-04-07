#ifndef ORDENAVETOR_H
#define ORDENAVETOR_H

// Aluna: Karine Ennalian Martins Laurindo  				Matrícula: 403160
// Aluno: Mateus Felix de Souza Silva					    Matrícula: 499053


class OrdenacaoVetor{
public:
    void swapSelection(int *xp, int *yp);

    void selectionSort(int arr[], int n); //algoritmo OK

    void insertionSort(int arr[], int n); //algoritmo OK

    void merge(int arr[], int l, int m, int r);

    void mergeSort(int arr[],int l,int r); //algoritmo OK

    void swapQuick(int* a, int* b);

    int partition (int arr[], int low, int high);

    void quickSort(int arr[], int low, int high); //algoritmo OK

    void printArray(int arr[], int n);

    void gera_dados(int num_iteracoes, const int vetor_tam[]);

    void ler_dados(int n, int A[], const char *nomeArquivo);

};
#endif