Exercice 0 : Annuaire
=====================

### Question 4

En remplaçant `snprintf` par `u.email = "alice@mail.com"`, j'ai l'erreur suivante :

```text
PS E:\Efrei\Master2\Algo_comparative\TP_Socle\exo0> gcc -Wall -Wextra -std=c11 -o test test.c
test.c: In function 'main':
test.c:10:13: error: assignment to expression with array type
   10 |     u.email = "alice@mail.com";
      |             ^
PS E:\Efrei\Master2\Algo_comparative\TP_Socle\exo0>
```

### Question 5
Un tableau ne peut pas être affecté après sa déclaration


Exercice 1 : Analyser le problème avant de coder
=====================

### Question 1 : La grille d'analyse

| Point       | Réponse appliquée au problème                                                                                   |
|-------------|----------------------------------------------------------------------------------------------------------------|
| Entrées     | Une adresse e-mail (chaîne) fournie à l'inscription, à comparer aux e-mails déjà enregistrés.                   |
| Sorties     | Un booléen : l'e-mail existe déjà (inscription refusée) ou non (compte créé).                                   |
| Contraintes | La vérification doit être rapide et exacte : aucun doublon ne doit passer, sans bloquer l'inscription.          |
| Volume      | Le nombre de comptes enregistrés, qui ne fait que croître (chaque inscription réussie ajoute un e-mail).        |
| Fréquence   | La vérification est appelée à chaque tentative d'inscription, donc potentiellement très souvent.               |

### Question 2 — Quels points guident le choix de la structure de données ?

Les points utiles sont le **Volume** et la **Fréquence** (et secondairement les
**Contraintes** de temps/mémoire). C'est le nombre d'éléments à stocker et le
nombre de recherches par seconde qui décident si une recherche séquentielle en
O(n) suffit ou s'il faut une table de hachage.

Les **Entrées** et les **Sorties** n'apprennent rien sur ce choix : elles sont
identiques quelle que soit la structure retenue (on compare toujours une chaîne,
on renvoie toujours un booléen). Elles définissent *ce que* le programme fait,
pas *comment* l'organiser efficacement.

### Question 3 — Qu'est-ce qui distingue les deux annuaires ?

Les deux points qui les séparent sont le **Volume** et la **Fréquence**.
Les deux annuaires ont les mêmes entrées, la même sortie et les mêmes contraintes
de correction ; seule l'échelle change : 30 éléments contre 5 millions (Volume),
et deux consultations par jour contre mille par seconde (Fréquence). Ce sont
précisément ces deux points qui justifient, pour le second, d'abandonner la
recherche séquentielle au profit d'une table de hachage.

=====================