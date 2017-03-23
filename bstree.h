#ifndef BSTREE_H
#define BSTREE_H
#include <stdlib.h>

typedef struct {
	int key;
	char *value;

	bstree *left;
	bstree *right;
} bstree;

bstree *bstree_create(int key, char *value);
void bstree_add(bstree *tree, int key, char *value);
bstree *bstree_lookup(bstree *tree, int key);
bstree *bstree_min(bstree *tree);
bstree *bstree_max(bstree *tree);

#endif
