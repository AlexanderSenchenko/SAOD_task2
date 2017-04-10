#ifndef HASHTAB_H
#define HASHTAB_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *value;
	int key;
	struct hashtab *next;
} listnode;

unsigned int hashtab_hash(char *value);
//void hashtab_init(listnode **hashtab);
//void hashtab_add(listnode **hashtab, char *key, int value);
//struct listnode *hashtab_lookup(struct listnode **hashtab, char *key);
//void hashtab_delete(struct listnode **hashtab, char *key);

#endif
