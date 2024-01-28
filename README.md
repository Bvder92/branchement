# Problème du Set Cover et Algorithme de Branchement

## Problème du Set Cover

Le Problème du Set Cover est un problème d'optimisation bien connu en informatique et en optimisation combinatoire. Étant donné un ensemble fini \( U \) et une collection de sous-ensembles \( S_i \) de \( U \), l'objectif est de trouver le nombre minimum de sous-ensembles dont l'union équivaut à l'ensemble entier \( U \).

### Énoncé du Problème

- **Entrée :** Un ensemble fini \( U \) et une collection de sous-ensembles \( S_i \) de \( U \).
- **Sortie :** Un sous-ensemble de taille minimale de \( S_i \) dont l'union couvre tous les éléments de \( U \).

## Algorithme de Branchement

L'algorithme de Branchement est un algorithme général pour trouver des solutions optimales aux problèmes d'optimisation combinatoire. Il explore systématiquement l'espace des solutions en le divisant en sous-problèmes plus petits et utilise des techniques de bornage pour éliminer les sous-problèmes qui ne peuvent pas produire de meilleures solutions que la meilleure solution actuellement connue.

### Aperçu de l'Algorithme

1. **Initialisation :** Commencez avec une solution vide et définissez la borne supérieure initiale sur l'infini positif.
2. **Branchement :** Sélectionnez une variable de décision et explorez différentes branches de l'espace des solutions.
3. **Bornage :** Utilisez des heuristiques ou des bornes pour élaguer les branches qui ne peuvent pas conduire à une solution optimale.
4. **Mise à jour :** Mettez à jour la meilleure solution actuellement connue si une meilleure solution est trouvée.
5. **Répétez :** Répétez les étapes 2-4 jusqu'à ce que l'espace des solutions soit épuisé.


### Structure du Benchmark

Le benchmark est modifiable par l'utilisateur et peut être adapté aux besoins spécifiques du Problème du Set Cover.

## Utilisation

Pour utiliser le projet, suivez ces étapes :

1. **Compilation :** Exécutez la commande `make` pour compiler le projet.
2. **Exécution :** Utilisez `./bin/main` pour lancer l'algorithme.






