#include <stdio.h>
#include <string.h>

int main() {
    char strings[][10] = {"Piano", "Bottle", "Gym"};

    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}