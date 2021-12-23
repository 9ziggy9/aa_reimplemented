#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

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

// Strings Exercise
// Show concatenation and find string length
// I previously showed concatenation, lets implement a string length function
int string_length(char *string) {
    int length = 0;
    while (*string++ != '\0') length++;
    return length;
}

// Goodbye (*)
// say goodbye to given string
char *goodbye(char *name) {
    static char goodbye[100] = "Goodbye, ";
    strcat(goodbye, name);
    return goodbye;
}

// Plus Five
// Write a function that adds 5
int plus_five(int num) {
    return num + 5;
}

int main(int argc, char **argv) {
    printf("%s\n", fav_food());
    some_operations();
    bools_example();

    // First fix for referencing memory in stack, can also use static
    // inside of function call, look at goodbye();
    char final_name[100];
    full_name(final_name);
    printf("%s\n", final_name);

    // We'll take this from command line, remember argv[1] is string
    printf("%d\n", string_length(argv[1]));
    printf("%s\n", goodbye(argv[1]));

    printf("%d\n", plus_five(atoi(argv[2])));

    return 0;
}
