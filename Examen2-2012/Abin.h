#ifndef ABIN_H
#define ABIN_H
#include <cassert>
// Usando celdas enlazadas

template <typename T> class Abin {
    struct celda;   // declaracion adelantada privada
    public:
        typedef celda* nodo;
        static const nodo NODO_NULO;
        Abin();                                // constructor
        void crearRaizB(const T& e);
        void insertarHijoIzqdoB(nodo n, const T& e);
        void insertarHijoDrchoB(nodo n, const T& e);
        void eliminarHijoIzqdoB(nodo n);
        void eliminarHijoDrchoB(nodo n);
        void eliminarRaizB();
        ~Abin();                               // destructor
        bool arbolVacioB() const;
        T  elemento(nodo n) const; // acceso a elto, lectura
        T& elemento(nodo n);       // acceso a elto, lectura/escritura
        nodo raizB() const;nodo padreB(nodo n) const;
        nodo hijoIzqdoB(nodo n) const;
        nodo hijoDrchoB(nodo n) const;
        Abin(const Abin<T>& a);                // ctor. de copia
        Abin<T>& operator =(const Abin<T>& a); //asignacion de arboles
        //Ejercicio 5.
        int altura(nodo n) const;
        int profundidad(nodo n) const;
        
    private:
        struct celda {
            T elto;
            nodo padre, hizq, hder;
            celda(const T& e, nodo p = NODO_NULO): elto(e),
            padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
            };
        nodo r;   // nodo raiz del arbol
        void destruirNodos(nodo& n);
        nodo copiar(nodo n);
    };
            
    /* Definicion del nodo nulo */
    template <typename T>
    const typename Abin<T>::nodo Abin<T>::NODO_NULO(0);
    
    template <typename T>
    inline Abin<T>::Abin() : r(NODO_NULO) {}
      
    template <typename T>    
    inline void Abin<T>::crearRaizB (const T& e)    
    {    
        assert(r == NODO_NULO);   // arbol vacio    
        r = new celda(e);   
    }   
    
    template <typename T>   
    inline void Abin<T>::insertarHijoIzqdoB(Abin<T>::nodo n,const T& e)    
    {    
        assert(n != NODO_NULO);   
        assert(n->hizq == NODO_NULO);// no existe hijo    
        n->hizq = new celda(e, n);
    }
    
    template <typename T> inline
    void Abin<T>::insertarHijoDrchoB(Abin<T>::nodo n, const T& e)
    {
        assert(n != NODO_NULO);
        assert(n->hder == NODO_NULO);  // no existe hijo
        n->hder = new celda(e, n);
    }
    
    template <typename T>
    inline void Abin<T>::eliminarHijoIzqdoB(Abin<T>::nodo n)
    {
        assert(n != NODO_NULO);
        assert(n->hizq != NODO_NULO);   // existe hijo izqdo.
        assert(n->hizq->hizq == NODO_NULO &&   // hijo izqdo. 
        n->hizq->hder == NODO_NULO);    // es hoja
        delete(n->hizq);
        n->hizq = NODO_NULO;
    }
    
    template <typename T>
    inline void Abin<T>::eliminarHijoDrchoB(Abin<T>::nodo n)
    {
        assert(n != NODO_NULO);
        assert(n->hder != NODO_NULO);   // existe hijo drcho.
        assert(n->hder->hizq == NODO_NULO &&   // hijo drcho.
        n->hder->hder == NODO_NULO);    // es hoja
        delete(n->hder);
        n->hder = NODO_NULO;
    }
    
    template <typename T>
    inline void Abin<T>::eliminarRaizB()
    {
        assert(r != NODO_NULO);   // arbol no vacio
        assert(r->hizq == NODO_NULO &&
        r->hder == NODO_NULO);   // la raiz es hoja
        delete(r);
        r = NODO_NULO;
    }
    
    template <typename T> inline Abin<T>::~Abin()
    {
        destruirNodos(r); // vacia el arbol
    }
    
    template <typename T> inline bool Abin<T>::arbolVacioB() const
    { return (r == NODO_NULO); }
    
    template <typename T>
    inline T Abin<T>::elemento(Abin<T>::nodo n) const
    {
        assert(n != NODO_NULO);
        return n->elto;
    }
    
    template <typename T>
    inline T& Abin<T>::elemento(Abin<T>::nodo n)
    {
        assert(n != NODO_NULO);
        return n->elto;
    }
    
    template <typename T>
    inline typename Abin<T>::nodo Abin<T>::raizB() const
    {
     return r;
    }
    
    template <typename T> 
    inline typename Abin<T>::nodo Abin<T>::padreB(Abin<T>::nodo n) const
    {
        assert(n != NODO_NULO);
        return n->padre;
    }
    
    template <typename T> 
    inline typename Abin<T>::nodo Abin<T>::hijoIzqdoB(Abin<T>::nodo n) const
    {
        assert(n != NODO_NULO);
        return n->hizq;
    }
    
    template <typename T> inline
    typename Abin<T>::nodo Abin<T>::hijoDrchoB(Abin<T>::nodo n) const
    {
        assert(n != NODO_NULO);
        return n->hder;
    }
    
    template <typename T>
    inline Abin<T>::Abin(const Abin<T>& a)
    { r = copiar(a.r); }
    
    template <typename T>
    Abin<T>& Abin<T>::operator =(const Abin<T>& a)
    {
        if (this != &a) {   // evitar autoasignacion
           this->~Abin();   // vaciar el arbol
           r = copiar(a.r);
        }
        return *this;
    }// Metodos privados
    // Destruye un nodo y todos sus descendientes
    
    template <typename T>
    void Abin<T>::destruirNodos(Abin<T>::nodo& n)
    {
        if (n != NODO_NULO) {
           destruirNodos(n->hizq);
           destruirNodos(n->hder);
           delete n;
           n = NODO_NULO;
        }
    }// Devuelve una copia de un nodo y todos sus descendientes
    
    template <typename T>
    typename Abin<T>::nodo Abin<T>::copiar(Abin<T>::nodo n)
    {
        nodo m = NODO_NULO;
        if (n != NODO_NULO) {
            m = new celda(n->elto);    // copiar n
            m->hizq = copiar(n->hizq); // copiar subarbol izqdo.
            if (m->hizq != NODO_NULO)
               m->hizq->padre = m;
            m->hder = copiar(n->hder); // copiar subárbol drcho.
            if (m->hder != NODO_NULO)
               m->hder->padre = m;
        }
    return m;
    }
    
//EJERCICIO 5. AÑADIDOS METODOS ALTURA Y PROFUNDIDAD.
//***************************************************
//Recibe un nodo. Si se quiere la altura del arbol, se da la raiz.
template <typename T>
int Abin<T>::altura(Abin<T>::nodo n) const
{
	if(n==NODO_NULO){ return -1; }
	else{
		return (1+max(altura(n->hizq),altura(n->hder)));
	}
}

//Recibe un nodo, y se va subiendo en la jerarquia.
template <typename T>
int Abin<T>::profundidad(Abin<T>::nodo n) const
{
	if(n==r){ return 0; }//El nodo es la raiz.
	else{
		return (1+profundidad(n->padre));
	}

}
  
#endif // ABIN_H
