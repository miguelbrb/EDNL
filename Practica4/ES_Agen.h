#ifndef ES_AGEN_H
#define ES_AGEN_H
#include <iostream>
#include "Agen.h"//Dinámico.
using namespace std;

template <typename T>
void imprimirAgen(const Agen<T>& A)
{
    if (!A.arbolVacio()) {
        cout << "Raiz del arbol: "
        << A.elemento(A.raiz()) << endl;
        imprimirDescendientes(A.raiz(), A);
    }
    else
    cout << "Arbol vacio\n";
}

template <typename T>
void imprimirDescendientes (typename Agen<T>::nodo r,const Agen<T>& A)
{
     if (A.hijoIzqdo(r) != Agen<T>::NODO_NULO) {
        cout << "Hijo izqdo de " << A.elemento(r) << ": "
        << A.elemento(A.hijoIzqdo(r)) << endl;
        imprimirDescendientes(A.hijoIzqdo(r), A);
     }
     if (A.hermDrcho(r) != Agen<T>::NODO_NULO) {
        cout << "Hermano derecho de " << A.elemento(r) << ": "
        << A.elemento(A.hermDrcho(r)) << endl;
        imprimirDescendientes(A.hermDrcho(r), A);
     }
}

template <typename T> 
void leerAgen(Agen<T>& a){
     if(a.arbolVacio()){
		 T elto, bandera;
		 cout << "Escriba elemento 'bandera' para parar" << endl;
		 cin >> bandera;
		 cout << "Introduzca nodo raiz:" << endl;
		 cin >> elto;
		 if(elto!=bandera){
		                   a.crearRaiz(elto);
		                   leerDescendientes(a, a.raiz(), bandera);
		                   }
		 else{
		      cout << "Fin del arbol." << endl;
		      }
		 }else{cout<<"Error: El arbol no estaba vacio."<<endl;}
     }

template <typename T> 
void leerDescendientes (Agen<T>& A, typename Agen<T>::nodo n, T bandera){
     T elto;
     cout << "Inserta hijo izquierdo de " << A.elemento(n) <<": ('" << bandera << "' no introducir mas hijos por aqui) " << endl;
     cin >> elto;
     if(elto != bandera){
          A.insertarHijoIzqdo(n,elto);
          leerDescendientes(A, A.hijoIzqdo(n), bandera);
     }
     if(n!= A.raiz()){
     cout << "Inserta hermano derecho de " << A.elemento(n) <<": ('" << bandera << "' no introducir mas hijos por aqui) " << endl;
     cin >> elto;
             if(elto != bandera){
                     A.insertarHermDrcho(n,elto);
                     leerDescendientes(A, A.hermDrcho(n), bandera);
             }
     }
}

#endif  // ES_AGEN_H
