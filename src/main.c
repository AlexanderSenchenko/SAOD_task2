//#include "bstree.h"
#include "hashtab.h"

int main(int argc, char *argv[])
{
	FILE *in = fopen("word.txt", "r");
	char key[20];
	listnode *hashtab[100];
	listnode *node;
	unsigned int value = 0;

	hashtab_init(hashtab);

	for (int i = 1; i <= atoi(argv[1]); i++) {
		fgets(key, sizeof(key), in);
		value = hashtab_hash(key);
		printf("%d %s", value, key);
		hashtab_add(hashtab, key, value);
	}

	node = hashtab_lookup(hashtab, argv[2]);
	printf("Поиск: %d %s", node->value, node->key);

	hashtab_delete(hashtab, argv[3]);
	printf("Delete: %d %s\n", node->value, node->key);

	fclose(in);

	return 0;
}
