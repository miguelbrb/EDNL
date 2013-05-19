
#include "Abb.h"
#include "Abin.h"

typedef Abb<int> Conjunto;

//Ejercicio 3. P5.
Conjunto UNION(const Conjunto& c1, const Conjunto& c2)
{
	Conjunto cA=c1, cR=c2;
	while(!cA.vacio()){
		int elem = Abin<int>(cA).elemento(Abin<int>(cA).raizB());
		cR.insertar(elem);//Inserta todos los elementos de cA en cR, que tiene los elementos de c2.
		cA.eliminar(elem);
	}	
	return cR;
}
//Ejercicio 4. P5.
Conjunto INTERSECCION(const Conjunto& c1, const Conjunto& c2)
{
	Conjunto cA=c1, cR;
	while(!cA.vacio()){
		int elem = Abin<int>(cA).elemento(Abin<int>(cA).raizB());
		if(c2.buscar(elem)!=Abb<int>::NODO_NULO){//Elementos comunes.
			cR.insertar(elem);
		}
		cA.eliminar(elem);
	}	
	return cR;
}
//Ejercicio 5. P5.
Conjunto ROMBO(const Conjunto& c1, const Conjunto& c2)
{
	Conjunto u=UNION(c1,c2), i=INTERSECCION(c1,c2);
	Conjunto R;//Resultado.
	
	while(!u.vacio()){
		int elem = Abin<int>(u).elemento(Abin<int>(u).raizB());
		if(i.buscar(elem)==Abb<int>::NODO_NULO){//Elementos no comunes.
			R.insertar(elem);
		}
		u.eliminar(elem);
	}	
	return R;
}

