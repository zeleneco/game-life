all: life.exe

life.exe: check.o main.o
	g++ check.o main.o -o life.exe

main.o: main.cpp
	g++ -c -Wall main.cpp

check.o: check.cpp
	g++ -c -Wall check.cpp

clean:
    rm -rf *.o life.exe
