dyv : main.cpp dyv.cpp dyv.h
	g++ main.cpp dyv.cpp dyv.h -o dyv

dyv2 : main2.cpp dyv.cpp dyv.h
	g++ main2.cpp dyv.cpp dyv.h -o dyv2

iterativo : iterativo.cpp
	g++ iterativo.cpp -o iterativo

generador : generador_casos.cpp
	g++ generador_casos.cpp -o generador_casos

run : prueba.txt dyv
	./dyv prueba.txt

run2 : prueba.txt iterativo
	./iterativo prueba.txt

tiempo : prueba.txt dyv2
	./dyv2 prueba.txt

prueba.txt : generador_casos
	./generador_casos > prueba.txt

diff : prueba.txt dyv iterativo
	./dyv prueba.txt > salidaDyv
	./iterativo prueba.txt > salidaIterativo
	diff salidaDyv salidaIterativo

completo: prueba.txt dyv dyv2 iterativo
	./dyv prueba.txt > salidaDyv
	./iterativo prueba.txt > salidaIterativo
	diff salidaDyv salidaIterativo
	./dyv2 prueba.txt

clean :
	rm -f dyv dyv2 iterativo generador_casos salidaIterativo salidaDyv prueba.txt salida.txt
