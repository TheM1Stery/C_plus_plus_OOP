IntArray: IntArray.o main.o
	g++ IntArray.o main.o -o main.exe
main.o: main.cpp
	g++ -c main.cpp
IntArray.o: IntArray.cpp
	g++ -c IntArray.cpp
clean:
	del *.o main.exe
