#include <stdio.h>
//#include "bstree.h"
#include "hashtab.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *in = fopen("word.txt", "r");
	char word[20];
	listnode hashtab[100];
	unsigned int key;

	hashtab_init(&hashtab);

	for (int i = 1; i <= atoi(argv[1]); i++) {
		fgets(word, sizeof(word), in);
		key = hashtab_hash(word);
		
		printf("%d", key);
		printf("%s", word);
	}

	fclose(in);

	return 0;
}
