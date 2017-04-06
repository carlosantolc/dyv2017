#include <iostream>
#include <fstream>
#include <string>
#include "dyv.h"
using namespace std;

string a, b;
int m;
int main(int argc, char *argv[]) {

	string txt;
	txt = argv[1];
	ifstream fichero;
	fichero.open (txt.c_str() );
	int num_casos;
	fichero >> num_casos;
	for (int i = 0; i < num_casos; ++i) {		
		fichero >> m; fichero >> a; fichero >> b;
		solucion final = divideVenceras(0,a.length()-1);
		cout << final.pos+1 << " " << final.valor << endl;
	}
}
