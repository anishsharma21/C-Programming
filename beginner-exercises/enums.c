#include <stdio.h>

enum Day { Mon,
           Tue,
           Wed,
           Thu,
           Fri,
           Sat,
           Sun };

typedef enum { Summer,
               Autumn,
               Spring,
               Winter } Season;

int main() {
    enum Day today = Thu;
    Season thisSeason = Spring;

    printf("Day: %d\n", today);
    printf("Season: %d\n", thisSeason);

    if (today == Sat || today == Sun)
        printf("It's the weekend!\n");
    else
        printf("I have to work today.\n");

    return 0;
}