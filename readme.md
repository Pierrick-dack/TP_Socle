# Exercice 0 : Annuaire

## Question 4

En remplaçant `snprintf` par `u.email = "alice@mail.com"`, j'ai l'erreur suivante :

```text
test.c: In function 'main':
test.c:10:13: error: assignment to expression with array type
   10 |     u.email = "alice@mail.com";
      |             ^
```

## Question 5

Un tableau ne peut pas être affecté après sa déclaration.

# Exercice 1 : Analyser le problème avant de coder

## Question 1 : La grille d'analyse

| Point       | Réponse appliquée au problème                                                              |
|-------------|-------------------------------------------------------------------------------------------|
| Entrées     | Une adresse e-mail fournie à l'inscription, à comparer aux e-mails déjà enregistrés.       |
| Sorties     | Un booléen : l'e-mail existe déjà (inscription refusée) ou non (compte créé).              |
| Contraintes | La vérification doit être rapide : aucun doublon ne doit passer, sans bloquer l'inscription. |
| Volume      | Le nombre de comptes enregistrés, qui ne fait que croître.                                 |
| Fréquence   | La vérification est appelée à chaque tentative d'inscription.                              |

## Question 2 : Quels points guident le choix de la structure de données ?

Le **Volume** et la **Fréquence**.

## Question 3 : Qu'est-ce qui distingue les deux annuaires ?

Le **Volume** et la **Fréquence** : 30 éléments contre 5 millions, et deux consultations par jour contre mille par seconde.

# Exercice 2 : Un tableau qui grandit tout seul

## Suite des capacités observée

`16, 32, 64`

## Question 5

- 40 insertions : **3** appels à `realloc`.
- 1000 insertions : **7** appels à `realloc`.

# Exercice 3 : La recherche séquentielle

## Résultats

| Recherche            | Attendu | Obtenu |
|----------------------|---------|--------|
| Une adresse présente | true    | true   |
| Une adresse absente  | false   | false  |
| Sur annuaire vide    | false   | false  |

## Question 4

Le programme compile (avec un avertissement), mais la recherche renvoie toujours `false` : on compare les adresses des pointeurs, pas le contenu des chaînes.

## Question 5

- Cas favorable : **1** comparaison (l'adresse est en première position).
- Cas moyen : **n/2** comparaisons (l'adresse est quelque part au milieu).
- Cas défavorable : **n** comparaisons (l'adresse est en dernier ou absente).

# Exercice 4 : Calculer une adresse plutôt que chercher

## Indices obtenus (TAILLE_TABLE = 1024)

| Adresse          | Indice |
|------------------|--------|
| alice@mail.com   | 19     |
| bob@mail.com     | 104    |
| carole@mail.com  | 747    |
| david@mail.com   | 189    |
| eve@mail.com     | 181    |

## Question 3

Toujours **19** : la fonction est déterministe.

## Question 4

**453** et **742** : non voisins, les clés sont bien dispersées.

## Question 5

`david` et `eve` : leur hachage dépasse la capacité d'un `int` et devient négatif, donnant les indices **-835** et **-843**. Utilisés tels quels, ils provoquent un accès hors des bornes du tableau.

## Question 6

Oui, deux adresses peuvent donner le même indice (collision). Ce n'est pas un défaut : c'est inévitable (principe des tiroirs).

# Exercice 5 : La table de hachage avec chaînage

## Résultats

| Recherche            | Attendu | Obtenu |
|----------------------|---------|--------|
| Une adresse présente | true    | true   |
| Une adresse absente  | false   | false  |
| Sur annuaire vide    | false   | false  |

## Question 3

Les chaînes précédentes sont perdues (seule la dernière adresse insérée reste trouvable), et le nœud pointant sur lui-même peut provoquer une boucle infinie.

## Question 4

Après `free(n)`, lire `n->next` est un accès à une zone libérée (*use-after-free*). On mémorise donc le suivant avant de libérer, sinon on perd le reste de la chaîne.