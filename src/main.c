#include "hashtab.h"
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
	//FILE *out = fopen("Lead_time.txt", "a");

	int rand_value, n = atoi(argv[1]);
	char *rand_key, *word[n];
	size_t len = 0;
	unsigned int value;
	double t;

	listnode *hashtab[100], *node;

	hashtab_init(hashtab);

	rand_value = rand() % n;

	for (int i = 0; i < n; i++) {
		word[i] = malloc(sizeof(char) * 20);
		word[i] = NULL;
		getline(&word[i], &len, in);
		//printf("%s", word[i]);
		//Hashtab
		value = hashtab_hash(word[i]);

		if (rand_value == i) {
			rand_key = word[i];
		}

		hashtab_add(hashtab, word[i], value);
	}

	//Эксперимент 1
	//Hashtab
	t = wtime();
	node = hashtab_lookup(hashtab, rand_key);
	t = wtime() - t;
	//fprintf(out, "%.10f\t", t);
	printf("Hashtab:\nВремя поиска: %.10f sec.\n", t);
	printf("Результат поиска: %d %s\n", node->value, node->key);

	//Эксперимент 4
	//fprintf(out, "%.10f\t", t); //худш
	//fprintf(out, "%.10f\t", t); //ср
	//Эксперимент 6
	//fprintf(out, "%.10f\t", t);//KP
	//fprintf(out, "%.10f\t", t);
	//fprintf(out, "%.10f\t", t);//XOR
	//fprintf(out, "%.10f\n", t);
	//fclose(out);

	hashtab_delete(hashtab, rand_key);

	printf("Колизии: %d\n", count);

	fclose(in);

	return 0;
}
