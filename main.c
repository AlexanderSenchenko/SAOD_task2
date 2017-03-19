#include <stdio.h>
//#include "bstree.h"
//#include "hashtab.h"
#include <stdlib.h>

int main(int a, char *argv[])
{
	FILE *A;
	int n = atoi(argv[1]);
	char word[n];

	A = fopen("dsa-spring2016-task2-src/war_and_peace.txt.utf8", "r");
	for (int i = 0; i < n; i++) {
		fscanf(A, "%c", &word[i]);
	}
	fclose(A);

	return 0;
}
