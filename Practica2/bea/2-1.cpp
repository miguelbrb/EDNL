/*
EN COMENTARIOS VERSION VECTORIAL
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "modABin.h"
#include "calNodos.h"
#include "calAltura.h"
#include "calProfundidad.h"
using namespace std;

int main(){
		//ABin <int> a(5);
		ABin <int> a;
		cout<<"\n[Pulse 0 si el nodo no tiene ningun valor aplicable]\n"<<endl;
		cout<<"\nALMACENAR VALORES: "<<endl;
		leerABin(a);
		cout<<"\t... El arbol ha sido almacenado\n"<<endl;
		cout<<"\nMOSTRAR VALORES: "<<endl;
		imprimirABin(a);
		cout<<endl;
		cout<<"\nNumero total de nodos: "<<calcularNodos(a)<<endl;
		cout<<"\nAltura: "<<calcularAltura(a)<<endl;
		cout<<"\nProfundidad: "<<calcularProfundidad(a,a.hijoIzqdoB(a.raizB()))<<endl;
		system("PAUSE");
		return 0;
}
