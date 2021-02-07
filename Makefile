CC=g++
CFLAGS= -Wall -DMAP
EXEC=main

$(EXEC): Manager.o $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o Manager.o $(CFLAGS)

$(EXEC).o: Manager.cpp Manager.h

Manager.o: Manager.cpp Manager.h

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)
