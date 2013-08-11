#include <iostream>
#include "Abin.h"
#include "ES_Abin.h"
#include "ejercicio1_P6.h"
using namespace std;

int main(){
	Abin<int> a;
	int x;
	leerAbin(a);
	cout<<"------------------Fin Arbol------------------"<<endl<<endl;
	imprimirAbin(a);
	cout<<"Introduzca elemento a eliminar:"<<endl;
	cin>>x;
	eliminarElemAbin(a,x);
	imprimirAbin(a);
	cout<<"------------------Fin Arbol------------------"<<endl;
}
