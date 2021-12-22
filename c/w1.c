#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Favorite Food
// Print out your favorite food
char* fav_food(void) {
    return "Crab Legs";
}

// Number Exercise
// Write 5 examples of expressions using operations
void some_operations(void) {
    printf("%d\n", 4 + 2);
    printf("%f\n", 4 + 2.2);
    printf("%f\n", 4 / 2.33);
    printf("%d\n", 5 % 2);
    printf("%f\n", 2.55 - 1.441);
}

// Boolean Exercise
// Write some boolean operations

void bools_example(void) {
    bool x = false;
    x = true && false;
    printf("%s\n", x ? "true" : "false");
    x = true || false;
    printf("%s\n", x ? "true" : "false");
    x = !false;
    printf("%s\n", x ? "true" : "false");
}

// Variables Exercise
// Declare a variable called "first_name" and "last_name" yaddy yada
void full_name(char* name) {
    strcat(name, "David ");
    strcat(name, "Rogers");
}

int main(int argc, char **argv) {
    printf("%s\n", fav_food());
    some_operations();
    bools_example();

    char final_name[100];
    full_name(final_name);
    printf("%s\n", final_name);
    return 0;
}
