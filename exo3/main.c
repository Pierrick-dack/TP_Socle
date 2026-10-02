#include <stdio.h>
#include "../exo0/annuaire.h"

int main(void)
{
    /* Test sur annuaire vide */
    printf("vide, recherche 'x@mail.com' : %s\n", seq_search("x@mail.com") ? "true" : "false");

    seq_insert("alice@mail.com", 1);
    seq_insert("bob@mail.com",   2);
    seq_insert("carol@mail.com", 3);
    seq_insert("dave@mail.com",  4);
    seq_insert("eve@mail.com",   5);

    /* 3 recherches qui réussissent */
    printf("alice : %s\n", seq_search("alice@mail.com") ? "true" : "false");
    printf("carol : %s\n", seq_search("carol@mail.com") ? "true" : "false");
    printf("eve   : %s\n", seq_search("eve@mail.com")   ? "true" : "false");

    /* 2 recherches qui échouent */
    printf("frank : %s\n", seq_search("frank@mail.com") ? "true" : "false");
    printf("ALICE : %s\n", seq_search("ALICE@mail.com") ? "true" : "false");

    seq_free();
    return 0;
}