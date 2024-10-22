#include <stdio.h>

enum boolean { FALSE,
               TRUE };

enum months { JAN = 1,
              FEB,
              MAR,
              APR,
              MAY,
              JUN,
              JUL,
              AUG,
              SEP,
              OCT,
              NOV,
              DEC };

const char* monthnames[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

int main() {
    printf("TRUE: %d\n", TRUE);
    printf("FALSE: %d\n", FALSE);

    for (int i = 0; i < DEC; i++) {
        printf("Month %d: %s\n", i + 1, monthnames[i]);
    }

    char a;
    short b;
    short int c;
    int d;
    long int e;
    long f;
    float eps = 1.0e-5;

    printf("%x, %x, %x, %x, %x, %x\n", (unsigned int)a, (unsigned int)b, (unsigned int)c, (unsigned int)d, (unsigned int)e, (unsigned int)f);
    printf("Float value (exp): %f\n", eps);
    printf("Float value rd (exp): %.2f\n", eps);
    printf("Float value rd (exp): %.9f\n", eps);

    printf("Another float value: %.10f\n", (22.0 / 7));
    printf("Float addition: %f\n", 1.00 + 2.00);
    printf("Interesting float division: %.20f\n", 1.0 / 3.0);

    return 0;
}