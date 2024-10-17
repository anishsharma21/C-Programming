#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c = 0, wc = 0;
    int status = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            status = OUT;
        } else {
            if (status == OUT) {
                wc++;
                status = IN;
            }
        }
    }
    printf("\nWord count: %d", wc);
    return 0;
}
