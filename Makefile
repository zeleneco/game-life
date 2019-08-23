all: life.exe

life.exe: check.o main.o
	g++ -fpermissive check.o main.o -o life.exe

main.o: main.cpp
	g++ -fpermissive -c -Wall main.cpp

check.o: check.cpp
	g++ -fpermissive -c -Wall check.cpp

clean:
	rm -rf *.o life.exe
