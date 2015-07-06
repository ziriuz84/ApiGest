OBJS = alveare.o apiario.o functions.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: apigest
	

apigest : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o apigest

main.o : main.cpp functions.h
	$(CC) $(CFLAGS) main.cpp

alveare.o : alveare.h alveare.cpp functions.h
	$(CC) $(CFLAGS) alveare.cpp

apiario.o : apiario.h apiario.cpp functions.h 
	$(CC) $(CFLAGS) apiario.cpp
    
functions.o : functions.h functions.cpp alveare.h apiario.h 
	$(CC) $(CFLAGS) functions.cpp

clean:
	\rm *.o *~ apigest
