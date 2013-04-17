#include <iostream>
#include "AbinVecIn.h"
using namespace std;

int main(){
	
        Abin<char> b1(3, '-');
        cout << "arbol creado" << endl;
        b1.crearRaizB('h');
        cout << "raiz creado" << endl;
        b1.insertarHijoIzqdoB(b1.raizB(), 'a');
        cout << "hizq(r) creado" << endl;
       	b1.insertarHijoDrchoB(b1.raizB(), 'm'); 
       	cout << "hder(r) creado" << endl;       
        b1.insertarHijoIzqdoB(b1.hijoIzqdoB(b1.raizB()), 'n');
        cout << "hizq(hizq(r) creado" << endl;
        b1.insertarHijoDrchoB(b1.hijoDrchoB(b1.raizB()), 'b');
        cout << "hder(hder(r) creado" << endl;
        
        cout<<b1.elemento(b1.raizB())<<endl;
        cout<<b1.elemento(b1.hijoIzqdoB(b1.raizB()))<<endl;
        cout<<b1.elemento(b1.hijoDrchoB(b1.raizB()))<<endl;
        cout<<b1.elemento(b1.hijoIzqdoB(b1.hijoIzqdoB(b1.raizB())))<<endl;
        cout<<b1.elemento(b1.hijoDrchoB(b1.hijoDrchoB(b1.raizB())))<<endl;
        return 0;
}
