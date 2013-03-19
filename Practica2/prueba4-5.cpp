#include <iostream>
#include <algorithm>
using namespace std;
#include "Abin_vec0.h"
#include "ES_Abin.h"

int main()
{
    Abin<char> t;
    leerAbin(t);
    imprimirAbin(t);
    int m=t.altura();
    cout << "Altura del arbol: "<< m << endl;
    int p=t.profundidad(t.hijoDrchoB(t.hijoIzqdoB(t.raizB())));    
    cout << "Profundidad del nodo "<< ": " << p << endl;
    return 0;
}
