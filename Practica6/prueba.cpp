#include "Apo.h"
#include <iostream>

using namespace std;

int main()
{
	int tam = 10;
	Apo<int> a(tam);
	for(int i=0;i<tam;i++)
	{
		cout << "introduce " << i << endl;
		a.insertarminmax(i);
		a.imprimir();
	}
}
