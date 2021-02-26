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
    clear();
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

//Remove elemento do final da lista e retorna seu valor.
int List:: popBack(){
    Node *aux = head;

    if(head == nullptr)
        return 0;

    if(aux == aux->prox){
        delete aux;
        return head->value;
        head = nullptr;
    }
    
    while(aux != head)
        aux = aux->prox;

    aux->anterior = head;
    head->anterior = aux->anterior;

    return aux->value;
    delete aux;

}

//Insere um novo nó com valor key apos o k-esimo no da lista.
void List:: insertAfter(int key, int k){

}


//Remove da lista a primeira ocorrencia do inteiro key
void List:: remove(int key){
    Node *noRemover = search(key);

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

    // if(!empty()){
    //     Node *aux = new Node;
    //     aux = head;

    //     if(head->value == key){
    //         if(head == head->prox){
    //             head = nullptr;
    //         }
    //         else{
    //             // head->anterior = head->prox;
    //             // head->prox = head->anterior;

    //             head = aux->prox;
    //             head->anterior = aux->anterior;
    //         }

    //         delete(aux);
    //     }
    // }
    // aux = aux->prox;

    // while(aux != head){
    //     if(aux->value == key){
    //         aux->anterior->prox = aux->prox;
    //         aux->prox->anterior = aux->anterior;
    //     }
    // }
    
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
       // cout < "Removendo " << head->value << endl;
        delete head;
        head = nullptr;
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

bool List:: contains(int key){
    return (search(key) != nullptr);
}