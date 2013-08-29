#include <iostream>
#include "Abin.h"
#include "ES_Abin.h"
#include "operaciones.h"
using namespace std;

int main()
{
	Abin<int> A,B;
	leerAbin(A);
	imprimirAbin(A);
	cout << "-----------------------FIN ARBOL A ------------------------" << endl;
	leerAbin(B);
	imprimirAbin(B);
	cout << "-----------------------FIN ARBOL B ------------------------" << endl;
	cout << AbinSimilares(A,B);
	return 0;	
}
