#include "hashtab.h"
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-10;
}

int main(int argc, char *argv[])
{
	FILE *in = fopen("word.txt", "r");
	char *key = NULL;
	size_t len = 0;
	unsigned int value = 0;
	double t;
	listnode *hashtab[100];
	listnode *node;

	hashtab_init(hashtab);

	for (int i = 1; i <= atoi(argv[1]); i++) {
		//fgets(key, sizeof(key), in);
		getline(&key, &len, in);
		//printf("%s", key);
		value = hashtab_hash(key);
		//printf("%d %s", value, key);
		hashtab_add(hashtab, key, value);
	}

	printf("%s\n", argv[2]);
	printf("%s\n", argv[3]);
	t = wtime();
	node = hashtab_lookup(hashtab, argv[2]);
	t = wtime() - t;
	printf("Поиск t: %.10f sec.\n", t);
	//printf("Поиск результат: %d %s", node->value, node->key);

	//hashtab_delete(hashtab, key);
	//printf("Delete: %d %s\n", node->value, node->key);

	fclose(in);

	return 0;
}
