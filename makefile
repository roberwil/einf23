LIB_PREFIX=lib
LIB_POSTFIX=.a
LIB_NAME=$(LIB_PREFIX)einf23$(LIB_POSTFIX)
LIB_PATH=./lib/
CFILES=$(LIB_PATH)*.c
OFILES=./*.o
CFLAGS= -Wall -c
ARFLAGS= -cvq

all: 
	gcc $(CFLAGS) $(CFILES) einf23.c
	ar $(ARFLAGS) $(LIB_NAME) $(OFILES)
	make clean

main:
	gcc *.c ./lib/*.c -o main.out
	clear
	./main.out	

clean:
	rm $(OFILES)