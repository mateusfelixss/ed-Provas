#include <iostream>
#include <string>
#include <climits>
#include <stdlib.h>
#include "List.h"
using namespace std;


// Aluna: Karine Ennalian Martins Laurindo  				Matrícula: 403160
// Aluno: Mateus Felix de Souza Silva					Matrícula: 499053

struct Node {
    int value;
    Node *prox;
    Node *anterior;
};

List:: List(){
    head = nullptr;
}

List:: ~List(){
    clear();
    delete head;
}

//Insere um inteiro key ao final da lista.
void List:: pushBack(int key){
    Node *novo = new Node;
    novo->value = key;

    //verifica se possui algum elemento na lista
    if(empty()){
        novo->prox = novo;      //caso a lista seja vazia, é adicionado um novo elemento
        novo->anterior = novo;
        head = novo;
    }
    else{  //caso nao esteja vazia a lista 
        Node *aux = new Node;
        while(aux->prox != head){   //busca para encontrar o ultimo elemento da lista
            aux = aux->prox;
        }
        //ajuste de ponteiros
        head->anterior = novo;
        aux->prox = novo;
        novo->anterior = aux;
        novo->prox = head;
    }
}

//Remove elemento do final da lista e retorna seu valor.
int List:: popBack(){
    Node *aux = head;
    //verifica se a lista é vazia
    if(head == nullptr)
        return 0;

    //verifica se o elemento a ser removido é o unico da lista, caso seja, ele é removido e retorna o seu value
    if(aux == aux->prox){
        return head->value;
        delete aux;
        head = nullptr;
    }
    
    //percorre a lista até antes da head
    while(aux != head)
        aux = aux->prox;

    //ajuste de ponteiros
    aux->anterior = head;
    head->anterior = aux->anterior;

    return aux->value;
    delete aux;

}

//Insere um novo nó com valor key apos o k-esimo no da lista.
void List:: insertAfter(int key, int k){

    
    //verifica se a lista é vazia
    if(head == nullptr){
        cout << "Lista vazia";
        return;
    }

    else if(size() > k){
        Node *novo = new Node;
        novo->value = key;
        Node *aux = head;

        while(0 < k){
            aux = aux->prox;
            k--;
        }
        //ajuste de ponteiro
        aux->prox = novo;
        novo->anterior = aux;
        novo->prox = aux->prox->prox;
        aux->prox->prox->anterior = novo;

        cout << "Adicionado com sucesso";
    }else{
        cout << "Posicao k nao esta na lista";
    }    
}


//Remove da lista a primeira ocorrencia do inteiro key
void List:: remove(int key){
    Node *noRemover = search(key);  //busca na lista o elemento que deseja remover

    if(noRemover == nullptr)
        return;
   
    if(noRemover == noRemover->prox){
        delete noRemover;
        head = nullptr;
        return;
    }    
    //percorrer a lista ate achar o antecessor do no
    Node *aux = noRemover;
    while(aux->prox != noRemover)
        aux = aux->prox;
    
    //ajusta os ponteiros
    aux->prox = noRemover->prox;
    noRemover->prox->anterior = aux;

    //se o no a ser removido for o head
    if(head == noRemover)
        head = noRemover->prox;
    
    delete noRemover;    
}

//Remove da lista todas as ocorrencias do inteiro key.
void List:: removeAll(int key){
    while(contains(key))
        remove(key);
}

//Remove todos os elementos da lista e deixa apenas o nó cabeça.
void List:: clear(){
    if(head != nullptr){
        Node *aux = head->prox;
        while(aux != head){         
            Node *aux2 = aux;
            aux = aux->prox;
            cout << "Removendo " << aux2->value << endl;
            delete aux2;
        }
       
        delete head;
        head = nullptr;
    }
}


//Imprime os elementos da lista.
//esta funcao esta com problema, alguma coisa relacionada com "primeiro"
void List:: print(){
    //caso nao tenha nenhum elemento na lista, nada é retornado.
    if(head == nullptr)
        return;
    
    Node *aux = new Node;
    aux = head;
    do{
        cout << aux->value << " ";
        aux = aux->prox;
    }while(aux != head);
}

//Imprime os elementos da lista em ordem reversa.
//esta funcao esta com problema, alguma coisa relacionada com "primeiro"
void List:: printReverse(){
    if(head == nullptr)
        return;
    
    Node *aux = new Node;
    aux = head;
    do{
        cout << aux->value << " ";
        aux = aux->anterior;
    }while(aux != head);

}
//Retorna true se a lista estiver vazia e false caso contrario.
bool List:: empty(){
    return head == nullptr;
}

Node *List :: search( int x ){
    if(head == nullptr)
        return nullptr;
    Node *aux = head;
    do{
        if(aux->value == x)
            return aux;
        aux = aux->prox;
    }while(aux != head);
        return nullptr;
}

//Retorna o numero de nós da lista.
int List:: size(){
    if(head == nullptr)
        return 0;
    Node *aux = head->prox;
    int cont = 1;
    while(aux != head){
        cont++;
        aux = aux->prox;
    }

    return cont;
}

//essa funcao retorna todas as ocorrencias do value key passado como paramentro
bool List:: contains(int key){
    return (search(key) != nullptr);
}