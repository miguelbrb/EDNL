#ifndef FIGURAPLANA_H_
#define FIGURAPLANA_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Agen.h"
using namespace std;

enum Color{B,N,I};

struct cerda{
	
	Color c;
	double XI, YI, XD, YD;
	cerda(Color c_, double XI_, double YI_, double XD_, double YD_): c(c_), XI(XI_), YI(YI_), XD(XD_), YD(YD_){}
};

typedef vector<vector<Color> > FiguraPlana;

void figuraplanaRec(const Agen<cerda>& a, FiguraPlana& v, typename Agen<cerda>::nodo n);

int alturaAgenCua(const Agen<cerda>& a, typename Agen<cerda>::nodo n){

	if(n == Agen<cerda>::NODO_NULO){
	
		return -1;
	}else{
		return 1 + max(max(alturaAgenCua(a, a.hijoIzqdo(n)), 
				alturaAgenCua(a, a.hermDrcho(a.hijoIzqdo(n)))), 
			max(alturaAgenCua(a, a.hermDrcho(a.hermDrcho(a.hijoIzqdo(n)))), 
		alturaAgenCua(a, a.hermDrcho(a.hermDrcho(a.hermDrcho(a.hijoIzqdo(n)))))));
	}
}

FiguraPlana figuraplana(const Agen<cerda>& a){
	
	int k = alturaAgenCua(a, a.raiz());
	int n = pow(2,k);
	FiguraPlana vec(n,vector<Color>(n,I));
	figuraplanaRec(a, vec, a.raiz());
	return vec;
}

void figuraplanaRec(const Agen<cerda>& a, FiguraPlana& v, typename Agen<cerda>::nodo n){

	if(a.elemento(n).c != I){
		for(int i = a.elemento(n).XI; i<a.elemento(n).XD; i++){
			for(int j = a.elemento(n).YI; j<a.elemento(n).YD; j--){
				v[i][j] = a.elemento(n).c;
			}
		}
	}else{
	
		figuraplanaRec(a, v, a.hijoIzqdo(n));
		figuraplanaRec(a, v, a.hermDrcho(a.hijoIzqdo(n)));
		figuraplanaRec(a, v, a.hermDrcho(a.hermDrcho(a.hijoIzqdo(n))));
		figuraplanaRec(a, v, a.hermDrcho(a.hermDrcho(a.hermDrcho(a.hijoIzqdo(n)))));
	}
}

#endif
