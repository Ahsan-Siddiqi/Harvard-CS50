#include <stdio.h>
#include <string.h>

int main() {
    char input[];
    int *letterCount[];
    int *sentanceCount[];
    int L, S, words = 0, sentances = 0, letters = 0;

    letterCount = malloc(sizeof(int) * 100);
    sentanceCount = malloc(sizeof(int) * 100);


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
        if (strcmp(input[i], " ")) {
            words++;
            if (words >= 100) {

            }
        } else if (strcmp(input[i], ".") || strcmp(input[i], "?") ||strcmp(input[i], "!")) {
            sentances++;
        } else {
            letters++;
        }
    }

    return 0;
}
