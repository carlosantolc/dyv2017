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
	/* code */
	return 0;
}


