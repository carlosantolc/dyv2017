/*Archivo donde se generarán las pruebas necesarias según:
	Número de casos: S
	Tamaño de las cadenas: N
	Tamaño de la subcadena: M
	Creando dos arrays de tamaño N y una cifra M, S veces
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

static const char alfabeto[] =
"abcdefghijklmnopqrstuvwxyz";

char genRandom()
{
    return alfabeto[rand() % (sizeof(alfabeto) - 1)];
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int m[9] = {2,5,10,20,50,100,200,500,1000};

	cout << "9000" << endl;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 100; j <= 100000; j+=100)
		{
			cout << m[i] << endl;
			for (int k = 0; k < 2; ++k)
			{
				for (int y = 0; y < j; ++y)
				{
					cout << genRandom();
				}
				cout << endl;
			}
		}
	}
	return 0;
}
