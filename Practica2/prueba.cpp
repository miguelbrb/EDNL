#include <iostream>
#include <algorithm>
using namespace std;
#include "Abin.h"
#include "ES_Abin.h"
#include "operabin.h"

int main()
{
    Abin<char> t;
    leerAbin(t);
    imprimirAbin(t);
    int n=numero_nodos(t);
    cout << "Numero de nodos: " << n << endl;
    int h=altura(t);
    cout << "Altura del arbol: "<< h << endl;
    int p=profundidad(t,t.hijoDrchoB(t.hijoIzqdoB(t.raizB())));    
    cout << "Profundidad del nodo: " << p << endl;
    int d=desequilibrio(t);
    cout << "Desequilibrio del arbol:" << d << endl;
    if(pseudocompleto(t)){ cout << "Arbol pseudocompleto." << endl; }
    else{ cout << "Arbol no pseudocompleto." << endl; }
    return 0;
}
