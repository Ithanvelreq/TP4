CC=g++
CFLAGS=
EXEC=main

$(EXEC): Decoder.o Manager.o $(EXEC).o
	$(CC) -o $(EXEC) $(EXEC).o Manager.o Decoder.o $(CFLAGS)

%.o: %.cpp %.h
	$(CC) -o $@ -c $< $(CFLAGS)
