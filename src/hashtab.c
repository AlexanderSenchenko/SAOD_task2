#include "hashtab.h"

unsigned int hashtab_hash(char *value)
{
	unsigned int key = 0;

	for (int i = 0; value[i] != '\0'; i++) {
		key = key + value[i];		
	}

	return key % 100;
}

void hashtab_init(listnode **hashtab)
{
	*hashtab = malloc(100 * sizeof(listnode));

	for (int i = 0; i < 100; i++) {
		(*hashtab)[i] = NULL;
	}
}

//void hashtab_add(listnode **hashtab, char *key, int value)
//listnode *hashtab_lookup(listnode **hashtab, char *key)
//void hashtab_delete(struct listnode **hashtab, char *key)
