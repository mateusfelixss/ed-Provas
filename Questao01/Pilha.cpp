#include <string>
#include <sstream>
#include <queue>
#include <Pilha.h>
using namespace std;

queue<int> *fila;
queue<int> *filaAux;

Pilha:: Pilha(){
    queue<int> fila;
    queue<int> filaAux;
}

Pilha:: ~Pilha(){
    if(fila.empty() && filaAux.empty())
        delete fila;
        delete filaAux;
}

void Pilha::_pop(int value){

}