#include <stdio.h>
#include <string.h>

int main() {
    char input[99999];
    int words = 0, sentances = 0, letters = 0, wordChunks = 0;

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
         char c = input[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letters++;
        } else if (c == ' ') {
            words++;
        } else if (c == '.' || c == '!' || c == '?') {
            sentances++;
        }
    }

    float L = (float)letters / words * 100;
    float S = (float)sentances / words * 100;

    // calcuate index
    int index = 0.0588 * L - 0.296 * S -15.8;

    // print result
    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16){
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }

    return 0;
}
