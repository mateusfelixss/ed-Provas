/**
 * Este arquivo esta finalizado, nao mexa nele
 */
#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main() 
{
	string line;
    getline(cin, line);
    Tree bt(line);
    cout << bt.bt_um_filho(); 
    if(bt.eh_avl()) 
        cout << " eh avl" << endl;
    else 
        cout << " nao eh avl" << endl;
    return 0;
}
