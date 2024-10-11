#include <stdio.h>

void fib(int num);

int main() {
    int num = 1;
    printf("How many fib nums? ");
    scanf("%d", &num);

    fib(num);
    return 0;
}

void fib(int num) {
    int prev = 0, cur = 1;

    printf("%d", 1);
    for (int i = 1; i < num; ++i) {
	printf(" %d", cur);
	int temp = cur;
	cur = prev + cur;
	prev = temp;
    }
    printf("\n");
}
