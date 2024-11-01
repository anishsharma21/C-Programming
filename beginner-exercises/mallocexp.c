#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = (int *)malloc(sizeof(int));
    *a = 5;
    printf("%p points to %d\n", a, *a);
    return 0;
}
