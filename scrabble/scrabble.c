#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calculate_score(char *input) {
    int score = 0;
    for (int i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'd':
            case 'g':
                score += 2;
                break;
            case 'b':
            case 'c':
            case 'm':
            case 'p':
                score += 3;
                break;
            case 'f':
            case 'h':
            case 'v':
            case 'w':
            case 'y':
                score += 4;
                break;
            case 'k':
                score += 5;
                break;
            case 'j':
            case 'x':
                score += 8;
                break;
            case 'q':
            case 'z':
                score += 10;
                break;
            case 'a':
            case 'e':
            case 'i':
            case 'l':
            case 'n':
            case 'o':
            case 'r':
            case 's':
            case 't':
            case 'u':
                score += 1;
                break;
            default:
                break;
        }
    }
    return score;
}

int main() {

    char input1[100];
    char input2[100];
    int result1 = 0, result2 = 0;

    // input
    printf("Player 1: ");
    fgets(input1, sizeof(input1), stdin);

    printf("Player 2: ");
    fgets(input2, sizeof(input2), stdin);

    // remove newline and uppercase
    size_t length = strlen(input1);
    if (length > 0 && input1[length - 1] == '\n') {
        input1[length - 1] = '\0';
    }

    size_t length2 = strlen(input2);
    if (length2 > 0 && input2[length2 - 1] == '\n') {
        input2[length2 - 1] = '\0';
    }

    char *p1 = input1;
    char *p2 = input2;
    for ( ; *p1; ++p1) *p1 = tolower(*p1);
    for ( ; *p2; ++p2) *p2 = tolower(*p2);

    // calculate
    result1 = calculate_score(input1);
    result2 = calculate_score(input2);

    // print winner
    if (result1 > result2) {
        printf("Player 1 wins!\n");
    } else if (result2 > result1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}
