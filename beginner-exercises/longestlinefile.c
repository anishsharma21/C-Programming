#include <stdio.h>
#include <string.h>

int main() {
    FILE *pF = fopen("test.txt", "r");

    if (pF == NULL) {
        printf("File not found.\n");
        return 1;
    }

    char buffer[255];
    int i = 0;
    int longestLength = 0;
    char longestLine[255];
    int templength = 0;

    printf("File contents:\n");
    printf("-------------\n");
    while (fgets(buffer, 255, pF) != NULL) {
        while (i < 256) {
            if (buffer[i] == '\n')
                break;
            templength++;
            i++;
        }
        i = 0;
        if (templength > longestLength) {
            longestLength = templength;
            buffer[strcspn(buffer, "\n")] = '\0';
            strcpy(longestLine, buffer);
        }
        templength = 0;
        printf("%s", buffer);
    }

    fclose(pF);
    printf("-------------\n");

    printf("\nLongest line: \"%s\"\n", longestLine);
    printf("Longest line length: %d\n", longestLength);

    return 0;
}