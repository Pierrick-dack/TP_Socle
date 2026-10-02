CFLAGS = -Wall -Wextra

all: exercice_0

run: exercice_0
	./exercice_0

clean:
	-del /f /q exercice_0.exe exercice_0 2>nul