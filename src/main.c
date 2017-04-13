//#include "bstree.h"
#include "hashtab.h"

int main(int argc, char *argv[])
{
	FILE *in = fopen("word.txt", "r");
	char key[20];
	listnode *hashtab[100];
	unsigned int value;

	hashtab_init(hashtab);
	/*for (int i = 0; i < 100; i++) {
		hashtab[i] = NULL;
	}*/

	for (int i = 1; i <= atoi(argv[1]); i++) {
		fgets(key, sizeof(key), in);
		value = hashtab_hash(key);
		hashtab_add(hashtab, key, value);
		
		printf("%d", hashtab[44]->value);
		printf("%s", hashtab[44]->key);
	}

	fclose(in);

	return 0;
}
