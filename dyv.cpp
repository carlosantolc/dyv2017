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
	s3.diferencias.clear();

	for (int i = 0; i < s1.diferencias.size(); ++i)
	{
		s3.diferencias.push_back(s1.diferencias.at(i));
	}

	for (int i = 0; i < s2.diferencias.size(); ++i)
	{
		s3.diferencias.push_back(s2.diferencias.at(i));
	}
	int limite = s3.diferencias.size();

	if (limite < m) {
		s3.pos = -1;
		s3.valor = -1;
		return s3;
	} else if (limite == m){
		int sumaTotal=0;
		for (int x = 0; x < m; ++x)
		{
			sumaTotal += s3.diferencias.at(x);
		}
		s3.pos = 0;
		s3.valor = sumaTotal;
		return s3;
	} else {
		int indCompr = s1.diferencias.size() - m + 1;
		int cont = 1;
		int valorCompr = 0;
		int sumaTotal = 0;
		int posCompr = -1;
		while ((indCompr + m) <= limite && cont < m) {
			//cout << "while" << endl;
			for (int x = 0; x < m; ++x)
			{
				int aux = x+indCompr;
				//cout << "s1.dif " << s1.diferencias.size() << " s2.dif " << s2.diferencias.size() << endl;
				//cout << "x " << x << " indCompr " << indCompr << " aux " << aux << endl;
				if (indCompr > -1) {
					sumaTotal = sumaTotal + s3.diferencias.at(x+indCompr);
				}
			}
			if (sumaTotal > valorCompr) {
				//cout << "actualiza " << indCompr << " " << sumaTotal << endl;
				posCompr = indCompr;
				valorCompr = sumaTotal;
			}
			sumaTotal=0;
			indCompr++;
			cont++;
		}
		int maximo = max(s1.valor,max(s2.valor,valorCompr));
		//s3.valor = max(s1.valor,max(s2.valor,valorCompr));

			//cout << "AQUI 0" << endl;
		if (maximo == s1.valor) {
			//cout << "AQUI 1" << endl;
			s3.valor = maximo;
			if (s1.pos == -1) {
				s3.pos = posCompr;

			//cout << "AQUI 2" << endl;
			} else {				
				s3.pos = s1.pos;

			//cout << "AQUI 3" << endl;
			}
		} else if (maximo == valorCompr) {
			//cout << "AQUI 4 " << posCompr << " " << maximo << endl;
			s3.pos = posCompr;
			s3.valor = maximo;
		} else {

			//cout << "AQUI 5" << endl;
			s3.valor = maximo;			
			if (s2.pos == -1) {
				s3.pos = posCompr;
			} else {
				s3.pos = s2.pos+s1.diferencias.size();
			}
		}
		return s3;
	}
}
