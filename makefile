CFLAGS = -O
CC = g++

KarExec: main.o displayFunctions.o fileDataFunctions.o
	$(CC) $(CFLAGS) -o KarExec main.o displayFunctions.o fileDataFunctions.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

displayFunctions.o: displayFunctions.cpp
	$(CC) $(CFLAGS) -c displayFunctions.cpp

fileDataFunctions.o: fileDataFunctions.cpp
	$(CC) $(CFLAGS) -c fileDataFunctions.cpp

clean:
	rm -f core *.o KarExec
