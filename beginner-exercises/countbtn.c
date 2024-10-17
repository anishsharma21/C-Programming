#include <stdio.h>

int main() {
    int blanks = 0, tabs = 0, newlines = 0, c = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                blanks++;
                break;
            case '\t':
                tabs++;
                break;
            case '\n':
                newlines++;
                break;
            default:
                break;
        }
    }
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
    return 0;
}
