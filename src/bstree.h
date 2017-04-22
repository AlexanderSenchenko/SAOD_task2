#ifndef BSTREE_H
#define BSTREE_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct bstree {
	char *key;
	struct bstree *left;
	struct bstree *right;
} bstree;

bstree *bstree_create(char *key);
void bstree_add(bstree *tree, char *key);
bstree *bstree_lookup(bstree *tree, char *key);
bstree *bstree_min(bstree *tree);
bstree *bstree_max(bstree *tree);

#endif
