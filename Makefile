dyv : main.cpp dyv.cpp dyv.h
	g++ main.cpp dyv.cpp dyv.h -o dyv

run : prueba.txt dyv
	./dyv prueba.txt

clean :
	rm -f dyv