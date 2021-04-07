#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include "OrdenacaoVetor.h"
using namespace std;

// Aluna: Karine Ennalian Martins Laurindo  				Matrícula: 403160
// Aluno: Mateus Felix de Souza Silva					    Matrícula: 499053


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