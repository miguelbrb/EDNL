#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
//#include "Abin_vec0.h"//Vectorial.Estático.
#include "Abin.h"//Enlazado.Dinámico.
#include "ES_Abin.h"

int main()
{
    //Abin<char> t(10);//Estático.
    Abin<char> t;//Dinámico.
    leerAbin(t);
    imprimirAbin(t);
    int m=t.altura(t.raizB());
    cout << "Altura del arbol: "<< m << endl;
    int p=t.profundidad(t.hijoDrchoB(t.hijoIzqdoB(t.raizB())));
    cout << "Profundidad del nodo "<< ": " << p << endl;
    return 0;
}
