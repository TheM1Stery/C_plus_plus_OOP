House: human.o house.o flat.o main.o
	g++ human.o house.o flat.o main.o -o main.exe
human.o: human.cpp
	g++ -c human.cpp
house.o : house.cpp
	g++ -c house.cpp
flat.o: flat.cpp
	g++ -c flat.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	del *.o main.exe