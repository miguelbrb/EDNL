#ifndef PODA_H
#define PODA_H
#include <cstdlib>

//PODA. Funcion en el TAD ABB

template <typename T>
void Abb<T>::poda(const T& e){
	typename Abb<T>::nodo n = buscar(e);
	if(n!=Abb<T>::NODO_NULO){
		podaR(n->hizq);
		eliminarHijoIzq(n);
		eliminar(e);
	}
}
template <typename T>
void podaR(typename Abin<T>::nodo n){
	if((n->hizq)!=Abb<T>::NODO_NULO){	
		podaR(n->hizq);
		eliminar(n->hizq->elto);
	}
	if((n->hder)!=Abb<T>::NODO_NULO){
		podaR(n->hder);
		eliminar(n->hder->elto);
	}
}
#endif//PODA_H
