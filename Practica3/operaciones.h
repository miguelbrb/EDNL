#include <Abin.h>
#include <iostream>
using namespace std;

//Ejercicio 1. Arboles similares.
template <typename T>
bool AbinSimilares(const Abin<T>& A, const Abin<T>& B)
{
	if(A.arbolVacioB() && B.arbolVacioB()){ return true; }
	else if(!A.arbolVacioB() && !B.arbolVacioB()){
			return SimilaresRec(A,A.raizB(),B,B.raizB());
		}
		else return false;
}

template <typename T>
bool SimilaresRec(const Abin<T>& A, const typename Abin<T>::nodo a,const Abin<T>& B, const typename Abin<T>::nodo b)
{
	if(a==Abin<T>::NODO_NULO && b==Abin<T>::NODO_NULO) { return true; }
	if(a.hijoIzqdoB()!=Abin<T>::NODO_NULO && b.hijoIzqdoB()!=Abin<T>::NODO_NULO)
	{
		return return SimilaresRec(A,a.hijoIzqdoB(),B,b.hijoIzqdoB());
	}
	if(a.hijoDrchoB()!=Abin<T>::NODO_NULO && b.hijoDrchoB()!=Abin<T>::NODO_NULO)
	{
		return return SimilaresRec(A,a.hijoDrchoB(),B,b.hijoDrchoB());
	}
	else return false;	
}
