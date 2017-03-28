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
		int posMax=-1;
		int valorMax=-1;
		int inicial=0;
		int valorAcumulado;
		while(inicial+m <= a.length()) {
			valorAcumulado=0;
			for (int j = 0; j < m; ++j)
			{
				valorAcumulado+=abs(int(a[inicial+j]) - int(b[inicial+j]));
			}
			if (valorAcumulado > valorMax)
			{
				posMax=inicial;
				valorMax=valorAcumulado;
			}
			inicial++;
		}
		cout << posMax+1 << " " << valorMax << endl;
	}
}