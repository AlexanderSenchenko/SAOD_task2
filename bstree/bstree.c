#include "bstree.h"

bstree *bstree_create(char *key)
{
	bstree *node;
	char *test = malloc(sizeof(char) * 20);
	strcpy(test, key);

	node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = test;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	return NULL;
}

void bstree_add(bstree *tree, char *key)
{
	bstree *parent, *node;
	if (tree == NULL) {
		return;
	}

	for (parent = tree; tree != NULL; ) {
		parent = tree;
		if (strcmp(tree->key, key) < 0) {
			tree = tree->left;
		}
		else if (strcmp(tree->key, key) > 0) {
			tree = tree->right;
		}
		else {
			return;
		}
	}

	node = bstree_create(key);
	if (strcmp(parent->key, key) < 0) {
		parent->left = node;
	} else {
		parent->right = node;
	}
}

bstree *bstree_lookup(bstree *tree, char *key)
{
	
	while (tree != NULL) {
		if (strcmp(tree->key, key) == 0) {
			return tree;
		} else if (strcmp(tree->key, key) < 0) {
			tree = tree->left;
		} else {
			tree = tree->right;
		}
	}
	return tree;
}
			
bstree *bstree_min(bstree *tree)
{
	if (tree == NULL) {
		return NULL;
	}
	while (tree->left !=NULL) {
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree)
{
	if (tree == NULL) {
		return NULL;
	}
	while (tree->right !=NULL) {
		tree = tree->right;
	}
	return tree;
}
