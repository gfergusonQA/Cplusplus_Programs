CC = g++
CPPFLAGS = -std=c++11 -g -Wall

main: main.o plane.o fleet.o

main.o: main.h plane.h fleet.h

fleet.o: plane.h fleet.h

plane.o: plane.h

clean: 
	rm *.o main
