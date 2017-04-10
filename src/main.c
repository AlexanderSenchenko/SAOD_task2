//#include "bstree.h"
#include "hashtab.h"

int main(int argc, char *argv[])
{
	FILE *in = fopen("word.txt", "r");
	char word[20];
	listnode *hashtab = NULL;
	unsigned int key;

	hashtab_init(&hashtab);
	/*for (int i = 0; i < 2; i++) {
		hashtab[i] = NULL;
	}*/

	for (int i = 1; i <= atoi(argv[1]); i++) {
		fgets(word, sizeof(word), in);
		key = hashtab_hash(word);
		//hashtab_add();
		
		printf("%d", key);
		printf("%s", word);
	}

	fclose(in);

	return 0;
}
