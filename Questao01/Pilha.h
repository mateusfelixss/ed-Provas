#ifndef PILHA_H
#define PILHA_H
#include <string>
#include <sstream>
#include <queue>

queue<int> fila2;
struct Node;

class Pilha {
public:
    Pilha();
    ~Pilha();
    void push();
    void pop();
    Pilha queue<int> fila;
    queue<int> *filaAux;
private:
    void _push(int valor);
    void _pop(int  valor);
    Node *_root;
    Node *_clear(Node *root);
    void _inorder(Node *node);
    void _bshow(Node *node, std::string heranca);
    void _serializeTree(std::stringstream& ss, Node **node);
    int _bt_um_filho(Node *node); // ---> Implementar essa funcao no arquivo .cpp
    bool eh_avl(Node *node); // ---> Implementar essa funcao no arquivo .cpp
    bool _empty(Node *node);  //funcao adicionada
};

#endif
