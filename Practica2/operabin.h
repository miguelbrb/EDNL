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
    return ((recorre_altura(A.raizB(),A))-1);
}

template <typename T>
int recorre_altura(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if (n != Abin<T>::NODO_NULO) {
       return (1+max((recorre_altura(A.hijoIzqdoB(n),A)),(recorre_altura(A.hijoDrchoB(n),A))));
    }
    else return 0;
}
/*
template <typename T>
int profundidad (const Abin<T>& A, const T& e)
{
	return buscaProf(A,A.raizB(),e);
}

template <typename T>
int buscaProf(const Abin<T>& A, const typename Abin<T>::nodo n,const T& e)
{
    if(n!=Abin<T>::NODO_NULO){
    if (e != A.elemento(n)){
       return (1+min(buscaProf(A,A.hijoIzqdoB(n),e),buscaProf(A,A.hijoDrchoB(n),e)));
    }}
    else return 0;
}
*/


//Ejercicio 3
template <typename T>
int profundidad (const Abin<T>& A, const typename Abin<T>::nodo n)
{
    return ((busca_profundidad(A.raizB(),A,n)));
}

template <typename T>
int busca_profundidad(typename Abin<T>::nodo n, const Abin<T>& A, const typename Abin<T>::nodo m)
{
    if(n!=Abin<T>::NODO_NULO){
    if (A.elemento(n) != A.elemento(m)) {
       return (1+max((busca_profundidad(A.hijoIzqdoB(n),A,m)),(busca_profundidad(A.hijoDrchoB(n),A,m))));
    }}
    else return 0;
}

#endif
