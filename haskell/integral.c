#include <stdio.h>

float test_function(float x) {
    return x*x;
}

float test_fpointer(float f(float)) {
    return f(4.0);
}

int main(void) {
    printf("%f\n", test_fpointer(&test_function));
    return 0;
}
