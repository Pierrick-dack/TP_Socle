CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iexo0

all: exo0/test exo2/main exo3/main

exo0/test: exo0/test.c exo0/annuaire.h
	$(CC) $(CFLAGS) -o exo0/test exo0/test.c

exo2/main: exo2/main.c exo2/sequentiel.c exo0/annuaire.h
	$(CC) $(CFLAGS) -o exo2/main exo2/main.c exo2/sequentiel.c

exo3/main: exo3/main.c exo2/sequentiel.c exo0/annuaire.h
	$(CC) $(CFLAGS) -o exo3/main exo3/main.c exo2/sequentiel.c

clean:
	rm -f exo0/*.o exo0/test exo0/test.exe exo2/*.o exo2/main exo2/main.exe exo3/*.o exo3/main exo3/main.exe 