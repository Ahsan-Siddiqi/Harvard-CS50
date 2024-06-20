#include <stdio.h>
#include <string.h>

int main() {
    char input[];
    int L, S, words = 0, sentances = 0;

    // input
    printf("Text: ");
    fgets(input, sizeof(input), stdin);

    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
    }

    // scan input
    for (int i = 0; i < strlen(input); i++) {
        if (strcmp()) {
            words++;
        } else if (i == ".") {
            sentances++;
        } else {

        }
    }

    return 0;
}
