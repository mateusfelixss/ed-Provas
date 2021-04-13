#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"

// Definicao do struct Node
// Em C++ os structs podem ter funcoes-membro, como 
// construtores, destrutores, etc.
struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

// Construtor
Tree::Tree(std::string serial) {
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

// Essa funcao recursiva recebe como entrada uma string contendo 
// uma versao serializada da arvore e recebe um ponteiro para ponteiro para o no raiz.
// A funcao ler os dados e constroi a arvore seguindo um percurso em pre-ordem.
void Tree::_serializeTree(std::stringstream& ss, Node **node) {
    std::string value;
    ss >> value;
    if(value == "#") // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

// Destrutor
Tree::~Tree() {
    _root = _clear(_root);
}

// Essa funcao recebe uma raiz chamada node e
// ela libera todos os nos decendentes de node e o proprio node.
Node *Tree::_clear(Node *node) {
    if(node != nullptr) { // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
    std::cout << std::endl;
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);  
    }
}

void Tree::bshow(){
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}





int Tree:: bt_um_filho(){
    return _bt_um_filho(_root);
}

bool Tree:: eh_avl(){
    return _eh_avl(_root);
}

int Tree::height() {
    return this->_height(_root) + 1;
}

bool Tree:: _empty(Node *node){
    return node == nullptr;
}

int Tree:: _bt_um_filho(Node *node){
    int cont = 0;
    if(_empty(node)){
        return 0;
    }
    else{
        if((node->left == nullptr && node->right != nullptr) ){
            cont += 1+_bt_um_filho(node->right);
            return  cont;
        }else if((node->left != nullptr && node->right == nullptr)){
            cont += 1+_bt_um_filho(node->left);
            return  cont;
        }
        else{
            return _bt_um_filho(node->left) + _bt_um_filho(node->right);
        }
    }
}

int Tree::_height(Node *node) {

    if(node == nullptr)
        return -1;

    else{
        int contL; 
        int contR;
        contL = 1 + _height(node->left);
        contR = 1 + _height(node->right);

        if(contL > contR)
            return contL;
        else
            return contR;
    }
}

bool Tree:: _eh_avl(Node *node){
	int esquerda;
    int direita;
	bool balanceada = true;
	if(node){
		balanceada = _eh_avl(node->left);
		if(balanceada) 
            balanceada = _eh_avl(node->right);
		if(balanceada){
			esquerda = _height(node->left);
			direita = _height(node->right);
			if(esquerda - direita > 1 || esquerda - direita < -1) 
                balanceada = false;  
			else 
                balanceada = true;
		}
	}
	return(balanceada);
}