CC      = clang
CFLAGS  = -g -Wall
RM      = rm -f


default: all

all: main.exe

main.exe: main.c cache.o cache.h moneyIntStr.o
	$(CC) $(CFLAGS) -o main.exe main.c cache.o moneyIntStr.o

clean veryclean:
	$(RM) main.exe
	$(RM) main.ilk
	$(RM) main.pdb
	$(RM) *.o

debug: main.c
	$(CC) $(CFLAGS) -o main.exe main.c -DDEBUG

test: main.exe
	./main.exe