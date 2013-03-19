#ifndef ABINV_H
#define ABINV_H
#include <cstdlib>
#include <cassert>

template <typename T> 
class ABin {
   public:
			 typedef int nodo; // �ndice de la matriz entre 0 y maxNodos-1
			 static const nodo NODO_NULO;
			 ABin(size_t maxNodos); // constructor
			 void crearRaizB(const T& e);
			 void insertarHijoIzqdoB(nodo n, const T& e);
			 void insertarHijoDrchoB(nodo n, const T& e);
			 void eliminarHijoIzqdoB(nodo n);
			 void eliminarHijoDrchoB(nodo n);
			 void eliminarRaizB();
			 ~ABin(); // destructor
			 bool arbolVacioB() const;
			 T elemento(nodo n) const; // acceso a elto, lectura
			 T& elemento(nodo n); // acceso a elto, lectura/escritura
			 nodo raizB() const;
			 nodo padreB(nodo n) const;
			 nodo hijoIzqdoB(nodo n) const;
			 nodo hijoDrchoB(nodo n) const;
			 ABin(const ABin<T>& a); // ctor. de copia
			 ABin<T>& operator =(const ABin<T>& a); // asignaci�n
   private:
       struct celda {
							 T elto;
							 nodo padre, hizq, hder;
			 };
			 celda *nodos; // vector de nodos
			 int maxNodos; // tama�o del vector
			 int numNodos; // n�mero de nodos del �rbol
};

/* Definici�n del nodo nulo */
template <typename T>
const typename ABin<T>::nodo ABin<T>::NODO_NULO(-1);

template <typename T>
inline ABin<T>::ABin(size_t maxNodos): nodos(new celda[maxNodos]),maxNodos(maxNodos), numNodos(0)
{}

template <typename T>
void ABin<T>::crearRaizB(const T& e){
		 assert(numNodos == 0); // �rbol vac�o
		 numNodos = 1;
		 nodos[0].elto = e;
		 nodos[0].padre = NODO_NULO;
		 nodos[0].hizq = NODO_NULO;
		 nodos[0].hder = NODO_NULO;
}

template <typename T>
void ABin<T>::insertarHijoIzqdoB(ABin<T>::nodo n, const T& e){
		 assert(n >= 0 && n < numNodos); // nodo v�lido
		 assert(nodos[n].hizq == NODO_NULO); // n no tiene hijo izqdo.
		 assert(numNodos < maxNodos); // �rbol no lleno a�adir el nuevo nodo al final de la secuencia
		 nodos[n].hizq = numNodos;
		 nodos[numNodos].elto = e;
		 nodos[numNodos].padre = n;
		 nodos[numNodos].hizq = NODO_NULO;
		 nodos[numNodos].hder = NODO_NULO;
		 ++numNodos;
}

template <typename T>
void ABin<T>::insertarHijoDrchoB(ABin<T>::nodo n, const T& e){
		 assert(n >= 0 && n < numNodos); // nodo v�lido
		 assert(nodos[n].hder == NODO_NULO); // n no tiene hijo drcho.
		 assert(numNodos < maxNodos); // �rbol no lleno a�adir el nuevo nodo al final de la secuencia
		 nodos[n].hder = numNodos;
		 nodos[numNodos].elto = e;
		 nodos[numNodos].padre = n;
		 nodos[numNodos].hizq = NODO_NULO;
		 nodos[numNodos].hder = NODO_NULO;
		 ++numNodos;
}

template <typename T>
void ABin<T>::eliminarHijoIzqdoB(ABin<T>::nodo n){
		 assert(n >= 0 && n < numNodos); // nodo v�lido
		 nodo hizqdo = nodos[n].hizq;
		 assert(hizqdo != NODO_NULO); // existe hijo izqdo. de n
		 assert(nodos[hizqdo].hizq == NODO_NULO && // hijo izqdo. de
		 nodos[hizqdo].hder == NODO_NULO); // n es hoja
		 if (hizqdo != numNodos-1) {
			   // Mover el �ltimo nodo a la posici�n del hijo izqdo.
		 		nodos[hizqdo] = nodos[numNodos-1];
		 		// Actualizar la posici�n del hijo (izquierdo o derecho)
		 		// en el padre del nodo movido
		 		if (nodos[nodos[hizqdo].padre].hizq == numNodos-1)
		 			 nodos[nodos[hizqdo].padre].hizq = hizqdo;
		 		else
		 		 		nodos[nodos[hizqdo].padre].hder = hizqdo;
		 		 		// Si el nodo movido tiene hijos, actualizar la posici�n del padre
		 		if (nodos[hizqdo].hizq != NODO_NULO)
		 			 nodos[nodos[hizqdo].hizq].padre = hizqdo;
		 		if (nodos[hizqdo].hder != NODO_NULO)
		 			 nodos[nodos[hizqdo].hder].padre = hizqdo;
		 }
		 nodos[n].hizq = NODO_NULO;
		 --numNodos;
}

template <typename T>
inline void ABin<T>::eliminarRaizB(){
     assert(numNodos == 1);
		 numNodos = 0;
}

template <typename T>
inline ABin<T>::~ABin(){
    delete[] nodos;
}

template <typename T>
inline bool ABin<T>::arbolVacioB() const{
    return (numNodos == 0);
}

template <typename T>
inline T ABin<T>::elemento(ABin<T>::nodo n) const{
    assert(n >= 0 && n < numNodos);
    return nodos[n].elto;
}

template <typename T>
inline T& ABin<T>::elemento(ABin<T>::nodo n){
   assert(n >= 0 && n < numNodos);
   return nodos[n].elto;
}

template <typename T>
inline typename ABin<T>::nodo ABin<T>::raizB() const{
    return numNodos? 0 : NODO_NULO;
}

template <typename T> inline
typename ABin<T>::nodo ABin<T>::padreB(ABin<T>::nodo n) const{
    assert(n >= 0 && n < numNodos);
    return nodos[n].padre;
}

template <typename T> inline
typename ABin<T>::nodo ABin<T>::hijoIzqdoB(ABin<T>::nodo n) const{
   assert(n >= 0 && n < numNodos);
   return nodos[n].hizq;
}

template <typename T> inline
typename ABin<T>::nodo ABin<T>::hijoDrchoB(ABin<T>::nodo n) const{
   assert(n >= 0 && n < numNodos);
   return nodos[n].hder;
}

template <typename T>
ABin<T>::ABin(const ABin<T>& a) :nodos(new celda[a.maxNodos]),maxNodos(a.maxNodos),numNodos(a.numNodos){
// copiar el vector
   for (nodo n = 0; n < numNodos; n++)
	 		 nodos[n] = a.nodos[n];
}

template <typename T>
ABin<T>& ABin<T>::operator =(const ABin<T>& a){
   if (this != &a) { // evitar autoasignaci�n
   		// Destruir el vector y crear uno nuevo si es necesario
   		if (maxNodos != a.maxNodos) {
				 delete[] nodos;
			   maxNodos = a.maxNodos;
				 nodos = new celda[maxNodos];
		  }
			// Copiar el vector
			numNodos = a.numNodos;
			for (nodo n = 0; n < numNodos; n++)
					nodos[n] = a.nodos[n];
   }
	 return *this;
}

#endif // ABINV_H
