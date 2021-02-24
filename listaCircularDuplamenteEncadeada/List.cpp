#include <iostream>
#include <string>
#include <climits>
#include <stdlib.h>
#include "List.h"
//#include "LISTCIRC2_H"
using namespace std;


struct Node {
    int value;
    Node *prox;
    Node *anterior;
};
struct Node *inicio;
Node *fim;


// Node *primeiro = new Node;
// Node *ultimo = new Node;

//acho que esse construtor tem algum problema, mas eu ainda nao sei qual

List:: List(){
    head = nullptr;


    // Node *novo = new Node;
    // novo->value = value;
    // novo->prox = novo;
    // novo->anterior = novo;

    // return novo;
}

List:: ~List(){
    
}

//Insere um inteiro key ao final da lista.
void List:: pushBack(int key){
    Node *novo = new Node;
    novo->value = key;

    // ultimo->prox = novo;
    // novo->prox = ultimo;
    // novo->prox = nullptr;
    // ultimo = ultimo->prox;
    // novo = nullptr;

    if(empty()){
        novo->prox = novo;
        novo->anterior = novo;
        head = novo;
    }
    else{
        Node *aux = new Node;
        while(aux->prox != head){
            aux = aux->prox;
        }
        head->anterior = novo;
        aux->prox = novo;
        novo->anterior = aux;
        novo->prox = head;
    }
}


//Remove da lista a primeira ocorrencia do inteiro key
void List:: remove(int key){
    if(!empty()){
        Node *aux = new Node;
        aux = head;

        if(head->value == key){
            if(head == head->prox){
                head = nullptr;
            }
            else{
                // head->anterior = head->prox;
                // head->prox = head->anterior;

                head = aux->prox;
                head->anterior = aux->anterior;
            }

            delete(aux);
        }
    }
    aux = aux->prox;

    while(aux != head){
        if(aux->value == key){
            aux->anterior->prox = aux->prox;
            aux->prox->anterior = aux->anterior;
        }
    }

    
        


    
}

//Imprime os elementos da lista.
//esta funcao esta com problema, alguma coisa relacionada com "primeiro"
void List:: print(){
    
    if(head == nullptr)
        return;
    
    Node *aux = new Node;
    aux = head;
    do{
        cout << aux->value << " ";
        aux = aux->prox;
    }while(aux =! head);
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
    }while(aux =! head);


//Retorna true se a lista estiver vazia e false caso contrario.
bool List:: empty(){
    return head == nullptr;
}
