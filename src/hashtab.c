#include "hashtab.h"

unsigned int hashtab_hash(char *value)
{
	unsigned int key = 0;

	for (int i = 0; value[i] != '\0'; i++) {
		key = key + value[i];		
	}

	return key % 100;
}

void hashtab_init(struct listnode **hashtab)
{
	for (int i = 0; i < 100; i++) {
		hashtab[i] = NULL;
	}
}
