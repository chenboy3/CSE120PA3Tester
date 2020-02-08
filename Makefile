# Makefile to compile Umix Programming Assignment 3 (pa3) [updated: 1/4/18]

LIBDIR = $(UMIXPUBDIR)/lib

CC      = cc
FLAGS   = -g -L$(LIBDIR) -lumix3

ALL =   pa3a pa3b pa3c pa3d massivetest

all:		$(ALL)

pa3a:   pa3a.c aux.h umix.h mycode3.o
	$(CC) $(FLAGS) -o pa3a pa3a.c mycode3.o

pa3b:   pa3b.c aux.h umix.h mycode3.o
	$(CC) $(FLAGS) -o pa3b pa3b.c mycode3.o

pa3c:   pa3c.c aux.h umix.h mycode3.o
	$(CC) $(FLAGS) -o pa3c pa3c.c mycode3.o

pa3d:   pa3d.c aux.h umix.h mycode3.o
	$(CC) $(FLAGS) -o pa3d pa3d.c mycode3.o

# not compiling for WI 2020
# semtest: semtest.c aux.h umix.h mycode3.o
	# gcc -std=c99 -o semtest semtest.c mycode3.o

massivetest: massivetest.c aux.h umix.h  mycode3.o
	$(CC) $(FLAGS) -o massivetest massivetest.c mycode3.o

mycode3.o:    mycode3.c aux.h sys.h mycode3.h
	$(CC) $(FLAGS) -c mycode3.c

clean:
	rm -f *.o $(ALL)

