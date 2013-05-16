#ifndef ES_ABIN_H
#define ES_ABIN_H
#include <iostream>
//#include "Abin_vec0.h"//Estático.
#include "Abin.h"//Dinámico.
using namespace std;

template <typename T>
void imprimirAbin(const Abin<T>& A)
{
    if (!A.arbolVacioB()) {
        cout << "Raiz del arbol: "
        << A.elemento(A.raizB()) << endl;
        imprimirDescendientes(A.raizB(), A);
    }
    else
    cout << "Arbol vacio\n";
}

template <typename T>
void imprimirDescendientes (typename Abin<T>::nodo r,const Abin<T>& A)
{
     if (A.hijoIzqdoB(r) != Abin<T>::NODO_NULO) {
        cout << "Hijo izqdo de " << A.elemento(r) << ": "
        << A.elemento(A.hijoIzqdoB(r)) << endl;
        imprimirDescendientes(A.hijoIzqdoB(r), A);
     }
     if (A.hijoDrchoB(r) != Abin<T>::NODO_NULO) {
        cout << "Hijo derecho de " << A.elemento(r) << ": "
        << A.elemento(A.hijoDrchoB(r)) << endl;
        imprimirDescendientes(A.hijoDrchoB(r), A);
     }
}

template <typename T> 
void leerAbin(Abin<T>& a){
     if(a.arbolVacioB()){
		 T elto, bandera;
		 cout << "Escriba elemento 'bandera' para parar" << endl;
		 cin >> bandera;
		 cout << "Introduzca nodo raiz:" << endl;
		 cin >> elto;
		 if(elto!=bandera){
		                   a.crearRaizB(elto);
		                   leerDescendientes(a, a.raizB(), bandera);
		                   }
		 else{
		      cout << "Fin del arbol." << endl;
		      }
		 }else{cout<<"Error: El arbol no estaba vacio."<<endl;}
     }

template <typename T> 
void leerDescendientes (Abin<T>& A, typename Abin<T>::nodo n, T bandera){
     T elto;
     cout << "Inserta hijo izquierdo de " << A.elemento(n) <<": ('" << bandera << "' no introducir mas hijos por aqui) " << endl;
     cin >> elto;
     if(elto != bandera){
          A.insertarHijoIzqdoB(n,elto);
          leerDescendientes(A, A.hijoIzqdoB(n), bandera);
     }
     cout << "Inserta hijo derecho de " << A.elemento(n) <<": ('" << bandera << "' no introducir mas hijos por aqui) " << endl;
     cin >> elto;
             if(elto != bandera){
                     A.insertarHijoDrchoB(n,elto);
                     leerDescendientes(A, A.hijoDrchoB(n), bandera);
             }
}
#endif  // ES_ABIN_H
