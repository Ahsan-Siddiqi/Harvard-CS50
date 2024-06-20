#include <stdio.h>
#include <string.h>

int main() {
    char input[];
    int L, S;

    // input
    printf("Text: ");
    fgets(input, sizeof(input), stdin);

    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
    }

    // get avg letters/100 words and avg sentences/100 words
    L = spaces 

    return 0;
}
