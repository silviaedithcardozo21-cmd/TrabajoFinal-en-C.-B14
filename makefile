CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
OBJETOS = main.o artemis.o validaciones.o
EJECUTABLE = artemis.exe

all: $(EJECUTABLE)

$(EJECUTABLE): $(OBJETOS)
	$(CC) $(CFLAGS) -o $(EJECUTABLE) $(OBJETOS) -lm

main.o: main.c artemis.h validaciones.h
	$(CC) $(CFLAGS) -c main.c

artemis.o: artemis.c artemis.h validaciones.h
	$(CC) $(CFLAGS) -c artemis.c

validaciones.o: validaciones.c validaciones.h
	$(CC) $(CFLAGS) -c validaciones.c

clean:
	rm -f $(OBJETOS) $(EJECUTABLE)

.PHONY: all clean

