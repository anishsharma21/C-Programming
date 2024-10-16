#include <stdio.h>
#include <time.h>

int main() {
    int x = 0;
    long startTime = time(0);
    printf("Start time: %ld\n", startTime);
    for (long i = 0; i < 1000000000; i++) {
        x += i;
    }
    printf("End time: %ld\n", time(0) - startTime);
    return 0;
}