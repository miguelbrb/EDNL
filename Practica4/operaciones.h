#include "Agen.h"
#include "ES_Agen.h"
#include <algorithm>

template <typename T>
int gradoAgen(const Agen<T>& a)
{
	return calculaGrado(a, a.raiz());
}

template <typename T>
int calculaGrado(const Agen<T>& a, typename const Agen<T>::nodo& n)
{
	int grado = 0;
	if(n==Agen<T>::NODO_NULO){ return 0; }
	else{
		typename Agen<T>::nodo aux=n;//aux es copia de n.
		while(a.hermDrcho(aux)!=Agen<T>::NODO_NULO)//Mientras aux tenga hermanos:
		{
			++grado;//Se incrementa el grado según tenga hermanos.
			aux=a.hermDrcho(aux);//Se pasa a su hermano.
		}
	}
	return max(calculaGrado(a, a.hijoIzqdo(n)), max(calculaGrado(a, a.hermDrcho(n)), ++grado));
	//Si resultase que n no tiene hermanos, su grado sería 1, por el "++grado" de la llamada recursiva.
	//El grado resultante es el máximo del grado de los hijos de n, y de los hijos de sus hermanos.
}

template <typename T>
int profundidadAgen(const Agen<T>& a, typename const Agen<T>::nodo n)
{
	if(n!=a.raiz()){ return 0; }
	else{
		return 1+profundidadAgenRec(a, a.padre(n));
	}
}

template <typename T>
int desequilibrioAgen(const Agen<T>& A)
{
	return desequilibrioMAX(A,A.raizB());
}
template <typename T>
int desequilibrioMAX(const Agen<T>& A, const typename Agen<T>::nodo n)
{
    if(n==Abin<T>::NODO_NULO){return 0;}
    else
    {
        int deseq_nodo=abs(A.altura(A.hijoIzqdoB(n)) - A.altura(A.hijoDrchoB(n)));
        return max(deseq_nodo,max(desequilibrioMAX(A,A.hijoIzqdoB(n)),desequilibrioMAX(A,A.hijoDrchoB(n))));
    }
}
