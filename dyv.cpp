#include "dyv.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//Algoritmo general, dividimos en 2 partes
solucion divideVenceras(int i, int j) {
	int p;
	if (pequeno(i,j)) {
		return solucionDirecta(i);
	} else {
		p = dividir(i,j);
		return combinar(divideVenceras(i,p),divideVenceras(p+1,j));
	}
}

//Es pequeño cuando el tamaño del array es de 1 posicion
bool pequeno (int i, int j){
	if (i == j) {
		return true;
	} else return false;
}

/* Calculamos la suma de la diferencia y lo almacenamos en nuestra estructura de datos
donde pos es la inicial (0), el valor es -1 si es caso base. además tenemos un vector
auxiliar en el que tenemos el calculo para para cada posicion */
solucion solucionDirecta(int i) {
	solucion s1;
	s1.pos = i;
	// -1 si es caso base
	s1.valor = -1;
	//Suma de la diferencia en valor absoluto
	s1.diferencias.insert(s1.diferencias.begin(),abs(int(a[i]) - int(b[i])));

	return s1;
}

/* Dividimos en 2 partes, si la división no es entera, la subcadena de mayor longitud
irá a la izquierda */
int dividir(int i, int j) {
	int aux = j - i + 1;
	// División y módulo
	int p = ((i + (aux/2)) + (aux%2) - 1);
	return p;
}

// Combina las soluciones dependiendo de m
solucion combinar(solucion s1, solucion s2) {

	solucion s3;
	s3.diferencias.clear();
	
	// Juntamos las dos estructuras en una sola
	for (int i = 0; i < s1.diferencias.size(); ++i)
	{
		s3.diferencias.push_back(s1.diferencias.at(i));
	}

	for (int i = 0; i < s2.diferencias.size(); ++i)
	{
		s3.diferencias.push_back(s2.diferencias.at(i));
	}
	int limite = s3.diferencias.size();
	
	// Si m es menor que el tamaño seguimos subiendo
	if (limite < m) {
		s3.pos = -1;
		s3.valor = -1;
		return s3;
	// si m es igual al tamaño, se realiza la suma de toda la cadena
	} else if (limite == m){
		int sumaTotal=0;
		for (int x = 0; x < m; ++x)
		{
			sumaTotal += s3.diferencias.at(x);
		}
		s3.pos = 0;
		s3.valor = sumaTotal;
		return s3;
	// m es mayor que el tamaño de la cadena
	} else {
		int indCompr = s1.diferencias.size() - m + 1;
		int cont = 1;
		int valorCompr = 0;
		int sumaTotal = 0;
		int posCompr = -1;
		/* Se realizan las comprobaciones intermedias de la frontera desde la solucion
		de s1 hasta la solucion de 2, al acabar nos quedamos con el mayor */
		while ((indCompr + m) <= limite && cont < m) {
			for (int x = 0; x < m; ++x)
			{
				int aux = x+indCompr;
				if (indCompr > -1) {
					sumaTotal = sumaTotal + s3.diferencias.at(x+indCompr);
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
		// Ahora nos quedamos con el mayor entre s1, s2 y el mayor obtenido arriba
		int maximo = max(s1.valor,max(s2.valor,valorCompr));

		//Asignamos el valor y posicion correctos a la estructura solucion s3
		if (maximo == s1.valor) {
			s3.valor = maximo;
			if (s1.pos == -1) {
				s3.pos = posCompr;
			} else {				
				s3.pos = s1.pos;
			}
		} else if (maximo == valorCompr) {
			s3.pos = posCompr;
			s3.valor = maximo;
		} else {
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
