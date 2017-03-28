#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>    
#include <vector> 

using namespace std;

extern string a,b;
extern int m;

typedef struct{
	int pos;
	int valor;
	vector<int> diferencias;
}solucion;

solucion divideVenceras(int, int);
bool pequeno(int, int);
solucion solucionDirecta(int);
void insertar(int, int);
int dividir(int, int);
solucion combinar(solucion, solucion);