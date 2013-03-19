/*
Implementa un subprograma que calcule la altura de un árbol binario.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ABinD.h"
//#include "ABinV.h"

using namespace std;

template <typename T>
int calcularAlturaDescendientes(const ABin <T>& a,typename ABin<T>::nodo h){
    if(h == ABin<T>::NODO_NULO){
		    return -1;
    }
    if(calcularAlturaDescendientes(a,a.hijoIzqdoB(h)) > calcularAlturaDescendientes(a,a.hijoDrchoB(h))){
			 return calcularAlturaDescendientes(a,a.hijoIzqdoB(h)) + 1;
    }
    else{
		   return calcularAlturaDescendientes(a,a.hijoDrchoB(h)) + 1;
    }
}

template <typename T> 
int calcularAltura(const ABin <T>& a){
		if(!a.arbolVacioB()){
	      return calcularAlturaDescendientes(a,a.raizB());
		}
		else return 0;
}
