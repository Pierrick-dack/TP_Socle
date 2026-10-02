#include <stdio.h>
#include "annuaire.h"

int main(void) {
    User u;

    u.id = 1;
    snprintf(u.email, EMAIL_MAX, "%s", "alice@mail.com");

    //u.email = "alice@mail.com";

    printf("ID    : %d\n", u.id);
    printf("Email : %s\n", u.email);

    return 0;
}