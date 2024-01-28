#include "benchmark.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

int **matrice;
extern int occurence;

BenchmarkParameters readBenchmarkParameters();

void print_tab(int *tab, int taille);

int count_ones(int *tab, int taille);

bool is_solution(int *tab);

int can_continue(int *current, int index);

int branchement(int *current, int index, int best);
