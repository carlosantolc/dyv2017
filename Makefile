dyv : main.cpp dyv.cpp dyv.h
	g++ main.cpp dyv.cpp dyv.h -o dyv

iterativo : iterativo.cpp
	g++ iterativo.cpp -o iterativo

run : prueba.txt dyv
	./dyv prueba.txt

run2 : prueba.txt iterativo
	./iterativo prueba.txt

diff : prueba.txt dyv iterativo
	./dyv prueba.txt > salidaDyv
	./iterativo prueba.txt > salidaIterativo
	diff salidaDyv salidaIterativo

diff2 :prueba2.txt dyv iterativo
	./dyv prueba2.txt > salidaDyv2
	./iterativo prueba2.txt > salidaIterativo2
	diff salidaDyv2 salidaIterativo2


clean :
	rm -f dyv iterativo salidaIterativo salidaDyv
