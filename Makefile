CC=g++
CFLAGS=-W -Wall -ansi -pedantic -DMAP
EXEC=maintest
all: $(EXEC)

$(EXEC): $(EXEC).o Manager.o
	$(CC) -o $@ $^ $(LDFLAGS)	

$(EXEC).o: $(EXEC).cpp
Manager.o: Manager.cpp Manager.h

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)
