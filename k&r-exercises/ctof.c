#include <stdio.h>

void ctof();
void ctoffor();
void ctofdefines();

int main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 30;

    fahr = lower;
    while (fahr <= upper) {
	celsius = 5 * (fahr - 32) / 9;
	printf("%d\t%d\n", fahr, celsius);
	fahr = fahr + step;
    }

    ctof();
    ctoffor();
    ctofdefines();
}

void ctof() {
    printf("\n");

    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 30;

    fahr = lower;
    while (fahr <= upper) {
	celsius = (5.0 / 9.0) * (fahr - 32.0);
	printf("%3.0f\t%6.2f\n", fahr, celsius);
	fahr += step;
    }
}

void ctoffor() {
    printf("\n");

    float fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
	printf("%3.0f\t%6.2f\n", fahr, (5.0/9.0*(fahr-32)));
    }
    printf("\n");
}

#define LOWER 0
#define UPPER 300
#define STEP 30

void ctofdefines() {
    int fahr = 0;
    for (fahr = LOWER; fahr < UPPER; fahr += STEP) {
	printf("%3.0d\t%6.2f\n", fahr, (5.0/9.0*(fahr - 32)));
    }
    printf("\n");
}
