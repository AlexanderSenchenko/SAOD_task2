#ifndef HASHTAB_H
#define HASHTAB_H

typedef struct {
	char *value;
	int key;
	struct hashtab *next;
} listnode;

unsigned int hashtab_hash(char *value);
void hashtab_init(struct listnode **hashtab);
//void hashtab_add(struct listnode **hashtab, char *key, int value);
//struct listnode *hashtab_lookup(struct listnode **hashtab, char *key);
//void hashtab_delete(struct listnode **hashtab, char *key);

#endif
