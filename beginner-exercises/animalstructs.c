#include <stdio.h>
#include <string.h>

struct Animal {
    char name[25];
    int speed;
};

int main() {
    struct Animal dog;
    struct Animal cat;

    strcpy(dog.name, "Spike");
    dog.speed = 5;
    strcpy(cat.name, "Marshmallow");
    cat.speed = 9;

    printf("%s moves at %d speed.\n", dog.name, dog.speed);
    printf("%s moves at %d speed.\n", cat.name, cat.speed);

    return 0;
}