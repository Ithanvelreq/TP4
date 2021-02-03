CC=g++
CFLAGS= -Wall -DMAP
EXEC=maintest

$(EXEC): Manager.o maintest.o
	$(CC) -o maintest maintest.o Manager.o $(CFLAGS)

maintest.o: maintest.cpp Manager.cpp Manager.h
	$(CC) -c -o maintest.o maintest.cpp $(CFLAGS)

Manager.o: Manager.cpp Manager.h
	$(CC) -c -o Manager.o Manager.cpp $(CFLAGS)
