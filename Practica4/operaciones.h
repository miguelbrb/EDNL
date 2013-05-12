#include "Agen.h"
#include "ES_Agen.h"
#include <algorithm>

template <typename T>
int gradoAgen(const Agen<T> a)
{
	return calculaGrado(a, a.raiz());
}

template <typename T>
int calculaGrado(const Agen<T> a, typename Agen<T>::nodo n)
{
	if(n==Agen<T>::NODO_NULO){ return 0; }
	int grado = 0;
	if(a.hijoIzqdo(n)!=Agen<T>::NODO_NULO){//Tiene al menos un hijo:
		grado=1;
		grado=max(grado,calculaGrado(a,a.hijoIzqdo(n)));//Se calcula grado del hijoIzqdo.
		typename Agen<T>::nodo herm=a.hijoIzqdo(n);//herm es hijoIzqdo(n)
		while(herm.hermDrcho(n)!=Agen<T>::NODO_NULO)//Mientras herm tenga hermanos:
		{
			grado=max(grado,calculaGrado(a,a.hermDrcho(herm)));
			herm=a.hermDrcho(herm);//Se pasa a su hermano.
		}
	}
	return grado;//El grado resultante es el máximo del grado de los hijos de n.
}
