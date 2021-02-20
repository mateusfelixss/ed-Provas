#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include "List.h"
using namespace std;

int main(){
    //Node *lista = new Node;

    List *lista;

    lista->pushBack(1);
    lista->pushBack(2);
    lista->pushBack(3);
    lista->pushBack(4);
    lista->pushBack(5);

    lista->print();
    cout << endl << "--------------------" << endl;

    lista->printReverse();
}