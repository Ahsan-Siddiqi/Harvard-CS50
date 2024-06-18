#include <stdio.h>
#include <stdlib.h>

int main () {
    char* input;
    input = malloc( 20 * sizeof(char));
    scanf("What's your name? %s", &input);

    printf("hello, %s\n", input);

    return 0;
}
