#include <stdio.h>
#include <stdlib.h>

int main () {
    char *input;
    input = (char*)malloc(20);
    scanf("What's your name? %s", &input);

    printf("hello, %s\n", input);

    return 0;
}
