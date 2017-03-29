#include "dyv.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

solucion divideVenceras(int i, int j) {
	int p;
	if (pequeno(i,j)) {
		return solucionDirecta(i);
	} else {
		p = dividir(i,j);
		return combinar(divideVenceras(i,p),divideVenceras(p+1,j));
	}
}

bool pequeno (int i, int j){
	if (i == j) {
		return true;
	} else return false;
}

solucion solucionDirecta(int i) {
	//Rellenar array C con los datos contenidos en A y B
	solucion s1;
	s1.pos = i;
	s1.valor = -1;
	s1.diferencias.insert(s1.diferencias.begin(),abs(int(a[i]) - int(b[i])));

	return s1;
}

int dividir(int i, int j) {
	int aux = j - i + 1;
	int p = ((i + (aux/2)) + (aux%2) - 1);
	return p;
}

solucion combinar(solucion s1, solucion s2) {

	solucion s3;
	vector<int> diferenciasCombinado;

	for (int i = 0; i < s1.diferencias.size(); ++i)
	{
		diferenciasCombinado.push_back(s1.diferencias.at(i));
	}

	for (int i = 0; i < s2.diferencias.size(); ++i)
	{
		diferenciasCombinado.push_back(s2.diferencias.at(i));
	}

	s3.diferencias = diferenciasCombinado;
	int limite = s3.diferencias.size();

	if (limite < m) {
		s3.pos = -1;
		s3.valor = -1;
		return s3;
	} else if (limite == m){
		int sumaTotal=0;
		for (int x = 0; x < m; ++x)
		{
			sumaTotal += diferenciasCombinado.at(x);
		}
		s3.pos = 0;
		s3.valor = sumaTotal;
		return s3;
	} else {
		int indCompr = s1.diferencias.size() - m + 1;
		int cont = 1;
		int valorCompr,sumaTotal = 0;
		int posCompr = -1;
		while ((indCompr + m) <= limite && cont < m) {
			for (int x = 0; x < m; ++x)
			{
				int aux = x+indCompr;
				//cout << "s1.dif " << s1.diferencias.size() << " s2.dif " << s2.diferencias.size() << endl;
				//cout << "x " << x << " indCompr " << indCompr << " aux " << aux << endl;
				if (aux > -1) {
					sumaTotal = sumaTotal + diferenciasCombinado.at(x+indCompr);
				}
			}
			if (sumaTotal > valorCompr) {
				posCompr = indCompr;
				valorCompr = sumaTotal;
			}
			sumaTotal=0;
			indCompr++;
			cont++;
		}
		s3.valor = max(s1.valor,max(s2.valor,valorCompr));
		if (s3.valor == s1.valor) {
			s3.pos = s1.pos;
		} else if (s3.valor == s2.valor) {
			s3.pos = s2.pos+s1.diferencias.size();
		} else {
			s3.pos = posCompr;
		}
		return s3;
	}
}