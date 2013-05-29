#include <iostream>
#include "Agen.h"
#include "ES_Agen.h"
#include "6.6_FiguraPlana.h"

using namespace std;
typedef vector<vector<Color> > FiguraPlana;

enum Color;
struct cerda;

int main(){
	Agen<cerda> a;
	leerAgen(a);
	cout<<"FIN LECTURA"<<endl;
	
	cout<<"Altura de aCuar es "<<alturaAgenCua(a, a.raiz())<<endl;
	FiguraPlana matriz=figuraplana(a);
	
	cout<<"--------------La figura plana asociada es: ----------------" << endl;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){	 	
	 		cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}
