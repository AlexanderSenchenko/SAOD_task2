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
	unsigned int value;
	double t;
	listnode *hashtab[100];
	listnode *node;

	hashtab_init(hashtab);

	for (int i = 1; i <= atoi(argv[1]); i++) {
		//fgets(key, sizeof(key), in);
		getline(&key, &len, in);
		value = hashtab_hash(key);
		//printf("%d %s\n", value, key);
		hashtab_add(hashtab, key, value);
	}

	t = wtime();
	node = hashtab_lookup(hashtab, key);
	t = wtime() - t;
	printf("Время поиска: %.10f sec.\n", t);
	printf("Результат поиска: %d %s\n", node->value, node->key);

	

	hashtab_delete(hashtab, key);

	fclose(in);

	return 0;
}
