.PHONY: gdb

all:
	gcc -Wall -o main src/*.c

gdb:
	gcc -Wall -g -O0 -o gdbtest src/*.c
	gdb --args ./gdbtest 20000 сунутся abandonne
