#include "hashtab.h"

unsigned int hashtab_hash(char *key)
{
	unsigned int value = 0;

	for (int i = 0; key[i] != '\0'; i++) {
		value += key[i];		
	}

	return value % 100;
}

void hashtab_init(listnode **hashtab)
{
	for (int i = 0; i < 100; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(listnode **hashtab, char *key, int value)
{
	listnode *node;

	unsigned int index = value; //hashtab_hash(key);

	node = malloc(sizeof(*node));

	if (node != NULL) {
		node->value = value;
		node->key = key;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

//listnode *hashtab_lookup(listnode **hashtab, char *key)
//void hashtab_delete(struct listnode **hashtab, char *key)
