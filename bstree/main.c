#include "bstree.h"
#include <sys/time.h>
#include <time.h>

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
	//FILE *out = fopen("Lead_time.txt", "a");

	int rand_value, n = atoi(argv[1]);
	char *rand_key, *word[n];
	size_t len = 0;
	double t;

	bstree *tree, *node_bs;

	rand_value = rand() % n;

	for (int i = 0; i < n; i++) {
		word[i] = malloc(sizeof(char) * 20);
		word[i] = NULL;
		getline(&word[i], &len, in);

		if (rand_value == i) {
			rand_key = word[i];
		}

		//Bstree
		if (i == 0) {
			tree = bstree_create(word[i]);
			continue;
		}
		bstree_add(tree, word[i]);
	}

	//Эксперимент 1
	//Bstree
	t = wtime();
	node_bs = bstree_lookup(tree, rand_key);
	t = wtime() - t;
	//fprintf(out, "%d\t%.10f\t", n, t);
	printf("Bstree:\nВремя поиска: %.10f sec.\n", t);
	printf("Результат поиска: %s\n", node_bs->key);

	//Эксперимент 4
	//fprintf(out, "%.10f\t", t); //худш
	//fprintf(out, "%.10f\t", t); //ср
	//Эксперимент 6
	//fprintf(out, "%.10f\t", t);//KP
	//fprintf(out, "%.10f\t", t);
	//fprintf(out, "%.10f\t", t);//XOR
	//fprintf(out, "%.10f\n", t);
	//fclose(out);

	fclose(in);

	return 0;
}
