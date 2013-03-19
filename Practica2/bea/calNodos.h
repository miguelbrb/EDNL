/*
Implementa un subprograma que calcule el número de nodos de un árbol binario.
*/
#ifndef CALNODOS_H
#define CALNODOS_H
//#include "ABinV.h"
#include "ABinD.h"
#include <cstdlib>
 
using namespace std;

template <typename T>
int calcularNodosDescendientes(const ABin <T>& a,typename ABin<T>::nodo h){
		if(h == ABin<T>::NODO_NULO){
	      return 0;
		}
		else return 1 + calcularNodosDescendientes(a,a.hijoIzqdoB(h)) + calcularNodosDescendientes(a,a.hijoDrchoB(h));
}

template <typename T> 
int calcularNodos(const ABin <T>& a){
		if(!a.arbolVacioB()){
	      return calcularNodosDescendientes(a,a.raizB());
		}
		else return 0;
}


#endif//CALNODOS_H
