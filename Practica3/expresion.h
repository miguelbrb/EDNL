#ifndef EXPRESION_H
#define EXPRESION_H
#include <iostream>
class expresion {
	public:
		double operando;
		char operador;
};

//Para poder utilizar el cin >>. Flujo de entrada.
std::istream& operator>>(std::istream& i, expresion& c)
{
	char sn;
	std::cout << "Es un operador? (s/n)" << std::endl;
	i >> sn;
	if(sn=='s'){
		std::cout << "Introduce el operador: " << std::endl;
		i >> c.operador;
		c.operando=0;//Valor asignado para no dejar sin inicializar el atributo. No se utilizará.
	}
	else{
		std::cout << "Introduce el operando: " << std::endl;
		i >> c.operando;
		c.operador='?';//Valor asignado para no dejar sin inicializar el atributo.
	}
	return i;
}

//Flujo de salida:
std::ostream& operator<<(std::ostream& o, const expresion& c)
{
	if(c.operador=='?'){ return o << c.operando; }
	else{ return o << c.operador; }
}
#endif
