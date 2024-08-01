CC = g++
CPPFLAGS = -std=c++11 -g -Wall

main: tools.o plane.o fleet.o

main.o: tools.h plane.h fleet.h

fleet.o: plane.h fleet.h

plane.o: plane.h

clean: 
	rm *.o main
