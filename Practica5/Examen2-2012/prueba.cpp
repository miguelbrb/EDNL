#include "Abin.h"
#include <iostream>
#include "ES_Abin.h"
using namespace std;

int main()
{
	Abin<int> t;
	leerAbin(t);
	imprimirAbin(t);
	cout << AbinEsAbb(t) << endl;
}
