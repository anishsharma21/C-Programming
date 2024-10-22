#include <stdio.h>

typedef unsigned char* byte_pointer;

void showbytes(byte_pointer start, int length);

int main() {
    const char a = 'A';
    const short b = 225;
    const int c;
    const long d;
    const char* pA = &a;
    const void* pV;

    const char name[] = "ANISH";
    const int values[] = {1, 2, 3, 4, 12};

    showbytes((byte_pointer)&a, sizeof(char));
    showbytes((byte_pointer)&b, sizeof(short));
    showbytes((byte_pointer)&c, sizeof(int));
    showbytes((byte_pointer)&d, sizeof(long));
    showbytes((byte_pointer)pA, sizeof(char*));
    showbytes((byte_pointer)pV, sizeof(void*));
    showbytes((byte_pointer)&name, sizeof(name));
    showbytes((byte_pointer)&values, sizeof(values));

    return 0;
}

void showbytes(byte_pointer start, int length) {
    printf("");
    for (int i = 0; i < length; i++) {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}
