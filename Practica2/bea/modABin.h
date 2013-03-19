/*
EN COMENTARIOS VERSION DINAMICA
*/

#ifndef MODABIN_H
#define MODABIN_H
#include "ABinD.h"
//#include "ABinV.h"
#define SALIR 0//Si definimos SALIR como 0 solo nos sera util si el arbol es de enteros,
//en el caso de ser un arbol de char habra que utilizar otro valor para SALIR

using namespace std;

template <typename T>
void leerDescendientes(typename ABin<T>::nodo n, ABin<T>& a){
		 T h;
		 cout<<"Valor hijo izqdo de "<<a.elemento(n)<<": ";
		 cin>>h;
		 if(h!=SALIR){
			   a.insertarHijoIzqdoB(n,h);
			   leerDescendientes(a.hijoIzqdoB(n),a);
     }
     
		 cout<<"Valor hijo derecho de "<<a.elemento(n)<<": ";
		 cin>>h;
		 if(h!=SALIR){
			   a.insertarHijoDrchoB(n,h);
			   leerDescendientes(a.hijoDrchoB(n),a);
     }
}

template <typename T>
void leerABin(ABin<T> &a){
		 T r;
		 cout<<"Valor para la raiz: ";
		 cin>>r;
		 if(r!=SALIR){
			   a.crearRaizB(r);
			   leerDescendientes(a.raizB(),a);
     }
}

template <typename T>
void imprimirDescendientes (typename ABin<T>::nodo r,const ABin<T>& a){
		 if (a.hijoIzqdoB(r) != ABin<T>::NODO_NULO) {
		 		cout << "Hijo izqdo de " << a.elemento(r) << ": "<<a.elemento(a.hijoIzqdoB(r))<<endl;
				imprimirDescendientes(a.hijoIzqdoB(r), a);
     }
		 if (a.hijoDrchoB(r) != ABin<T>::NODO_NULO) {
		 		cout << "Hijo derecho de " << a.elemento(r) << ": "<< a.elemento(a.hijoDrchoB(r))<<endl;
				imprimirDescendientes(a.hijoDrchoB(r), a);
     }
}

template <typename T>
void imprimirABin (const ABin<T>& a){
		 if (!a.arbolVacioB()) {
		 		cout << "Raiz del arbol: "<< a.elemento(a.raizB())<<endl;
				imprimirDescendientes(a.raizB(), a);
     }
		 else
		 		 cout << "Arbol vacio\n";
}
#endif
