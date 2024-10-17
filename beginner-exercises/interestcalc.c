#include <stdio.h>

float calcsimpint(float principal, float rate, float time) {
    return principal * (rate / 100) * time;
}

void calcsimpintp(float *principal, float *rate, float *time, float *value) {
    *value = *principal * (*rate / 100) * *time;
}

int main() {
    float principal, rate, time, value;
    printf("Principal: ");
    scanf("%f", &principal);
    printf("Rate: ");
    scanf("%f", &rate);
    printf("Time: ");
    scanf("%f", &time);
    float result = calcsimpint(principal, rate, time);
    printf("%.f\n", result);
    calcsimpintp(&principal, &rate, &time, &value);
    printf("%.f\n", value);
}
