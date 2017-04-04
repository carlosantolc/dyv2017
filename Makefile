dyv : main.cpp dyv.cpp dyv.h
	g++ main.cpp dyv.cpp dyv.h -o dyv

iterativo : iterativo.cpp
	g++ iterativo.cpp -o iterativo

generador : generador_casos.cpp
	g++ generador_casos.cpp -o generador_casos

run : prueba.txt dyv
	./dyv prueba.txt

run2 : prueba.txt iterativo
	./iterativo prueba.txt

prueba.txt : generador_casos
	./generador_casos > prueba.txt

diff : prueba.txt dyv iterativo
	./dyv prueba.txt > salidaDyv
	./iterativo prueba.txt > salidaIterativo
	diff salidaDyv salidaIterativo

clean :
	rm -f dyv iterativo generador_casos salidaIterativo salidaDyv prueba.txt
