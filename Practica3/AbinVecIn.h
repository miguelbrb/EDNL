#ifndef ABINVECIN_H
#define ABINVECIN_H
#include <cassert>
#include <cmath>

template <typename T> class Abin{
	public:
		typedef int nodo;
		static const nodo NODO_NULO;
		explicit Abin(int alturaMax, const T& e_nulo = '-');
		void crearRaizB(const T& e);
		void insertarHijoIzqdoB(nodo n, const T& e);
		void insertarHijoDrchoB(nodo n, const T& e);
		nodo raizB() const;
		nodo padreB(nodo n) const;
		nodo hijoIzqdoB(nodo n) const;
		nodo hijoDrchoB(nodo n) const;
		T& elemento(nodo n);
		T elemento(nodo n) const;
		~Abin();
		void mostrar() const;
	private:
		T* nodos;
		int nNodos;
		int maxNodos;
		T ELTO_NULO;
		int profundidad(nodo n) const;
		int profundidadRec(nodo n, int limitInf, int limitSup) const;
};

//Constructor:
template <typename T>
Abin<T>::Abin(int alturaMax, const T& e_nulo): maxNodos(pow(2,++alturaMax)-1), ELTO_NULO(e_nulo), nNodos(0)
{
//Se marcan todas las celdas como libres:
	nodos=new T[maxNodos];
	for(nodo n=0;n<maxNodos;n++)
	{ nodos[n]=ELTO_NULO; }
	
}

//Definición NODO_NULO
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);

//Funciones privadas:
template <typename T>
int Abin<T>::profundidad(Abin<T>::nodo n) const
{
	return profundidadRec(n,0,maxNodos-1);
}
template <typename T>
int Abin<T>::profundidadRec(Abin<T>::nodo n, int limitInf, int limitSup) const
{
	int mitad = ((limitSup - limitInf)/2) + limitInf;
	if(n == mitad) { return 0; }//Se encuentra el nodo.
	else{
		if(n<mitad){ return 1+profundidadRec(n,limitInf,mitad-1);}//Llamada recursiva a subarbol izquierdo.
		else{ return 1+profundidadRec(n,mitad+1,limitSup);}//Llamada recursiva a la otra rama, subarbol derecho de m.
	}
}

//Resto de métodos:
template <typename T>
void Abin<T>::crearRaizB(const T& e)
{
	assert(nNodos==0);//Arbol está vacío.
	nodos[maxNodos/2]=e;
	nNodos++;
}

template <typename T>
void Abin<T>::insertarHijoIzqdoB(typename Abin<T>::nodo n, const T& e)
{
	assert(nNodos < maxNodos);//El árbol no está lleno.
	int HIzq = n-(maxNodos+1)/(pow(2,profundidad(n)+2));
	nodos[HIzq]=e;
	nNodos++;
}

template <typename T>
void Abin<T>::insertarHijoDrchoB(typename Abin<T>::nodo n, const T& e)
{
	assert(nNodos < maxNodos);//El árbol no está lleno.
	int HDrcho = n+(maxNodos+1)/(pow(2,profundidad(n)+2));
	nodos[HDrcho]=e;
	nNodos++;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::raizB() const
{
	return maxNodos/2;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::padreB(typename Abin<T>::nodo n) const
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	if( n%((maxNodos+1)/pow(2,profundidad(n)-1)) == (((maxNodos+1)/pow(2,profundidad(n)+1))-1) )
	{ return n+(maxNodos+1)/pow(2,profundidad(n)+1); }
	else return n-(maxNodos+1)/pow(2,profundidad(n)+1);
}

template <typename T>
typename Abin<T>::nodo Abin<T>::hijoIzqdoB(typename Abin<T>::nodo n) const
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	return n-(maxNodos+1)/pow(2,profundidad(n)+2);
}

template <typename T>
typename Abin<T>::nodo Abin<T>::hijoDrchoB(typename Abin<T>::nodo n) const
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	return n+(maxNodos+1)/pow(2,profundidad(n)+2);
}

template <typename T>
T& Abin<T>::elemento(typename Abin<T>::nodo n)
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	return nodos[n];
}

template <typename T>
T Abin<T>::elemento(typename Abin<T>::nodo n) const
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	return nodos[n];
}

template <typename T>
Abin<T>::~Abin()
{
	maxNodos=0;
	nNodos=0;
	delete nodos;
}

template <typename T>
void Abin<T>:: mostrar() const{
	
	for(int i=0; i<maxNodos; i++){
		std::cout<<"Elemento "<<i<<" = "<<nodos[i]<<std::endl;
	}
}
#endif
