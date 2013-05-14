void eliminar(T e, Abin<T>& a)
{
	typename Abin<T>::nodo n;
	n=buscar(e,a);

	if(a.hijoIzqdoB(n)!=Abin<T>::NODO_NULO || a.hijoDrchoB(n)!=Abin<T>::NODO_NULO)
	{
		T &etiqueta=a.elemento(n);
		etiqueta=minimo(n, a);
	}
	else{
		if(n==a.raizB())
		{
			a.eliminarRaizB();
		}
		else{
			typename Abin<T>::nodo padre=a.padreB(n);
			if(n==a.hijoIzqdoB(padre)){
				a.eliminarHijoIzqdoB(padre);
			}
			if(n==a.hijoDrchoB(padre)){
				a.eliminarHijoDrchoB(padre);
			}
		}
	}
}





