#include <stdio.h>
#include <memory.h>
#include "read.h"

extern char *s;

int main () {
    int weight = 0;
    s = strdup("K(OH)2O(C(OH(OH)3))2");
    while (*s) {
        weight += readBlock();
    }
    printf("%d\n", weight);
}