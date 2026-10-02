#include <stdio.h>
#include "../exo0/annuaire.h"

int main(void)
{
    const char *addrs[] = {
        "alice@mail.com", "bob@mail.com", "carole@mail.com",
        "david@mail.com", "eve@mail.com"
    };

    /* Consigne 2 : indice des cinq adresses */
    printf("=== Indices (TAILLE_TABLE = %d) ===\n", TAILLE_TABLE);
    for (int i = 0; i < 5; i++) {
        unsigned long h = hachage(addrs[i]);
        printf("%-16s -> %lu\n", addrs[i], h % TAILLE_TABLE);
    }

    /* Consigne 3 : alice trois fois */
    printf("\n=== alice x3 ===\n");
    for (int i = 0; i < 3; i++)
        printf("alice@mail.com -> %lu\n",
               hachage("alice@mail.com") % TAILLE_TABLE);

    /* Consigne 4 : user1 vs user2 */
    printf("\n=== user1 vs user2 ===\n");
    printf("user1@mail.com -> %lu\n", hachage("user1@mail.com") % TAILLE_TABLE);
    printf("user2@mail.com -> %lu\n", hachage("user2@mail.com") % TAILLE_TABLE);

    return 0;
}