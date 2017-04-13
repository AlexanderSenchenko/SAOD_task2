#ifndef HASHTAB_H
#define HASHTAB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode{
	char *key;
	int value;
	struct listnode *next;
} listnode;

unsigned int hashtab_hash(char *key);
void hashtab_init(listnode **hashtab);
void hashtab_add(listnode **hashtab, char *key, int value);
listnode *hashtab_lookup(listnode **hashtab, char *key);
void hashtab_delete(listnode **hashtab, char *key);

#endif
