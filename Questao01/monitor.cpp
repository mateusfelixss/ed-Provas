#include<iostream>
#include<queue>

using namespace std;

void popRemove(queue<int> filaPrincipal, queue<int> filaAX){
    while(!filaPrincipal.empty()){
        while(filaPrincipal.size() > 1){
            filaAX.push(filaPrincipal.front());
            filaPrincipal.pop();
        }
        cout<<"saiu: "<< filaPrincipal.front()<<"\n";
            filaPrincipal.pop();
            while(!filaAX.empty()){
                filaPrincipal.push(filaAX.front());
                filaAX.pop();
            }
    }
}

void pushAdd(queue<int> filaPrincipal, int x ){
    filaPrincipal.push(x);
}



int main(){
    queue<int> fila;
    queue<int> aux;
    //int n = 0;
   //

    // 1 2 3 4
    fila.push(1);
    fila.push(2);
    fila.push(3);
    fila.push(4);
    
    // pushAdd(fila, 1);
    // pushAdd(fila, 2);
    // pushAdd(fila, 3);
    // pushAdd(fila, 4);
    // pushAdd(fila, 5);
    for(int i = 0; i < fila.size(); i++){
        cout << fila.front() << endl;
    }
    //popRemove(fila, aux);
    // while(!fila.empty()){
    //     //coloco na auxiliar 
    //   //  popRemove(fila, aux);
    //     while(fila.size() > 1){
    //         aux.push(fila.front());
    //         fila.pop();
    //     }

    //     cout<<"saiu: "<< fila.front()<<"\n";
    //     fila.pop();
    //     while(!aux.empty()){
    //         fila.push(aux.front());
    //         aux.pop();
    //     }

    // }
    return 0;
}


// Verifica se árvore é AVL
bool ehAVL(PONT p){
	int e,d;
	bool ok = true;
	if(p){
		ok = ehAVL(p->esq);
		if(ok) 
            ok = ehAVL(p->dir);
		if(ok){
			e = altura(p->esq);
			d = altura(p->dir);
			if(e-d > 1 || e-d < -1) 
                ok = false;  
			else 
                ok = true;
		}
	}
	return(ok);
}