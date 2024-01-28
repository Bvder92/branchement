#include "../include/branchement.h"

int **matrice = NULL;
int occurence = 0;

BenchmarkParameters params;

BenchmarkParameters readBenchmarkParameters() {
  FILE *file = fopen("benchmark.txt", "r");
  if (file == NULL) {
    perror("Erreur lors de l'ouverture du fichier de benchmark");
    exit(1);
  }

  fscanf(file, "NombreSousEnsembles %d\n", &params.nombreSousEnsembles);
  fscanf(file, "TailleEnsemble %d\n", &params.tailleEnsemble);

  params.matriceEnsembles = malloc(params.nombreSousEnsembles * sizeof(int *));

  for (int i = 0; i < params.nombreSousEnsembles; i++) {
    params.matriceEnsembles[i] = malloc(params.tailleEnsemble * sizeof(int));
    for (int j = 0; j < params.tailleEnsemble; j++) {
      fscanf(file, "%d", &params.matriceEnsembles[i][j]);
    }
  }
  fclose(file);
  return params;
}

void print_tab(int *tab, int taille) {
  for (int i = 0; i < taille; ++i) {
    if (i != taille - 1) {
      printf("%d | ", tab[i]);
    } else {
      printf("%d\n", tab[i]);
    }
  }
}

int count_ones(int *tab, int taille){
  int nb=0, i;
  for(i=0; i<taille; ++i){
    if(tab[i] == 1){
      nb++;
    }
  }
  return nb; 
}

bool is_solution(int *tab) {
  int *solution = calloc(params.tailleEnsemble, sizeof(int));
  for (int i = 0; i < params.nombreSousEnsembles; ++i) {
    if (tab[i] == 1) {
      // Nous allons récuperer l'ensemble correspondant a cette indice et
      // parcourir le tableau
      for (int j = 0; j < params.tailleEnsemble; j++) {
        if (matrice[i][j] == 1) {
          solution[j] = 1;
        }
      }
    }
  }
  // On vérifie si l'ensemble est bien une solution ou non
  for (int i = 0; i < params.tailleEnsemble; ++i) {
    if (solution[i] == 0) {
      return false;
    }
  }
  return true;
}

int can_continue(int *current, int index){
  int cur_cpy[params.nombreSousEnsembles];
  memcpy(cur_cpy, current, sizeof(int) * params.nombreSousEnsembles);
  for(int i = index; i< params.nombreSousEnsembles; ++i){
    cur_cpy[i] = 1;
  }
  if(is_solution(cur_cpy)){
    return 1;
  }
  return 0;
}


int branchement(int *current, int index, int best){
  occurence++;
  if(count_ones(current, params.nombreSousEnsembles) > best){
    return best;
  }
  if(is_solution(current)){
    printf("\n\t---Solution Minimale---\n");
    printf("**%d**\t", count_ones(current, params.nombreSousEnsembles));
    print_tab(current, params.nombreSousEnsembles);
    return count_ones(current, params.nombreSousEnsembles);
  }
  if (index >= params.nombreSousEnsembles){
    return best;
  }
  current[index] = 1;
  best = branchement(current, index+1, best);
  current[index] = 0;
  if(can_continue(current, index +1)){
    best = branchement(current, index + 1, best);
  }
  return best;
}



