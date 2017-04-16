#include "hashtab.h"
#include "bstree.h"
#include <sys/time.h>
#include <time.h>

int count = 0;

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(int argc, char *argv[])
{
	srand(time(0));
	FILE *in = fopen("word.txt", "r");
	char *key = NULL;
	size_t len = 0;
	unsigned int value, value_bs;
	double t;
	listnode *hashtab[100], *node;
	bstree *tree;

	hashtab_init(hashtab);

	for (int i = 0; i < atoi(argv[1]); i++) {
		getline(&key, &len, in);
		value = hashtab_hash(key);
		hashtab_add(hashtab, key, value);		
		if (i == 0) {
			tree = bstree_create(key, i);
			key = NULL;
			continue;
		}
		value_bs = rand() % atoi(argv[1]);
		bstree_add(tree, key, value_bs);
		key = NULL;
	}

	t = wtime();
	node = hashtab_lookup(hashtab, argv[2]);
	t = wtime() - t;
	printf("Время поиска: %.10f sec.\n", t);
	printf("Результат поиска: %d %s\n", node->value, node->key);

	/*FILE *out = fopen("Lead_time.txt", "a");
	//эксперимент 1
	fprintf(out, "%d\t%.10f\t", atoi(argv[1]), t); //bstree
	fprintf(out, "%.10f\t", t); //hashtab
	//эксперимент 4
	fprintf(out, "%.10f\t", t); //худш
	fprintf(out, "%.10f\t", t); //ср
	//эксперимент 6
	fprintf(out, "%.10f\t", t);//KP
	fprintf(out, "%.10f\t", t);
	fprintf(out, "%.10f\t", t);//XOR
	fprintf(out, "%.10f\n", t);
	fclose(out);*/

	hashtab_delete(hashtab, argv[3]);

	printf("%d\n", count);

	fclose(in);

	return 0;
}
