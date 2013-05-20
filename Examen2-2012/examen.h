#include "Abin.h"

template <typename T>
bool AbinEsAbb(const Abin<T>& a)
{
	if(a.arbolVacioB()){ return true; }//Arbol vacío. Es un Abb vacío ;)
	else{
		return AbinEsAbbRec(a, a.raizB());
	} 
}

//Recibe un árbol, un nodo n. Si n=a.raizB(), entonces p=NODO_NULO. 
template <typename T>
bool AbinEsAbbRec(const Abin<T>& a, const typename Abin<T>::nodo n)
{
	//NO SE HARÁN LLAMADAS RECURSIVAS A NODOS_NULOS!!! SE CONTROLAN CON LAS CONDICIONES!!
	//Utilizo "alias" para simplificar código y hacerlo más legible... es igual de eficiente.
	//... o incluso menos, porque se hacen las llamadas una sola vez, no tantas como en las comparaciones.
	typename Abin<T>::nodo hizq=a.hijoIzqdoB(n);//hijoIzqdoB
	typename Abin<T>::nodo hder=a.hijoDrchoB(n);//hijoDrchoB
	typename Abin<T>::nodo nulo=Abin<T>::NODO_NULO;//nodo nulo
	//En caso de que no cumpla la definición de Abb será, false. Por defecto, será true.
	if(n==a.raizB()){//La raiz no tiene padre, por eso es una condición especial.
		if(hizq!=nulo && a.elemento(hizq) < a.elemento(n) && hder!=nulo && a.elemento(hder) > a.elemento(n))
		{//Ambos hijos cumplen la condición.
			return AbinEsAbbRec(a,hizq) && AbinEsAbbRec(a,hder);//Llamada recursiva a ambas ramas.
		}
		else if(hizq==nulo && hder!=nulo && a.elemento(hder) > a.elemento(n))
		{
			return AbinEsAbbRec(a,hder); //Solo rama derecha. La otra no existe.
		}
		else if(hder==nulo && hizq!=nulo && a.elemento(hizq) < a.elemento(n))
		{
			return AbinEsAbbRec(a,hizq);//Solo rama izquierda. La otra no existe.
		}
		else if(hizq==nulo && hder==nulo)
		{
			return true;//No tiene hijos. Por defecto, era true.
		}
		else{//Tiene algún hijo, PERO INCUMPLE la definición de Abb. Por tanto, ya es false.
			return false;
		}
	}//if de la raiz. Ahora, para el resto de casos, en los que se comprueba el padre.
	//Ahora, n NO ES LA RAIZ. Solo cambia que hay que comprobar al padre... pero cada rama es distinta.
	else{
	typename Abin<T>::nodo p=a.padreB(n);//p es el padre de n.
	if(n==a.hijoIzqdoB(p))//n es el hijoIzqdoB de su padre.
	{//Hay que comprobar ahora con especial cuidado que el hijoDrchoB(n) siempre sea menor que p.
		//El hijoIzqdoB(n), si cumple la condición, será también menor que p, porque será menor que n.
		if(hizq!=nulo && a.elemento(hizq) < a.elemento(n) && hder!=nulo && a.elemento(hder) > a.elemento(n) && a.elemento(hder) < a.elemento(p))
		{//Ambos hijos cumplen la condición. Además, hder es menor que el padre de n. IMPORTANTE ESTO.
			return AbinEsAbbRec(a,hizq) && AbinEsAbbRec(a,hder);//Llamada recursiva a ambas ramas.
		}
		else if(hizq==nulo && hder!=nulo && a.elemento(hder) > a.elemento(n) && a.elemento(hder) < a.elemento(p))
		{//hder es menor que el padre de n. IMPORTANTE ESTO.
			return AbinEsAbbRec(a,hder); //Solo rama derecha. La otra no existe.
		}
		else if(hder==nulo && hizq!=nulo && a.elemento(hizq) < a.elemento(n))
		{//hizq va a ser menor que el padre de n si es menor que n.
			return AbinEsAbbRec(a,hizq);//Solo rama izquierda. La otra no existe.
		}
		else if(hizq==nulo && hder==nulo)
		{
			return true;//No tiene hijos. Por defecto, era true.
		}
		else{//Tiene algún hijo, PERO INCUMPLE la definición de Abb. Por tanto, ya es false.
			return false;
		}
	}// n NO es el hijoIzqdoB(p)...
	else if(n==a.hijoDrchoB(p))//n es el hijoDrchoB de su padre.
	{//Hay que comprobar ahora con especial cuidado que el hijoIzqdoB(n) siempre sea mayor que p.
		//El hijoDrchoB(n), si cumple la condición, será también mayor que p, porque será mayor que n.
		if(hizq!=nulo && a.elemento(hizq) < a.elemento(n) && a.elemento(hizq) > a.elemento(p) && hder!=nulo && a.elemento(hder) > a.elemento(n))
		{//Ambos hijos cumplen la condición. Además, hizq es mayor que el padre de n. IMPORTANTE ESTO.
			return AbinEsAbbRec(a,hizq) && AbinEsAbbRec(a,hder);//Llamada recursiva a ambas ramas.
		}
		else if(hizq==nulo && hder!=nulo && a.elemento(hder) > a.elemento(n))
		{//hder va a ser mayor que el padre de n si es mayor que n.
			return AbinEsAbbRec(a,hder); //Solo rama derecha. La otra no existe.
		}
		else if(hder==nulo && hizq!=nulo && a.elemento(hizq) < a.elemento(n) && a.elemento(hizq) > a.elemento(p))
		{//hizq es mayor que el padre de n. IMPORTANTE ESTO. && a.elemento(hder) < a.elemento(p)
			return AbinEsAbbRec(a,hizq);//Solo rama izquierda. La otra no existe.
		}
		else if(hizq==nulo && hder==nulo)
		{
			return true;//No tiene hijos. Por defecto, era true.
		}
		else{//Tiene algún hijo, PERO INCUMPLE la definición de Abb. Por tanto, ya es false.
			return false;
		}
	}
	}//else de raiz.
}
