#include <stdio.h>

int main() {
    long nc;

    nc = 0;
    while (getchar() != EOF) {
	++nc;
    }
    printf("%ld\n", nc);

//    double ncc;
//
//    for (ncc = 0; getchar() != EOF; ++ncc);
//    printf("%.0f\n", ncc);
//
//    return 0;
}
