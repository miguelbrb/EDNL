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
//Aquí, el ejercicio en sí:
template <typename T>
int desequilibrio (const Abin<T>& A)
{
	return desequilibrioMAX(A,A.raizB());
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
/*
//OTRA POSIBILIDAD: Utilizando algorithm::max .
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
*/



//Ejercicio 7
template <typename T>
bool pseudocompleto(const Abin<T>& A)
{
	if(A.arbolVacioB()){return false;}//Arbol vacio. No puede ser pseudocompleto.
	else if(A.hijoIzqdoB(A.raizB())==Abin<T>::NODO_NULO && A.hijoDrchoB(A.raizB())==Abin<T>::NODO_NULO)
			{ return false; }//La raíz no tiene hijos. No es el penúltimo nivel, sino el último. No pseudocompleto.
		else if(A.altura(A.raizB())==1)//Solo la raíz tiene hijos.
			{//Si además, ambos existen, entonces la raíz es el penúltimo nivel y el siguiente está completo.
				if(A.hijoIzqdoB(A.raizB())!=Abin<T>::NODO_NULO && A.hijoDrchoB(A.raizB())!=Abin<T>::NODO_NULO)
					{ return true; }
			}
			else{//La altura es mayor que 1. HAY MÁS NODOS.
				return pseudocompletRec(A,A.raizB());//Llamada recursiva.
			}
}

template <typename T>
bool pseudocompletRec(const Abin<T>& A, const typename Abin<T>::nodo n)
{
	//La idea ahora es comprobar primero al hijoIzqdoB y luego al hijoDrchoB.
	//En cada uno, primero se comprueba si la altura es 1. Si lo es, se comprueba que sus hijos
	//sean 2 o ninguno. De lo contrario, no es pseudocompleto.
	//Si la altura no es 1, se pasa al siguiente nivel. Así progresivamente.
	typename Abin<T>::nodo h;//Se crea un nodo para hacer más comodo el código.
	
	h=A.hijoIzqdoB(n);//Primero el hijoIzqdoB(n);
	if(A.altura(h)==1)//Los hijos de h no tienen hijos. Se comprueba la propiedad.
	{
		if(A.hijoIzqdoB(h)==Abin<T>::NODO_NULO && A.hijoDrchoB(h)==Abin<T>::NODO_NULO){ return true; }
		else if(A.hijoIzqdoB(h)!=Abin<T>::NODO_NULO && A.hijoDrchoB(h)!=Abin<T>::NODO_NULO){ return true; }
			else {return false;}//Tiene 1 hijo.
	}
	else if(A.altura(h)>1){ return pseudocompletRec(A,h); }//Si la altura no es 1, se pasa al siguiente nivel.
	
	h=A.hijoDrchoB(n);//Ahora, el hijoDrchoB(n);
	//Se realizan las mismas comprobaciones:
	if(A.altura(h)==1)//Los hijos de h no tienen hijos. Se comprueba la propiedad.
	{
		if(A.hijoIzqdoB(h)==Abin<T>::NODO_NULO && A.hijoDrchoB(h)==Abin<T>::NODO_NULO){ return true; }
		else if(A.hijoIzqdoB(h)!=Abin<T>::NODO_NULO && A.hijoDrchoB(h)!=Abin<T>::NODO_NULO){ return true; }
			else {return false;}//Tiene 1 hijo.
	}
	else if(A.altura(h)>1){ return pseudocompletRec(A,h); }//Si la altura no es 1, se pasa al siguiente nivel.
}


#endif
