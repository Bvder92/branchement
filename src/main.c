#include "../include/branchement.h"


int main(int argc, char const *argv[])
{
    BenchmarkParameters params = readBenchmarkParameters();
    int tailleEnsemble = params.tailleEnsemble;
    int nbSousEnsemble = params.nombreSousEnsembles;

    matrice = (int**)malloc(sizeof(int*) * nbSousEnsemble);
    for(int i=0; i<nbSousEnsemble; ++i){
        matrice[i] = malloc(sizeof(int)*tailleEnsemble);
    }
    // copier les valeurs de la matrice benchmark dans la matrice
    for (int i = 0; i < nbSousEnsemble; ++i) {
        memcpy(matrice[i], params.matriceEnsembles[i], tailleEnsemble * sizeof(int));
    }

    int *solutionOptimale = malloc(sizeof(int) * nbSousEnsemble);

    int meilleureSolution = branchement(solutionOptimale, 0, INT_MAX);
    printf("\n** La nombre de sous-ensembles optimal est : %d\n", meilleureSolution);
    printf("** La fonction a réalisé %d appels récursifs\n", occurence);
    //print_tab(solutionOptimale, nbSousEnsemble);
    
    return 0;
}
