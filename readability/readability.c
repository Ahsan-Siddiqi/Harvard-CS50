#include <stdio.h>
#include <string.h>

int main() {
    char input[99999];
    int words = 1, sentences = 0, letters = 0;

    // input
    printf("Text: ");
    fgets(input, sizeof(input), stdin);

    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    // scan input
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c == ' ') {
            words++;
        } else if (c == '.' || c == '!' || c == '?') {
            sentences++;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letters++;
        }
    }

    // Calculate L and S
    if (words == 0) {
        printf("Error: No words found in the input.\n");
        return 1;
    }

    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;

    // Calculate index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print result
    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %.0f\n", index);
    }

    return 0;
}
