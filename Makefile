.PHONY: gdb bs

all:
	gcc -Wall -o main src/*.c

bs:
	gcc -Wall -o bsmain bstree/*c

gdb:
	gcc -Wall -g -O0 -o gdbtest src/*.c
	gdb --args ./gdbtest 20000 сунутся abandonne
