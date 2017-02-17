# super easy makefile

ODIR=obj
BDIR=../bin
CC=gcc

hw1: $(ODIR)/hw1.o
	$(CC) -o $(BDIR)/hw1 $(ODIR)/hw1.o

$(ODIR)/hw1.o: hw1.c
	$(CC) -o $(ODIR)/hw1.o -c hw1.c

clean:
	rm -f $(ODIR)/*.o $(BDIR)/hw1
