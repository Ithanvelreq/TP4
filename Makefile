CC=g++
CFLAGS= -Wall -DMAP
EXEC=maintest

$(EXEC): Manager.o $(EXEC).o
	$(CC) -o maintest maintest.o Manager.o $(CFLAGS)

$(EXEC).o: Manager.cpp Manager.h

Manager.o: Manager.cpp Manager.h

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
