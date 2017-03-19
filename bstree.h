#ifndef BSTREE_H
#define BSTREE_H

typedef struct{
	int value;
	char *kay;

	bstree *left;
	bstree *right;
} bstree;

bstree *bstree_create(char *key, int value);
void bstree_add(struct bstree *tree, char *key, int value);
bstree *bstree_lookup(struct bstree *tree, char *key);
bstree *bstree_min(struct bstree *tree);
bstree *bstree_max(struct bstree *tree);

#endif
