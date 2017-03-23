#include <stdio.h>
#include "bstree.h"
//#include "hashtab.h"
#include <stdlib.h>

int main()
{
	bstree *tree;

	tree = bstree_create(180, "tigr");

	printf("%d %s", tree->key, tree->value);

	return 0;
}
