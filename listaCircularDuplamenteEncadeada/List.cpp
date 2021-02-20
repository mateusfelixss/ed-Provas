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

struct Node *primeiro;
struct Node *ultimo;
// Node *primeiro = new Node;
// Node *ultimo = new Node;

//acho que esse construtor tem algum problema, mas eu ainda nao sei qual

List:: List(){
    Node *primeiro = new Node;
    //lista->primeiro = nullptr;

    primeiro->value = 0;
    primeiro->prox = nullptr;
    primeiro->anterior = nullptr;
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
        primeiro = novo;
    }
    else{
        Node *aux = new Node;
        while(aux->prox != primeiro){
            aux = aux->prox;
        }
        primeiro->anterior = novo;
        aux->prox = novo;
        novo->anterior = aux;
        novo->prox = primeiro;

        novo->prox = primeiro;
        novo->anterior = aux;
        aux->prox = novo;
        primeiro->anterior = novo;
    }
}

//Imprime os elementos da lista.
//esta funcao esta com problema, alguma coisa relacionada com "primeiro"
void List:: print(){
    Node *aux = new Node;
    aux = primeiro;

    do{
        cout << aux->value << " ";
        aux = aux->prox;
    }while(aux =! primeiro);
}

//Imprime os elementos da lista em ordem reversa.
//esta funcao esta com problema, alguma coisa relacionada com "primeiro"
void List:: printReverse(){
    Node *aux = new Node;
    aux = primeiro;

    do{
        cout << aux->value << " ";
        aux = aux->anterior;
    }while(aux =! primeiro);
}

//Retorna true se a lista estiver vazia e false caso contrario.
bool List:: empty(){
    return primeiro == nullptr;
}
