#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "error.h"

// C Development Toolkits Using Example.

int main() {
    struct StackInt* stackInt = generateStackInt();
    for (int cursor = 0; cursor < 64; cursor++) {
        pushStackInt(stackInt, cursor);
    }
    struct StackInt* stackIntCopy = copyStackInt(stackInt);
    printStackInt(stackInt);
    printStackInt(stackIntCopy);
    for (int cursor = 0; cursor < 65; cursor++) {
        printf("%d ", popStackInt(stackInt));
    }
    printStackInt(stackInt);
    printStackInt(stackIntCopy);
    destroyStackInt(stackInt);
    destroyStackInt(stackIntCopy);
    printf("Error Head is: %d.\n", ErrorHead);
    return 0;
};
