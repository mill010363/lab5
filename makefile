main: HugeInt.o main.o 
	g++ -o main main.o HugeInt.o

h2.o: HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp

main.o: main.cpp HugeInt.h
	g++ -c main.cpp

clean:
	rm main *.o