#ifndef BSTREE_H
#define BSTREE_H
#include <stdlib.h>

typedef struct bstree{
	int key;
	char *value;

	struct bstree *left;
	struct bstree *right;
} bstree;

bstree *bstree_create(int key, char *value);
//void bstree_add(bstree *tree, int key, char *value);
//bstree *bstree_lookup(bstree *tree, int key);
//bstree *bstree_min(bstree *tree);
//bstree *bstree_max(bstree *tree);

#endif
