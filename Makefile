.PHONY: gdb

all:
	gcc -Wall -o main src/main.c src/hashtab.c

gdb:
	gcc -Wall -g -O0 -o gdbtest src/main.c src/hashtab.c
	gdb --args ./gdbtest 2
