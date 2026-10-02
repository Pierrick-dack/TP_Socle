#include <stdio.h>
#include "../exo0/annuaire.h"

int main(void)
{
    /* Cas de l'annuaire vide, AVANT toute insertion */
    printf("vide, recherche 'x@mail.com' : %s\n",
           hash_search("x@mail.com") ? "true" : "false");

    hash_insert("alice@mail.com",  1);
    hash_insert("bob@mail.com",    2);
    hash_insert("carole@mail.com", 3);
    hash_insert("david@mail.com",  4);
    hash_insert("eve@mail.com",    5);

    /* 3 recherches qui réussissent */
    printf("alice  : %s\n", hash_search("alice@mail.com")  ? "true" : "false");
    printf("carole : %s\n", hash_search("carole@mail.com") ? "true" : "false");
    printf("eve    : %s\n", hash_search("eve@mail.com")    ? "true" : "false");

    /* 2 recherches qui échouent */
    printf("frank  : %s\n", hash_search("frank@mail.com")  ? "true" : "false");
    printf("ALICE  : %s\n", hash_search("ALICE@mail.com")  ? "true" : "false");

    hash_free();
    return 0;
}