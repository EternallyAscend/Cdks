#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "error.h"

// C Development Toolkits Using Example.

int main() {
    // testStackInt();
    testLinkedStackInt();
    printf("Error Head is: %d.\n", ErrorHead);
    return 0;
};
