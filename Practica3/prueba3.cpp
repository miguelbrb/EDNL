#include <iostream>
#include "Abin.h"
#include "ES_Abin.h"
#include "expresion.h"
using namespace std;

int main()
{
	Abin<expresion> A;
	leerAbin(A);
	imprimirAbin(A);
	return 0;	
}
