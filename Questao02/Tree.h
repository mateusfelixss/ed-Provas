#ifndef TREE_H
#define TREE_H
#include <string>
#include <sstream>

struct Node;

class Tree {
public:
    Tree(std::string serial);
    void inorder(); 
    void bshow();
    int bt_um_filho(); // ---> Implementar essa funcao no arquivo .cpp
    bool eh_avl(); // ---> Implementar essa funcao no arquivo .cpp
    int height(); //adicionada
    ~Tree();
private:
    Node *_root;
    Node *_clear(Node *root);
    void _inorder(Node *node);
    void _bshow(Node *node, std::string heranca);
    void _serializeTree(std::stringstream& ss, Node **node);
    int  _bt_um_filho(Node *node); // ---> Implementar essa funcao no arquivo .cpp
    bool _eh_avl(Node *node); // ---> Implementar essa funcao no arquivo .cpp
    bool _empty(Node *node); // adicionada
    int  _height(Node *node); //adicionada

};
#endif

