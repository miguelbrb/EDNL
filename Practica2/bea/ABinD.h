#ifndef ABIND_H
#define ABIND_H
#include <cassert>
#include <cstdlib>

template <typename T>
class ABin {
    struct celda;

    public:
        typedef celda* nodo;
        static const nodo NODO_NULO;
        ABin();
        void crearRaizB(const T& e);
        void insertarHijoIzqdoB(nodo n, const T& e);
        void insertarHijoDrchoB(nodo n, const T& e);
        void eliminarHijoIzqdoB(nodo n);
        void eliminarHijoDrchoB(nodo n);
        void eliminarRaizB();
        ~ABin();
        bool arbolVacioB() const;
        T elemento(nodo n) const; // acceso a elto, lectura
        T& elemento(nodo n); // acceso a elto, lectura/escritura
        nodo raizB() const;
        nodo padreB(nodo n) const;
        nodo hijoIzqdoB(nodo n) const;
        nodo hijoDrchoB(nodo n) const;
        ABin(const ABin<T>& a); // ctor. de copia
        ABin<T>& operator =(const ABin<T>& a); //asignacion de arboles
        
    private:
        struct celda 
        {
            T elto;
            nodo padre, hizq, hder;
            celda(const T& e, nodo p = NODO_NULO): elto(e),
            padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
        };
        
        nodo r; // nodo raíz del árbol
        void destruirNodos(nodo n);
        nodo copiar(nodo n);
};

/* Definicion del nodo nulo */
template <typename T>
const typename ABin<T>::nodo ABin<T>::NODO_NULO(0);

template <typename T>
inline ABin<T>::ABin() : r(ABin<T>::NODO_NULO) {}

template <typename T>
inline void ABin<T>::crearRaizB (const T& e){
    assert(r == ABin<T>::NODO_NULO); // Arbol vacio
    r = new celda(e);
}

template <typename T>
inline void ABin<T>::insertarHijoIzqdoB(ABin<T>::nodo n, const T& e){
    assert(n != ABin<T>::NODO_NULO);
    assert(n->hizq == ABin<T>::NODO_NULO); // no existe hijo
    n->hizq = new celda(e, n);
}

template <typename T> inline
void ABin<T>::insertarHijoDrchoB(ABin<T>::nodo n, const T& e){
    assert(n != ABin<T>::NODO_NULO);
    assert(n->hder == ABin<T>::NODO_NULO); // no existe hijo
    n->hder = new celda(e, n);
}

template <typename T>
inline void ABin<T>::eliminarHijoIzqdoB(ABin<T>::nodo n){
    assert(n != ABin<T>::NODO_NULO);
    assert(n->hizq != ABin<T>::NODO_NULO);
    assert(n->hizq->hizq == ABin<T>::NODO_NULO &&
    n->hizq->hder == ABin<T>::NODO_NULO);
    delete(n->hizq);
    n->hizq = ABin<T>::NODO_NULO;
}

template <typename T>
inline void ABin<T>::eliminarHijoDrchoB(ABin<T>::nodo n){
    assert(n != ABin<T>::NODO_NULO);
    assert(n->hder != ABin<T>::NODO_NULO);
    assert(n->hder->hizq == ABin<T>::NODO_NULO &&
    n->hder->hder == ABin<T>::NODO_NULO);
    delete(n->hder);
    n->hder = ABin<T>::NODO_NULO;
}

template <typename T>
inline void ABin<T>::eliminarRaizB(){
    assert(r != ABin<T>::NODO_NULO); // Arbol no vacio
    assert(r->hizq == ABin<T>::NODO_NULO &&
    r->hder == ABin<T>::NODO_NULO); // la raiz es hoja
    delete(r);
    r = ABin<T>::NODO_NULO;
}

template <typename T>
inline ABin<T>::~ABin() { 
		destruirNodos(r);
}

template <typename T>
inline bool ABin<T>::arbolVacioB() const {
		return (r == ABin<T>::NODO_NULO); 
}

template <typename T>
inline T ABin<T>::elemento(ABin<T>::nodo n) const{
    assert(n != ABin<T>::NODO_NULO);
    return n->elto;
}

template <typename T>
inline T& ABin<T>::elemento(ABin<T>::nodo n)	{
    assert(n != ABin<T>::NODO_NULO);
    return n->elto;
}

template <typename T>
inline typename ABin<T>::nodo ABin<T>::raizB() const{
    return r;
}

template <typename T> inline
typename ABin<T>::nodo ABin<T>::padreB(ABin<T>::nodo n) const{
    assert(n != ABin<T>::NODO_NULO);
    return n->padre;
}

template <typename T> inline
typename ABin<T>::nodo ABin<T>::hijoIzqdoB(ABin<T>::nodo n) const{
    assert(n != ABin<T>::NODO_NULO);
    return n->hizq;
}

template <typename T> inline
typename ABin<T>::nodo ABin<T>::hijoDrchoB(ABin<T>::nodo n) const{
    assert(n != ABin<T>::NODO_NULO);
    return n->hder;
}

template <typename T>
inline ABin<T>::ABin(const ABin<T>& a) {
    r = copiar(a.r);
}

template <typename T>
ABin<T>& ABin<T>::operator =(const ABin<T>& a){
    if (this != &a){
        this->~ABin();
        r = copiar(a.r);
    }
    return *this;
}

// Metodos privados

// Destruye un nodo y todos sus descendientes
template <typename T>
void ABin<T>::destruirNodos(ABin<T>::nodo n){
    if (n != ABin<T>::NODO_NULO){
        destruirNodos(n->hizq);
        destruirNodos(n->hder);
        delete n;
    }
}

// Devuelve una copia de un nodo y todos sus descendientes
template <typename T>
typename ABin<T>::nodo ABin<T>::copiar(ABin<T>::nodo n){
    nodo m = ABin<T>::NODO_NULO;
    if (n != ABin<T>::NODO_NULO){
        m = new celda(n->elto); // copiar la raiz
        m->hizq = copiar(n->hizq);
        if (m->hizq != ABin<T>::NODO_NULO)
            m->hizq->padre = m;
        m->hder = copiar(n->hder);
        if (m->hder != ABin<T>::NODO_NULO)
            m->hder->padre = m;
    }
    return m;
}

#endif//ABIND_H
