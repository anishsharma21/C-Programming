#include <stdio.h>

int removeFile(char* filename);

int main() {
    FILE* pF = fopen("test.txt", "w");

    fprintf(pF, "Water\n");
    fprintf(pF, "Bottle\n");

    fclose(pF);

    pF = fopen("test.txt", "r");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), pF) != NULL) {
        printf("%s", buffer);
    }

    fclose(pF);

    removeFile("test.txt");

    return 0;
}

int removeFile(char* filename) {
    if (remove(filename) == 0) {
        printf("\nSUCCESS - file removed.\n");
        return 1;
    }
    printf("\nFAIL - file was not removed.\n");
    return 0;
}