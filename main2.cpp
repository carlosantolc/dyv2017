#include <iostream>
#include <fstream>
#include <string>
#include "dyv.h"
#include <sys/time.h>
using namespace std;

string a, b;
int m;
int main(int argc, char *argv[]) {

	struct timeval ti, tf; //Para la lectura del tiempo
	double tiempo;	
	remove("salidaTiempo.csv");
	std::ofstream salidaTiempo ("salidaTiempo.csv");
	string txt;
	txt = argv[1];
	ifstream fichero;
	fichero.open (txt.c_str() );
	int num_casos;
	fichero >> num_casos;
	for (int i = 0; i < num_casos; ++i) {		
		fichero >> m; fichero >> a; fichero >> b;
		tiempo = 0.0;
		gettimeofday(&ti, NULL); //Calculo del tiempo antes de analizar una cadena
		solucion final = divideVenceras(0,a.length()-1);
		gettimeofday(&tf, NULL); //Calculo del tiempo después de analizar una cadena
		tiempo += (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0; //Tiempo por caso
		salidaTiempo << m << "," << a.length() << "," << tiempo << endl;
	}
}