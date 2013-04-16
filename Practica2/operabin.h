#ifndef OPERABIN_H
#define OPERABIN_H
#include <iostream>
#include "Abin.h"
using namespace std;

//Ejercicio 1
template <typename T>
int numero_nodos (const Abin<T>& A)
{
    return sumar_nodos(A.raizB(),A);   
}

template <typename T>
int sumar_nodos (typename Abin<T>::nodo n, const Abin<T>& A)
{
    if (n != Abin<T>::NODO_NULO) {
       return (1+(sumar_nodos(A.hijoIzqdoB(n),A))+(sumar_nodos(A.hijoDrchoB(n),A)));
    }
    else return 0; 
}

//Ejercicio 2
template <typename T>
int altura (const Abin<T>& A)
{
    return recorre_altura(A.raizB(),A);
}

template <typename T>
int recorre_altura(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if (n != Abin<T>::NODO_NULO) {
       return (1+max((recorre_altura(A.hijoIzqdoB(n),A)),(recorre_altura(A.hijoDrchoB(n),A))));
    }
    else return -1;
}

//Ejercicio 3
template <typename T>
int profundidad (const Abin<T>& A, const typename Abin<T>::nodo n)
{
    if(n==A.raizB()){return 0;}
    else{
    	return (1+profundidad(A,A.padreB(n)));
	}
}
//*******************************************
//4 y 5 hechos en sus respectivos TADs.     *
//*******************************************

//Ejercicio 6
//Aquí, el ejercicio en sí:
template <typename T>
int desequilibrio (const Abin<T>& A)
{
	return desequilibrioMAX(A,A.raizB());
}
template <typename T>
int desequilibrioMAX(const Abin<T>& A, const typename Abin<T>::nodo n)
{
    if(n==Abin<T>::NODO_NULO){return 0;}
    else
    {
        int deseq_nodo=abs(A.altura(A.hijoIzqdoB(n)) - A.altura(A.hijoDrchoB(n)));
        return max(deseq_nodo,max(desequilibrioMAX(A,A.hijoIzqdoB(n)),desequilibrioMAX(A,A.hijoDrchoB(n))));
    }
}

/*
//OTRA POSIBILIDAD: Utilizando funcion maximo(a,b,c) .
//Se necesita una funcion maximo de 3 argumentos si se va a hacer así.
//FUNCION QUE CALCULA EL MAXIMO DE 3 ARGUMENTOS. EL max NO VALE (2 ARGUMENTOS SOLO).
template <typename T>
const T maximo_3 (const T& a, const T& b, const T& c)
{
	T x;
	if(b<c){x=c;}
	else{x=b;}
	if(a<x){return x;}
	else{return a;}
}
template <typename T>
int desequilibrioMAX(const Abin<T>& A, const typename Abin<T>::nodo n)
{
	if(n!=Abin<T>::NODO_NULO)
	{
		int deseq_nodo = abs(A.altura(A.hijoIzqdoB(n))-A.altura(A.hijoDrchoB(n)));
		return maximo_3(deseq_nodo,desequilibrioMAX(A,A.hijoIzqdoB(n)),desequilibrioMAX(A,A.hijoDrchoB(n)));
	}
	else{return 0;}
}
*/

//Ejercicio 7
template <typename T>
bool pseudocompleto(const Abin<T>& A)
{
	if (A.arbolVacioB() || A.altura(A.raizB()) == 0){ return true; }//Arbol vacío o raiz hoja: Pseudocompleto.
    else return pseudocompletRec(A, A.raizB());//Llamada recursiva.
}

template <typename T>
bool pseudocompletRec(const Abin<T>& A, const typename Abin<T>::nodo n)
{
	
	if(A.hijoIzqdoB(n)==Abin<T>::NODO_NULO && A.hijoDrchoB(n)==Abin<T>::NODO_NULO)
	{//El nodo recibido es hoja...
		if(A.hijoIzqdoB(A.padreB(n))!=Abin<T>::NODO_NULO && A.hijoDrchoB(A.padreB(n))==Abin<T>::NODO_NULO)
		{//Si el padre tiene ambos hijos, significa que n tiene hermano. Nivel completo en esa rama.
			return true;
		}
		else return false; //No tiene hermano, y como es hoja en el último nivel, no es pseudocompleto.
	}
	else{ //No es un nodo hoja, tiene hijos.
		if(A.altura(A.hijoIzqdoB(n)) > A.altura(A.hijoDrchoB(n)))//Rama izquierda más larga.
		{
			return pseudocompletRec(A,A.hijoIzqdoB(n));//Llamada recursiva por esa rama.
		}
		else if(A.altura(A.hijoIzqdoB(n)) < A.altura(A.hijoDrchoB(n)))//Rama derecha más larga.
		{
			return pseudocompletRec(A,A.hijoDrchoB(n));//Llamada recursiva por esa rama.
		}
		else if(A.altura(A.hijoIzqdoB(n)) == A.altura(A.hijoDrchoB(n)))//Ramas de igual longitud.
		{
			return (pseudocompletRec(A,A.hijoIzqdoB(n)) && pseudocompletRec(A,A.hijoDrchoB(n)));
			//Llamada recursiva por ambas ramas.
		}
	}
}

/*//Versión Sergi:
template <typename T>
bool pseudoCompletoRec(const Abin<T>& a, typename Abin<T>::nodo n) {
    //defino 3 alias útiles.
    typename Abin<T>::nodo nulo = Abin<T>::NODO_NULO;
    typename Abin<T>::nodo hizq = a.hijoIzqdoB(n);
    typename Abin<T>::nodo hder = a.hijoDrchoB(n);
    
    if (hizq == nulo && hder == nulo) { //si el nodo hoja
        if (a.hijoIzqdoB(a.padreB(n)) == nulo || a.hijoDrchoB(a.padreB(n)) == nulo) {
            return false;
        } else {
            return true;
        }
    } else {
        int altSubArbIzq = (hizq == nulo) ? -1 : a.altura(hizq);
        int altSubArbDer = (hder == nulo) ? -1 : a.altura(hder);
        //si las alturas de los sub-árboles son diferentes
        if (altSubArbIzq > altSubArbDer) {
            return pseudoCompletoRec(a, hizq);
        } else if (altSubArbDer > altSubArbIzq) {
            return pseudoCompletoRec(a, hder);
        } else {
            //si las alturas de los sub-árboles coinciden
            bool porlaDer = true;
            bool porlaIzq = true;
            porlaIzq = (hizq == nulo) ? true : pseudoCompletoRec(a, hizq);
            if (porlaIzq) {
                porlaDer = (hder == nulo) ? true : pseudoCompletoRec(a, hder);
            }
            return (porlaIzq && porlaDer);
        }
    }
}
*/
#endif
