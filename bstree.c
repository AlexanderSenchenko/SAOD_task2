#include "bstree.h"
#include <stdlib.h>

bstree *bstree_create(int key, char *value)
{
	bstree *node;

	node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}

	return node;
}

/*void bstree_add(bstree *tree, int key, char *value)
{
	bstree *parent, *node;

	if (tree == NULL) {
		return;
	}

	for (perent = tree; tree != NULL; ) {
		if (key > tree->key) {
			tree = tree->right;
		} else if (key < tree->key) {
			tree = tree->left;
		} else {
			return;
		}
	}

	node = bstree_create(key, value);

	if (key > parent->key) {
		parent->right = node;
	} else {
		parent->left = node;
	}
}*/

//bstree *bstree_lookup(bstree *tree, int key)
//bstree *bstree_min(bstree *tree)
//bstree *bstree_max(bstree *tree)
