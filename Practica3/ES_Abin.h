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

bool pregunta()
{
	char sn;
	cout << "Desea introducir un nodo? (s/n)" << endl;
	cin >> sn;
	return (sn=='s');
}


template <typename T> 
void leerAbin(Abin<T>& a){
     if(a.arbolVacioB()){
		T elto;
		if(pregunta()){
			 cout << "Introduzca nodo raiz:" << endl;
			 cin >> elto;
		     a.crearRaizB(elto);
			leerDescendientes(a, a.raizB());
			}
			 else{
				  cout << "Fin del arbol." << endl;
				  }
				 
		 }else{cout<<"Error: El arbol no estaba vacio."<<endl;}
     }

template <typename T> 
void leerDescendientes (Abin<T>& A, typename Abin<T>::nodo n){
     T elto;
     cout << "Hijo izquierdo de " << A.elemento(n) <<": " << endl;
     if(pregunta()){
     	cin >> elto;
          A.insertarHijoIzqdoB(n,elto);
          leerDescendientes(A, A.hijoIzqdoB(n));
     }
     cout << "Hijo derecho de " << A.elemento(n) <<": " << endl;
     if(pregunta()){
            cin >> elto;
            A.insertarHijoDrchoB(n,elto);
            leerDescendientes(A, A.hijoDrchoB(n));
     }
}

#endif  // ES_ABIN_H
