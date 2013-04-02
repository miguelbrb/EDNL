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
	if(A.hijoIzqdoB(a)!=Abin<T>::NODO_NULO && B.hijoIzqdoB(b)!=Abin<T>::NODO_NULO)
	{
		return SimilaresRec(A,A.hijoIzqdoB(a),B,B.hijoIzqdoB(b));
	}
	if(A.hijoDrchoB(a)!=Abin<T>::NODO_NULO && B.hijoDrchoBb()!=Abin<T>::NODO_NULO)
	{
		return SimilaresRec(A,A.hijoDrchoB(a),B,B.hijoDrchoB(b));
	}
	else return false;	
}

/*
//OTRA FORMA. No tan eficiente, pero es buena.
template <typename T>
bool AbinSimilares (const Abin<T>& A, const typename Abin<T>::nodo a,const Abin<T>& B, const typename Abin<T>::nodo b)
{
	if(A.arbolVacioB() && B.arbolVacioB()){ return true; }
	else{
		if(a!=Abin<T>::NODO_NULO && b!=Abin<T>::NODO_NULO)
		{
			bool ri,rd;
			
			ri=AbinSimilares(A,A.hijoIzqdoB(a),B,B.hijoIzqdoB(b));
			rd=AbinSimilares(A,A.hijoDrchoB(a),B,B.hijoDrchoB(b));
			
			return ri && rd;
		}
		else if(a==Abin<T>::NODO_NULO && b==Abin<T>::NODO_NULO)
				{ return true; }
			else return false;
	}
}
