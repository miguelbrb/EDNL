#ifndef ABINVECIN_H
#define ABINVECIN_H
#include <cassert>
#include <cmath>

template <typename T> class Abin{
	public:
		typedef int nodo;
		static const nodo NODO_NULO;
		explicit Abin(int alturaMax, const T& e_nulo);
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
	private:
		T* nodos;
		int nNodos;
		int maxNodos;
		T ELTO_NULO;
		int profundidad(nodo n) const;
		int profundidadRec(nodo n, nodo m, int tam) const;
};
//Definición NODO_NULO
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);

//Funciones privadas:
template <typename T>
int Abin<T>::profundidad(Abin<T>::nodo n) const
{
	return profundidadRec(n,maxNodos/2,maxNodos);
}
template <typename T>
int Abin<T>::profundidadRec(Abin<T>::nodo n, Abin<T>::nodo m, int tam) const
{
	if(n == m) { return 0; }//Se encuentra el nodo.
	else{
		tam=tam-m-1;///tam comprende ahora el subarbol izquierdo descendiente de m.
		if(n<m){ return 1+profundidadRec(n,m/2,tam);}//Llamada recursiva a esa rama, subarbol izquierdo de m.
		if(n>m){ return 1+profundidadRec(n,tam/2+m,tam);}//Llamada recursiva a la otra rama, subarbol derecho de m.
	}
}

//Constructor:
template <typename T>
Abin<T>::Abin(int alturaMax, const T& e_nulo): maxNodos(pow(2,++alturaMax)), ELTO_NULO(e_nulo), nNodos(0)
{
//Se marcan todas las celdas como libres:
	for(nodo n=0;n<maxNodos;n++)
	{ nodos[n]=ELTO_NULO; }
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
void Abin<T>::insertarHijoIzqdoB(Abin<T>::nodo n, const T& e)
{
	assert(nNodos < maxNodos);//El árbol no está lleno.
	int HI=(n-(maxNodos+1))/pow(2,profundidad(n)+2);
	nodos[HI]=e;
	nNodos++;
}

template <typename T>
void Abin<T>::insertarHijoDrchoB(Abin<T>::nodo n, const T& e)
{
	assert(nNodos < maxNodos);//El árbol no está lleno.
	int HD=(n+(maxNodos+1))/pow(2,profundidad(n)+2);
	nodos[HD]=e;
	nNodos++;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::raizB() const
{
	return maxNodos/2;
}

template <typename T>
typename Abin<T>::nodo Abin<T>::padreB(Abin<T>::nodo n) const
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	if( n%((maxNodos+1)/pow(2,profundidad(n)-1)) == (((maxNodos+1)/pow(2,profundidad(n)+1))-1) )
	{ return (n+(maxNodos+1))/pow(2,profundidad(n)+1); }
	else return (n-(maxNodos+1))/pow(2,profundidad(n)+1);
}

template <typename T>
typename Abin<T>::nodo Abin<T>::hijoIzqdoB(Abin<T>::nodo n) const
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	return (n-(maxNodos+1))/pow(2,profundidad(n)+2);
}

template <typename T>
typename Abin<T>::nodo Abin<T>::hijoDrchoB(Abin<T>::nodo n) const
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	return (n+(maxNodos+1))/pow(2,profundidad(n)+2);
}

template <typename T>
T& Abin<T>::elemento(Abin<T>::nodo n)
{
	assert(n > 0 && n < maxNodos);//El nodo pertenece al árbol.
	return nodos[n];
}

template <typename T>
T Abin<T>::elemento(Abin<T>::nodo n) const
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
#endif
