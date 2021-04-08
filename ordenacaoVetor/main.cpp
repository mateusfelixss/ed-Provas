#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include "OrdenacaoVetor.h"
using namespace std;

// Aluna: Karine Ennalian Martins Laurindo  				Matrícula: 403160
// Aluno: Mateus Felix de Souza Silva					    Matrícula: 499053



void  swapSelection(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void  selectionSort(int arr[], int n) 
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


void  insertionSort(int arr[], int n){
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


void  merge(int arr[], int left, int middle, int right)
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
 

void  mergeSort(int arr[],int left,int right){
    if(left >= right){
        return;
    }
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr,middle + 1, right);
    merge(arr, left, middle, right);
}

void  swapQuick(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int  partition (int arr[], int low, int high){
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
 

void  quickSort(int arr[], int low, int high){
    if (low < high){
    
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int getNextGap(int gap){

    gap = (gap * 10) / 13;
 
    if (gap < 1)
        return 1;
    return gap;
}
 

void  combSort(int a[], int n){
    
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


void  gera_dados(int num_iteracoes, const int vetor_tam[]) 
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
void ler_dados(int n, int A[], const char *nomeArquivo) 
{	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++) 
	{
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor A
	}
	fin.close(); // fecha o arquivo de leitura
}



int main() 
{ 
	// Os tamanhos dos vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {500,1000,2000,3000,4000,5000,6000,7000,8000,9000,
	10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000};
	
	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'
	
	// Etapa 1: Gerar arquivos contendo numeros aleatorios
	// Os arquivos sao gerados e salvos na pasta dados
	gera_dados(TOTAL_N, tam);
	
	// ------------------------------------------------------------
	// Etapa 2 - Execucao do CocktailSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs("resultados/resultadoSelectionSort.txt", std::ofstream::out ); // abre arquivo de resultados do selectionShort
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_selectionSort = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// SelectionSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
//mudei essa chamada da funcao		
			selectionSort(vetor, tamanho_vetor); // ordena o vetor usando o selectionSort
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_selectionSort = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_selectionSort += duracao_selectionSort;
			
		}
		
		duracao_media_selectionSort = duracao_media_selectionSort / 5.0;
		cout << "[selectionSort] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selectionSort << " microssegundos" << endl;
		ofs << tamanho_vetor << " " << duracao_media_selectionSort << "\n"; // grava no arquivo de resultados do selectionSort
	}
	
	ofs.close(); // fecha arquivo de resultados do selectionSort
	// ------------------------------------------------------------
	
	

	
	// ------------------------------------------------------------
	// Etapa 3 - Execução do insertionSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs2("resultados/resultadoInsertionSort.txt", std::ofstream::out ); // abre arquivo de resultados do insertionSort
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_insertionSort = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o insertionSort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// insertionSort ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = std::chrono::high_resolution_clock::now();
		
			insertionSort(vetor, tamanho_vetor); // ordena o vetor usando o insertionSort
		
			// obtendo o tempo final
			auto fim2 = std::chrono::high_resolution_clock::now();
		
			// obtendo a duracao total da ordenacao
			auto duracao_insertionSort = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_insertionSort += duracao_insertionSort;			
		}	
		
		duracao_media_insertionSort = duracao_media_insertionSort / 5.0;
		cout << "[insertionSort] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertionSort << " microssegundos" << endl;
		ofs2 << tamanho_vetor << " " << duracao_media_insertionSort << "\n"; // grava no arquivo de resultados do insertionSort
	}
	
	ofs2.close(); // fecha arquivo de resultados do insertionSort
	// ------------------------------------------------------------




	// ------------------------------------------------------------
	// Etapa 4 - Execução do mergeSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs3("resultados/resultadoMergeSort.txt", std::ofstream::out ); // abre arquivo de resultados do insertionSort
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_mergeSort = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o mergeSort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// mergeSort ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = std::chrono::high_resolution_clock::now();
		
			mergeSort(vetor, 0, TOTAL_N); // ordena o vetor usando o mergeSort
		
			// obtendo o tempo final
			auto fim2 = std::chrono::high_resolution_clock::now();
		
			// obtendo a duracao total da ordenacao
			auto duracao_mergeSort = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_mergeSort += duracao_mergeSort;			
		}	
		
		duracao_media_mergeSort = duracao_media_mergeSort / 5.0;
		cout << "[mergeSort] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_mergeSort << " microssegundos" << endl;
		ofs3 << tamanho_vetor << " " << duracao_media_mergeSort << "\n"; // grava no arquivo de resultados do mergeSort
	}
	
	ofs3.close(); // fecha arquivo de resultados do mergeSort
	// ------------------------------------------------------------




	// ------------------------------------------------------------
	// Etapa 4 - Execução do quickSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs4("resultados/resultadoQuickSort.txt", std::ofstream::out ); // abre arquivo de resultados do insertionSort
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_quickSort = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o quickSort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// quickSort ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = std::chrono::high_resolution_clock::now();
		
			quickSort(vetor, 0, TOTAL_N); // ordena o vetor usando o quickSort
		
			// obtendo o tempo final
			auto fim2 = std::chrono::high_resolution_clock::now();
		
			// obtendo a duracao total da ordenacao
			auto duracao_quickSort = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_quickSort += duracao_quickSort;			
		}	
		
		duracao_media_quickSort = duracao_media_quickSort / 5.0;
		cout << "[quickSort] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_quickSort << " microssegundos" << endl;
		ofs4 << tamanho_vetor << " " << duracao_media_quickSort << "\n"; // grava no arquivo de resultados do quickSort
	}
	
	ofs4.close(); // fecha arquivo de resultados do quickSort
	// ------------------------------------------------------------




// ------------------------------------------------------------
	// Etapa 2 - Execucao do combSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs5("resultados/resultadoCombSort.txt", std::ofstream::out ); // abre arquivo de resultados do selectionShort
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_combSort = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// combSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			combSort(vetor, tamanho_vetor); // ordena o vetor usando o combSort
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_combSort = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_combSort += duracao_combSort;
			
		}
		
		duracao_media_combSort = duracao_media_combSort / 5.0;
		cout << "[combSort] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_combSort << " microssegundos" << endl;
		ofs << tamanho_vetor << " " << duracao_media_combSort << "\n"; // grava no arquivo de resultados do combSort
	}
	
	ofs5.close(); // fecha arquivo de resultados do combSort
	// ------------------------------------------------------------	

	return 0;
}