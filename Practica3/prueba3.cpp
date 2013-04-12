#include <iostream>
#include "Abin.h"
#include "ES_Abin.h"
#include "expresion.h"
#include "operaciones.h"
using namespace std;

int main()
{
	Abin<expresion> A;
	leerAbin(A);
	imprimirAbin(A);
	double res=calcularExp(A);
	cout << "Resultado: " << res << endl;
	return 0;	
}
