#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("newfile.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error in opening file.\n");
        return 1;
    }
    printf("File opened\n");

    fputs("Line in file\n", file);
    fclose(file);

    file = fopen("newfile.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error in reading file.\n");
        return 1;
    }
    printf("File reopened\n");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}
