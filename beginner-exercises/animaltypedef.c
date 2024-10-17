#include <stdio.h>
#include <string.h>

typedef char name[25];

typedef struct {
    name animalName;
    int speed;
} Animal;

int main() {
    Animal dog;
    Animal cat;

    strcpy(dog.animalName, "Spike");
    dog.speed = 5;
    strcpy(cat.animalName, "Marshmallow");
    cat.speed = 9;

    printf("%s moves at %d speed.\n", dog.animalName, dog.speed);
    printf("%s moves at %d speed.\n", cat.animalName, cat.speed);

    return 0;
}