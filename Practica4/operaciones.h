#include "Agen.h"
#include "ES_Agen.h"//Ejercicio 1.
#include <algorithm>
//Ejercicio 2. Grado de un Agen.
template <typename T>
int gradoAgen(const Agen<T>& a)
{
	return calculaGrado(a, a.raiz());
}

template <typename T>
int calculaGrado(const Agen<T>& a, const typename Agen<T>::nodo& n)
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
//Ejercicio 3. Profundidad
template <typename T>
int profundidadAgen(const Agen<T>& a, const typename Agen<T>::nodo n)
{
	if(n!=a.raiz()){ return 0; }
	else{
		return 1+profundidadAgenRec(a, a.padre(n));
	}
}

