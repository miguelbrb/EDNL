#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include <cassert>

template <typename T>
class Lista{

	struct nodo;
	
	public:
		
		typedef nodo* posicion;
		Lista();
		Lista(const Lista<T>& l);
		Lista<T>& operator =(const Lista<T>& l);
		void insertar(const T& x, posicion p);
		void eliminar(posicion p);
		T elemento(posicion p) const;
		T& elemento(posicion p);
		posicion buscar(const T& x) const;
		posicion siguiente(posicion p) const;
		posicion anterior(posicion p) const;
		posicion primera() const;
		posicion fin() const;
		~Lista();
	
	private:
	
		struct nodo{
		
			T elto;
			nodo *ant, *sig;
			nodo(const T& e, nodo* a=0, nodo* s=0):elto(e),ant(a),sig(s){}
		};
		
		nodo* L;
		
		void copiar(const Lista<T>& l);
};

//Método privado
template <typename T>
void Lista<T>::copiar(const Lista<T>& l){

	L = new nodo(T()); //Crear el nodo cabecera
	L->sig = L;
	nodo* q = L;
	for(nodo* r = l.L->sig; r!= l.L; r = r->sig){
	
		q->sig = new nodo(r->elto, q, L);
		q = q->sig;
	}
	
	L->ant = q;
}

template <typename T>
inline Lista<T>::Lista() : L(new nodo(T())){

	L->ant = L->sig = L;//Estructura circular
}

template <typename T>
inline Lista<T>::Lista(const Lista<T>& l){

	copiar(l);
}

template <typename T>
Lista<T>& Lista<T>::operator =(const Lista<T>& l){

	if(this != &l){
	
		this->~Lista();
		copiar(l);
	}
	
	return *this;
}

template <typename T>
inline void Lista<T>::insertar(const T& x, Lista<T>::posicion p){

	p->sig = p->sig->ant = new nodo(x, p, p->sig);
	//El nuevo nodo con x queda en la posición p
}

template <typename T>
inline void Lista<T>::eliminar(Lista<T>::posicion p){

	assert(p->sig != L); //p no es fin
	nodo* q = p->sig;
	p->sig = q->sig;
	p->sig->ant = p;
	delete q;
	//El nodo siguiente queda en la posición p
}

template <typename T>
inline T Lista<T>::elemento(Lista<T>::posicion p) const{

	assert(p->sig != L); //p no es fin
	return p->sig->elto;
}

template <typename T>
inline T& Lista<T>::elemento(Lista<T>::posicion p){

	assert(p->sig != L); //p no es fin
	return p->sig->elto;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::buscar(const T& x) const{

	nodo* q = L;
	bool encontrado = false;
	while((q->sig) != L && !encontrado){
	
		if(q->sig->elto == x){
		
			encontrado = true;
		}
		else {q = q->sig;}
		}
	return q;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(Lista<T>::posicion p) const{

	assert(p->sig != L); //p no es fin
	return p->sig;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p) const{

	assert(p != L);
	return p->ant;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const{

	return L;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const{

	return L->ant;
}

//Destructor: Vacía la lista y destruye el nodo cabecera
template <typename T>
Lista<T>::~Lista(){

	nodo* q;
	while(L->sig != L){
	
		q = L->sig;
		L->sig = q->sig;
		delete q;
	}
	
	delete L;
}

#endif //LISTA_DOBLE_H
