#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindrome(char *str, int strlen);

int main() {
    char input[100];
    printf("Type in a string: ");
    scanf("%99s", input);
    size_t length = strlen(input);
    bool isPalindrome = palindrome(input, length);
    if (isPalindrome) {
	printf("%s is a palindrome\n", input);
	return 0;
    }
    printf("%s is not a palindrome\n", input);
    return 0;
}

bool palindrome(char *str, int length) {
    if (length == 1) {
	return true;
    }
    int low = 0, high = length - 1;
    while (low < high) {
	if (*(str+low) != *(str+high)) {
	    return false;
	}
	low++;
	high--;
    }
    return true;
}
