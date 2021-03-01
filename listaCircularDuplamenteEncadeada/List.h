#ifndef LISTCIRC2_H
#define LISTCIRC2_H

// Aluna: Karine Ennalian Martins Laurindo  				Matrícula: 403160
// Aluno: Mateus Felix de Souza Silva					Matrícula: 499053s

struct Node;

class List{
public:
    //Construtor da classe. Deve iniciar todos os atributos da classe com valores validos
    List(); 

    //Destrutor da classe. Libera memoria previamente alocada.
    ~List();

    //Insere um inteiro key ao final da lista.
    void pushBack(int key);

    //Remove elemento do final da lista e retorna seu valor.
    int popBack();

    //Insere um novo nó com valor key apos o k-esimo no da lista.
    void insertAfter(int key, int k);

    //Remove da lista a primeira ocorrencia do inteiro key
    void remove(int key); 

    //Remove da lista todas as ocorrencias do inteiro key.
    void removeAll(int key);

    //Imprime os elementos da lista.
    void print();

    //Imprime os elementos da lista em ordem reversa.
    void printReverse();

    //Retorna true se a lista estiver vazia e false caso contrario.
    bool empty();

    //Retorna o numero de nós da lista.
    int size(); 

    //Remove todos os elementos da lista e deixa apenas o nó cabeça.
    void clear(); 

    //funcao auxiliar
    bool contains(int key);


    //Concatena a lista atual com a lista lst passada por parametro. Apos essa operaçao ser executada, 
    //lst sera uma lista vazia, ou seja, o unico nó de lst sera o no cabeça.
    void concat(List *lst); 

    //Retorna um ponteiro para uma copia desta lista.
    List *copy(); 

    //Copia os elementos do array arr para a lista. O array arr tem n elementos. Todos os elementos anteriores da lista sao
    //mantidos e os elementos do array arr devem ser adicionados apos os elementos originais.
    void copyArray(int n, int arr[]);


    //Determina se a lista passada por parametro e igual a lista em questao.
    //Duas listas sao iguais se elas possuem o mesmo tamanho e o valor do k-´esimo elemento da primeira lista é igual ao k-esimo elemento da segunda lista.
    bool equal(List *lst);

private:
    Node *head;
    Node *search(int x);
};
#endif