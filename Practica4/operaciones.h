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

//Ejercicio 4. Desequilibrio de un Agen. 
//Son necesarias aquí 2 funciones: alturaAgenMax y alturaAgenMin, que devuelven respectivamente la altura
//maxima y minima de un Agen.

template <typename T>
int alturaAgenMax(const Agen<T>& a, const typename Agen<T>::nodo  n)
{
	if(n==Agen<T>::NODO_NULO) { return -1; }
	else{
		typename Agen<T>::nodo h=a.hijoIzqdo(n);
		int altura = alturaAgenMax(a,h);//Se calcula la altura del hijoIzqdo, que se usa como mínimo.
		while(h!=Agen<T>::NODO_NULO)
		{
			altura=max(altura, alturaAgenMax(a,a.hermDrcho(h)));//Se va calculando la altura de los hermanos y el máximo entre
													//estas alturas.
			h=a.hermDrcho(h);
		}
		return (1+altura);
	}
}

template <typename T>
int alturaAgenMin(const Agen<T>& a, const typename Agen<T>::nodo  n)
{
	if(n==Agen<T>::NODO_NULO) { return -1; }
	else{
		typename Agen<T>::nodo h=a.hijoIzqdo(n);
		int altura = alturaAgenMax(a,h);//Se calcula la altura del hijoIzqdo, que se usa como máximo.
		while(h!=Agen<T>::NODO_NULO && a.hermDrcho(h)!=Agen<T>::NODO_NULO)
		{
			altura=min(altura, alturaAgenMax(a,a.hermDrcho(h)));//La altura que se calcula es la máxima de cada nodo, para luego
													//calcular el mínimo de estas alturas máximas.
			h=a.hermDrcho(h);
		}
		return (1+altura);
	}
}

template <typename T>
int desequilibrioAgen(const Agen<T>& a)
{
	return abs(alturaAgenMax(a, a.raiz()) - alturaAgenMin(a,a.raiz()));
}

//Ejercicio 5. Poda de Agen.
//Función para la búsqueda del nodo.
template <typename T>
typename Agen<T>::nodo buscarAgen(const Agen<T>& a, typename Agen<T>::nodo n, const T& x)
{
	if(n == Agen<T>::NODO_NULO || a.elemento(n) == x){ return n; }
	else{
		typename Agen<T>::nodo encontrado = Agen<T>::NODO_NULO;
		encontrado = buscarAgen(a, a.hijoIzqdo(n), x);
		if(encontrado == Agen<T>::NODO_NULO)
		{
			return buscarAgen(a, a.hermDrcho(n), x);			
		}
		else return encontrado;
	}
}

//Función para eliminar los hijos y hermanos de un nodo.
template <typename T>
void eliminarNodos(Agen<T>& a, typename Agen<T>:: nodo n)
{
	if(n!=Agen<T>::NODO_NULO){
		if(a.hijoIzqdo(n)!=Agen<T>::NODO_NULO)//El nodo tiene hijoIzqdo.
		{
			eliminarNodos(a,a.hijoIzqdo(n));//Se poda ese hijo...
			a.eliminarHijoIzqdo(n);//... y se elimina.
		}
		if(a.hermDrcho(n)!=Agen<T>::NODO_NULO)//El nodo
		{
			eliminarNodos(a,a.hermDrcho(n));
			a.eliminarHermDrcho(n);
		}
	}
}

//Función para la poda recursiva
template <typename T>
void podaAgenRec(Agen<T>& a, typename Agen<T>:: nodo n)
{
	if(n==a.raiz())
	{
		eliminarNodos(a,a.hijoIzqdo(n));//Se elimina a los descendientes menos a su hijoIzqdo...
		a.eliminarHijoIzqdo(n);//...y ahora se elimina al hijoIzqdo.
		a.eliminarRaiz();//Por último, la raiz.
	}
	else{
		typename Agen<T>::nodo p;
		eliminarNodos(a,a.hijoIzqdo(n));//Se elimina a los descendientes menos a su hijoIzqdo...
		a.eliminarHijoIzqdo(n);//...y ahora se elimina al hijoIzqdo.
		p=a.padre(n);//Se pasa al padre.
		if(a.hijoIzqdo(p)==n){//n es el hijoIzqdo
			a.eliminarHijoIzqdo(p);
		}
		else{//n no es el hijoIzqdo... sino un hermano de este.
			p=a.hijoIzqdo(p);//Se pasa al hijoIzqdo del padre de n.
			while(a.hermDrcho(p)!=n)//Se busca n entre los hermanos.
				p=a.hermDrcho(p);
			a.eliminarHermDrcho(p);//Se elimina finalmente a n.
		}
	}
}

//Función que llama a las demás. Función de poda principal.
template <typename T>
void podaAgen(Agen<T>& a, const T& x)
{
	typename Agen<T>::nodo encontrado=buscarAgen(a,a.raiz(),x);//Busca el nodo, y lo almacena.
	if(encontrado!=Agen<T>::NODO_NULO)//Se elimina la posibilidad de "podar" nodos nulos.
	{
		podaAgenRec(a,encontrado);
		std::cout << "Nodo podado." << std::endl;
	}
	else std::cout << "Nodo no encontrado." << std::endl;
}


