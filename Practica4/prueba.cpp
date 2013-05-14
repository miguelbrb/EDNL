#include <iostream>
#include "Agen.h"
#include "ES_Agen.h"
#include "operaciones.h"
#include <algorithm>
using namespace std;

int main()
{
	Agen<char> t;
	leerAgen(t);
	imprimirAgen(t);
	cout << "Grado del arbol: " << gradoAgen(t) << endl;
	cout << "Desequilibrio: " << desequilibrioAgen(t) << endl;
}
