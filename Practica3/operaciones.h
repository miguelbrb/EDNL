#include <iostream>
#include "Abin.h"
#include "expresion.h"
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
bool SimilaresRec (const Abin<T>& A, const typename Abin<T>::nodo a,const Abin<T>& B, const typename Abin<T>::nodo b)
{
	if(a!=Abin<T>::NODO_NULO && b!=Abin<T>::NODO_NULO)
	{
		return SimilaresRec(A,A.hijoIzqdoB(a),B,B.hijoIzqdoB(b)) && SimilaresRec(A,A.hijoDrchoB(a),B,B.hijoDrchoB(b));
	}
	else if(a==Abin<T>::NODO_NULO && b==Abin<T>::NODO_NULO){ return true; }
		else return false;
}

//Ejercicio 2. Reflejar un arbol en otro.
template <typename T>
Abin<T> reflejar(const Abin<T>& A)
{
	Abin<T> reflejo;
	if(A.arbolVacioB()){ return reflejo; }
	else{ 
		reflejo.crearRaizB(A.elemento(A.raizB()));
		refleRec(A,A.raizB(),reflejo,reflejo.raizB());
		return reflejo;
		}
}

template <typename T>
void refleRec(const Abin<T>& A, const typename Abin<T>::nodo a, Abin<T>& B, const typename Abin<T>::nodo b)
{
	if(A.hijoIzqdoB(a)!=Abin<T>::NODO_NULO || A.hijoDrchoB(a)!=Abin<T>::NODO_NULO){//Si tiene algún hijo...
		if(A.hijoIzqdoB(a)!=Abin<T>::NODO_NULO)
		{
			B.insertarHijoDrchoB(b,A.elemento(A.hijoIzqdoB(a)));
			refleRec(A,A.hijoIzqdoB(a),B,B.hijoDrchoB(b));
		}
		if(A.hijoDrchoB(a)!=Abin<T>::NODO_NULO)
		{
			B.insertarHijoIzqdoB(b,A.elemento(A.hijoDrchoB(a)));
			refleRec(A,A.hijoDrchoB(a),B,B.hijoIzqdoB(b));
		}
	}
	else{/*No se hace nada.*/}//No tiene hijos, por tanto no se sigue por esa rama.
}

//EJERCICIO 3.

double calculaExpRec(const Abin<expresion>& A, const typename Abin<expresion>::nodo n)
{
	if(A.hijoIzqdoB(n)==Abin<expresion>::NODO_NULO && A.hijoDrchoB(n)==Abin<expresion>::NODO_NULO)
	{//Nodo es hoja, luego es un operando:
		return A.elemento(n).operando;
	}
	else{//No es una hoja, por tanto, es un operador:
		double resultado;
		switch(A.elemento(n).operador)
		{
			case'+':
			{
				resultado=calculaExpRec(A,A.hijoIzqdoB(n)) + calculaExpRec(A,A.hijoDrchoB(n));
				break;
			}
			case'-':
			{
				resultado=calculaExpRec(A,A.hijoIzqdoB(n)) - calculaExpRec(A,A.hijoDrchoB(n));
				break;
			}
			case'*':
			{
				resultado=calculaExpRec(A,A.hijoIzqdoB(n)) * calculaExpRec(A,A.hijoDrchoB(n));
				break;
			}
			case'/':
			{
				resultado=calculaExpRec(A,A.hijoIzqdoB(n)) / calculaExpRec(A,A.hijoDrchoB(n));
				break;
			}
		}
		return resultado;
	}
}

double calcularExp(const Abin<expresion>& A)
{
	return calculaExpRec(A,A.raizB());	
}
