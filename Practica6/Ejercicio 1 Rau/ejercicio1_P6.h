//Función de búsqueda en un Abin:
typename Abin<int>::nodo buscarAbin(const Abin<int>& a, typename Abin<int>::nodo n, int x)
{
	if(n == Abin<int>::NODO_NULO || a.elemento(n) == x){ return n; }
	else{
		typename Abin<int>::nodo encontrado = Abin<int>::NODO_NULO;
		encontrado = buscarAbin(a,a.hijoIzqdoB(n),x);//Busca el nodo por la izquierda...
		if(encontrado == Abin<int>::NODO_NULO){//Si no ha encontrado por la izquierda, busca por la derecha.
			return buscarAbin(a,a.hijoDrchoB(n),x);
		}
		else return encontrado;
	}
}


//Función recursiva para hundir el nodo y eliminarlo:
void eliminaElemRec(Abin<int>& a, typename Abin<int>::nodo n, int x)
{
	if(a.hijoIzqdoB(n)==Abin<int>::NODO_NULO && a.hijoDrchoB(n)==Abin<int>::NODO_NULO)
	{//Si el nodo es hoja, se elimina desde su padre (no será la raíz, se controla en la función principal.)
		if(n==a.hijoIzqdoB(a.padreB(n))) { a.eliminarHijoIzqdoB(a.padreB(n)); }
		else a.eliminarHijoDrchoB(a.padreB(n));
	}else if(a.hijoDrchoB(n)==Abin<int>::NODO_NULO){//Si solo tiene hijoIzqdo (el drcho es NULO), se pasa a esa rama:
		a.elemento(n)=a.elemento(a.hijoIzqdoB(n));//Se intercambia el elemento por el hijo...
		a.elemento(a.hijoIzqdoB(n)) = x;//... hundiendose el nodo con x.
		eliminaElemRec(a,a.hijoIzqdoB(n),x);//Llamada recursiva. Así en todos los casos.
	}else if(a.hijoIzqdoB(n)==Abin<int>::NODO_NULO){//Si solo tiene hijoDrcho, se pasa a esa rama:
		a.elemento(n)=a.elemento(a.hijoDrchoB(n));
		a.elemento(a.hijoDrchoB(n)) = x;
		eliminaElemRec(a,a.hijoDrchoB(n),x);
	}else if(a.elemento(a.hijoIzqdoB(n)) < a.elemento(a.hijoDrchoB(n))){//Si tiene ambos hijos, se mira cual es menor. Izqdo:
		a.elemento(n)=a.elemento(a.hijoIzqdoB(n));
		a.elemento(a.hijoIzqdoB(n)) = x;
		eliminaElemRec(a,a.hijoIzqdoB(n),x);
	}else{//Si no, si el derecho es menor:
		a.elemento(n)=a.elemento(a.hijoDrchoB(n));
		a.elemento(a.hijoDrchoB(n)) = x;
		eliminaElemRec(a,a.hijoDrchoB(n),x);
	}
}


//Función principal:
void eliminarElemAbin(Abin<int>& a, int x)
{
	typename Abin<int>::nodo encontrado = buscarAbin(a,a.raizB(),x);//Se busca el nodo con x.
	if(encontrado==a.raizB() && a.hijoIzqdoB(encontrado)==Abin<int>::NODO_NULO && a.hijoDrchoB(encontrado)==Abin<int>::NODO_NULO)
	{	a.eliminarRaizB();	} //Si es raíz y es hoja, elimina la raíz. En caso de encontrar algo que no sea raíz, pasa a la RECURSIVA.
	else if(encontrado != Abin<int>::NODO_NULO){//Si se ha encontrado el nodo, pero no es la raíz, llamada recursiva:
		eliminaElemRec(a,encontrado,x);
	}
}

