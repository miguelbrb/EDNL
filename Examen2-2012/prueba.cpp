#include "Abin.h"
#include <iostream>
#include "ES_Abin.h"
#include "examen.h"
using namespace std;

int main()
{
	Abin<int> t;
	leerAbin(t);
	imprimirAbin(t);
	if(AbinEsAbb(t)) cout << "Es un Abb." << endl;
	else cout << "No es un Abb." << endl;
}
