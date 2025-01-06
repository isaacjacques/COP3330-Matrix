main: main.o matrix.o
	g++ -o main -std=c++11 main.o matrix.o

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c -std=c++11 matrix.cpp

clean:
	rm -f *.h.gch
	rm -f *.o