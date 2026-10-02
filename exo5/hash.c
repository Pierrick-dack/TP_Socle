#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../exo0/annuaire.h"

typedef struct Node {
    char email[EMAIL_MAX];
    int id;
    struct Node *next;
} Node;

static Node *table[TAILLE_TABLE] = { NULL };


void hash_insert(const char *email, int id) {
    unsigned long i = hachage(email) % TAILLE_TABLE;
    Node *n = malloc(sizeof(Node));
    if (n == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    snprintf(n->email, EMAIL_MAX, "%s", email);
    n->id = id;
    n->next = table[i];
    table[i] = n;
}

bool hash_search(const char *email) {
    unsigned long i = hachage(email) % TAILLE_TABLE;
    for (Node *n = table[i]; n != NULL; n = n->next)
        if (strcmp(n->email, email) == 0)
            return true;
    return false;
}

void hash_free(void) {
    for (int i = 0; i < TAILLE_TABLE; i++) {
        Node *n = table[i];
        while (n != NULL) {
            Node *suiv = n->next;
            free(n);
            n = suiv;
        }
        table[i] = NULL;
    }
}