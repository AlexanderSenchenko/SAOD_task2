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
		key = NULL;
	}

	t = wtime();
	node = hashtab_lookup(hashtab, argv[2]);
	t = wtime() - t;
	printf("Поиск t: %.10f sec.\n", t);
	printf("Поиск результат: %d %s\n", node->value, node->key);

	hashtab_delete(hashtab, argv[3]);

	fclose(in);

	return 0;
}
