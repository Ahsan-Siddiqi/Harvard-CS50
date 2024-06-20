#include <stdio.h>
#include <string.h>

int main() {
    char input[99999];
    int L, S, words = 0, sentances = 0, letters = 0, wordChunks = 0;

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
        if (input[i] == " ") {
            words++;
            if (words >= 100) {
                wordChunks++;
                words = 0;
            }
        } else if (input[i] == "." || input[i] == "?" || input[i] == "!") {
            sentances++;
            words++;
            if (words >= 100) {
                wordChunks++;
                words = 0;
            }
        } else {
            letters++;
        }
    }

    L = letters / wordChunks;
    S = sentances / wordChunks;


    // calcuate index
    int index = 0.0588 * L - 0.296 *s -15.8;

    // print result
    if (index < 1) {
        printf("Before Grade 1");
    } else if (index >= 16){
        printf("Grade 16+");
    } else {
        printf("Grade %d", index);
    }

    return 0;
}
