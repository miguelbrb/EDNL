#include <iostream>
#include "Abin.h"
#include "Abb.h"
#include "leerAbb.h"
#include "ES_Abin.h"
#include "Conjuntos.h"

int main()
{	
	Abb<int> a, b;
	
	cout<<"------------INICIO LECTURA a------------"<<endl;
	leerAbb(a);
	cout<<"------------FIN LECTURA a------------"<<endl;
	
	cout<<"------------INICIO LECTURA b------------"<<endl;
	leerAbb(b);
	cout<<"------------FIN LECTURA b------------"<<endl;
	
	cout<<"------------INICIO ESCRITURA a------------"<<endl;
	imprimirAbin(Abin<int>(a));
	cout<<"------------FIN ESCRITURA a------------"<<endl;
	
	cout<<"------------INICIO ESCRITURA b------------"<<endl;
	imprimirAbin(Abin<int>(b));
	cout<<"------------FIN ESCRITURA b------------"<<endl;
	
	Abb<int> c1 = UNION(a,b);
	cout<<"------------INICIO ESCRITURA UNION------------"<<endl;
	imprimirAbin(Abin<int>(c1));
	cout<<"------------FIN ESCRITURA UNION------------"<<endl;
	
	Abb<int> c2 = INTERSECCION(a,b);
	cout<<"------------INICIO ESCRITURA INTERSECCION------------"<<endl;
	imprimirAbin(Abin<int>(c2));
	cout<<"------------FIN ESCRITURA INTERSECCION------------"<<endl;
	
	Abb<int> c3 = ROMBO(a,b);
	cout<<"------------INICIO ESCRITURA ROMBO------------"<<endl;
	imprimirAbin(Abin<int>(c3));
	cout<<"------------FIN ESCRITURA ROMBO------------"<<endl;
}
