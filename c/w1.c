#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

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

// Whisper
// Write a function that returns whispered version
char* whisper(char *string) {
    static char whisper[255] = "...";
    char *ellipse = "...";
    char *string_p = string;
    while (*string != '\0') {
        *string = tolower(*string);
        string++;
    }
    return strcat(whisper, strcat(string_p, ellipse));
}

// Averager
// Function which returns average of numbers
float average(float *nums, int total) {
    int count = total;
    float acc = 0;
    while (count-- >= 0) acc += nums[count];
    return acc / total;
}

// Is Odd
// Determine if number is odd
int is_odd(int n) {
    if (n <= 0) return 0;
    return n % 2 == 0 ? 0 : 1;
}

// Log Between
// Print every numbers between a low and high value
// NOTE: First we need to implement a clean way to display arrays
void print_arr(int *arr, int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
    printf("}\n");
}

// Dynamic array implementation, not this only works for positive a and b, b > a
int *new_array(int a, int b) {
    size_t length = abs(b - a);
    int *p_arr;
    p_arr = (int*) malloc(length * sizeof(int));
    int *p_arr_begin = p_arr;
    if (p_arr == NULL) {
        printf("\nERROR: Allocation of memory failed in new_array().\n");
        exit(-1);
    }
    for (size_t i = 0; i < length; i++) {
        *p_arr = a++;
        p_arr++;
    }
    return p_arr_begin;
}

// Print Fives
// Print multiples of five in a range
// Simply generalize new_array()
int *new_mult_array(int a, int b, int mult) {
    size_t length = abs(b - a) / mult;
    int *p_arr;
    p_arr = (int*) malloc(length * sizeof(int));
    int *p_arr_begin = p_arr;
    if (p_arr == NULL) {
        printf("\nERROR: Allocation of memory failed in new_array().\n");
        exit(-1);
    }
    for (int i = a; i <= b; i++) {
        if (a % mult == 0) {
            *p_arr = a;
            p_arr++;
        }
        a++;
    }
    return p_arr_begin;
}

// Add Array
// Write a function which takes two arrays and returns the two combined into one.
int* combined_array(int* arr1, int* arr2, size_t length1, size_t length2) {
    int* combined_array = (int*) malloc(sizeof(int)*(length1+length2));
    for (size_t i = 0; i < length1; i++)
        combined_array[i] = arr1[i];
    for (size_t i = 0; i < length2; i++)
        combined_array[length1+i] = arr2[i];
    return combined_array;
}

// Vowel Counter
bool is_vowel(char c)  {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return true;
        default: return false;
    }
}

int vowel_counter(char* string) {
    int count = 0;
    while (*string++ != '\0') if (is_vowel(tolower(*string))) count++;
    return count;
}

bool is_substring(char *sub, char *string) {
    char* ret;
    ret = strstr(string, sub);
    if (ret)
        return true;
    else
        return false;
}

char** fizz_buzz(size_t max) {
    // Max string length is of "Fizz Buzz" -- 10 chars
    char** fizz_arr = malloc(max * sizeof(char*));
    for (size_t i = 0; i < max; i++)
        fizz_arr[i] = (char*) malloc(10 * sizeof(char));

    for (int i = 1; i < (int) max; i++) {
        if (!(i%3) && !(i%5)) strcpy(fizz_arr[i], "Fizz Buzz");
        else if (!(i%3)) strcpy(fizz_arr[i], "Fizz");
        else if (!(i%5)) strcpy(fizz_arr[i], "Buzz");
        else sprintf(fizz_arr[i], "%d", i);
        printf("%s\n", fizz_arr[i]);
    }
    return fizz_arr;
}

char* pig_word(char *string) {
    size_t length = (size_t) string_length(string);
    char* pig_string;
    int count = 0;
    char first = string[0];
    char cfirst;
    char* cons_buffer = malloc(10*sizeof(char));

    if(strstr("aeiou", &first)) {
        pig_string = malloc((length+4)*sizeof(char));
        strcpy(pig_string, string);
        strcat(pig_string, "yay");
    } else {
        pig_string = malloc((length+3)*sizeof(char));
        while (first != '\0') {
            if(strstr("aeiou", &first)) break;
            strcat(cons_buffer, &first);
            first = string[++count];
        }
        while (first != '\0') {
            strcat(pig_string, &first);
            first = string[++count];
        }
        count = 0;
        cfirst = cons_buffer[count];
        while (cons_buffer[count] != '\0') {
            strcat(pig_string, &cfirst);
            cfirst = cons_buffer[++count];
        }
        strcat(pig_string, "ay");
    }
    free(cons_buffer);
    return pig_string;
}

void pig_latin(char **string, int len) {
    //NOTE: look into strtok
}

bool is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (!(n % i)) return false;
    }
    return true;
}

int main(int argc, char **argv) {
    int start_num = atoi(argv[2]);
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
    printf("%s\n", whisper(argv[1]));

    float number_set[5] = {1,2,3,4,5};
    printf("Average is: %.2f\n", average(number_set, 5));

    printf("Is odd: %s\n", is_odd(start_num) == 1 ? "true" : "false");

    int start = 1;
    int end = 21;
    int *test_arr = new_array(start,end);
    int *test_mult_arr = new_mult_array(start,end, 5);
    print_arr(test_arr, end-start);
    print_arr(test_mult_arr, (end-start)/5);
    free(test_arr);
    free(test_mult_arr);

    int aT1[3] = {1,2,3};
    int aT2[4] = {4,5,6,7};
    int* new_arr = combined_array(aT1,aT2,3,4);
    print_arr(new_arr,7);
    free(new_arr);

    int vowel_count = vowel_counter(argv[1]);
    printf("VOWEL COUNT: %d\n", vowel_count);

    printf("Is \"%s\" a substring of \"%s\"? %s\n", "Dog", "Cat ate a thing",
           is_substring("Dog", "Cat ate a thing") ? "yes" : "no");

    printf("Is \"%s\" a substring of \"%s\"? %s\n", "Cat", "Cat ate a thing",
           is_substring("Cat", "Cat ate a thing") ? "yes" : "no");

    char** fizz_test = fizz_buzz(16);
    free(fizz_test);

    char* old_string = "sham";
    char* piggy = pig_word(old_string);
    printf("\nPIGGY STRING: %s\n", piggy);
    free(piggy);

    int test_prime = is_prime(6);
    printf("Is Prime? %s\n", test_prime ? "true" : "false");

    return 0;
}
