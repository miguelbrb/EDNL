#ifndef EXPRESION_H
#define EXPRESION_H
#include <iostream>
#include <string>
#include <sstream>
class expresion {
	public:
		double operando;
		char operador;
		bool operator!=(const expresion&);
};

//Para poder utilizar el cin >>. Flujo de entrada.
std::istream& operator>>(std::istream& i, expresion& c)
{
    std::string a;
    i>>a;
    if(isdigit(a[0])){ //Este método comprueba si el primer caracter es numérico.
        c.operador='?';
        std::stringstream(a)>>c.operando;
    }
    else c.operador=a[0];
    return i;
}

//Flujo de salida:
std::ostream& operator<<(std::ostream& o, const expresion& c)
{
	if(c.operador=='?'){ return o << c.operando; }
	else{ return o << c.operador; }
}

bool expresion::operator!=(const expresion& e)
{
	if(operador==e.operador && operador!='?' && e.operador!='?'){return false;}
	if(operando==e.operando && operador=='?' && e.operador=='?'){return false;}
	else return true;
}
#endif
