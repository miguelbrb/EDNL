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
    int m=altura(t);
    cout << "Altura del arbol: "<< m << endl;
    int p=profundidad(t,t.hijoDrchoB(t.hijoIzqdoB(t.raizB())));    
    cout << "Profundidad del nodo "<< ": " << p << endl;
    return 0;
}
