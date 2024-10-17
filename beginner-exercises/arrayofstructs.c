#include <stdio.h>
#include <string.h>

typedef struct {
    char name[24];
    int age;
} Student;

int main() {
    Student students[2];
    Student student1 = {"Shwarma", 21};
    Student student2 = {"Llama", 19};
    students[0] = student1;
    students[1] = student2;
    printf("Student 1: %s is %d years old.\n", students[0].name, students[0].age);
    printf("Student 2: %s is %d years old.\n", students[1].name, students[1].age);

    Student students2[] = {student1, student2};
    strcpy(student1.name, "Mike");  // does not modify the values in students2
    strcpy(student2.name, "Jack");
    strcpy(students2[0].name, "Sam");
    strcpy(students2[1].name, "Bob");
    printf("\nStudent 1: %s is %d years old.\n", students2[0].name, students2[0].age);
    printf("Student 2: %s is %d years old.\n", students2[1].name, students2[1].age);

    Student students3[] = {{"John", 18}, {"Luke", 22}, {"Shwarma", 21}, {"Llama", 24}};
    printf("\nSize of the array of structs: %lu\n", sizeof(students3));
    printf("Size of each struct in array: %lu\n\n", sizeof(students3[0]));
    for (int i = 0; i < sizeof(students3) / sizeof(students3[0]); i++)
        printf("Student %d: %s is %d years old.\n", i + 1, students3[i].name, students3[i].age);

    return 0;
}
