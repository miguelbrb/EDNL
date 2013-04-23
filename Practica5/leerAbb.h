#include <iostream>
#include "Abb.h"
using namespace std;

template <typename T> 
void leerAbb(Abb<T>& a){
     if(a.vacio()){
		 T elto, bandera;
		 cout << "Escriba elemento 'bandera' para parar" << endl;
		 cin >> bandera;
		 leerAbbRec(a, bandera);
	}else{cout<<"Error: El arbol no estaba vacio." <<endl;}
}

template <typename T> 
void leerAbbRec(Abb<T>& A, T bandera){
     T elto;
     cout << "Inserta nodo para introducir en el arbol: ('"<< bandera <<"' no introducir mas hijos por aqui) " << endl;
     cin >> elto;
     if(elto != bandera){
          A.insertar(elto);
          leerAbbRec(A, bandera);
     }
}
