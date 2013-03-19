/*
Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
la profundidad de este nodo en dicho árbol.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ABinD.h"
//#include "ABinV.h"

using namespace std;

template <typename T> 
int calcularProfundidad(const ABin <T>& a,typename ABin<T>::nodo p){
		if(p==a.raizB()){
	      return 0;
		}
		else return 1+calcularProfundidad(a,a.padreB(p));
}
