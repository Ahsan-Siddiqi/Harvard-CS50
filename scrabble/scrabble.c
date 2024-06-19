#include <stdio.h>
#include <string.h>

int main() {

    char input1[100];
    char input2[100];
    int result1, result2 = 0;

    // input
    printf("Player 1: ");
    fgets(input1, sizeof(input1), stdin);

    printf("Player 2: ");
    fgets(input2, sizeof(input2), stdin);

    // remove newline
    size_t length = strlen(input1);
    if (length > 0 && input1[length - 1] == '\n') {
        input1[length - 1] = '\0';
    }

    size_t length = strlen(input2);
    if (length > 0 && input2[length - 1] == '\n') {
        input2[length - 1] = '\0';
    }


    // calculate
     for (int i = 0; i < strlen(input1); i++) {
        switch (input1[i]) {
            case 'd':
            case 'g':
                result1 += 2;
                break;
            case 'b':
            case 'c':
            case 'm':
            case 'p':
                result1 += 3;
                break;
            case 'f':
            case 'h':
            case 'v':
            case 'w':
            case 'y':
                result1 += 4;
                break;
            case 'k':
                result1 += 5;
                break;
            case 'j':
            case 'x':
                result1 += 8;
                break;
            case 'q':
            case 'z':
                result1 += 10;
                break;
            default:
                result1 += 1;
        }
    }

    for (int i = 0; i < strlen(input2); i++) {
        switch (input2[i]) {
            case 'd':
            case 'g':
                result2 += 2;
                break;
            case 'b':
            case 'c':
            case 'm':
            case 'p':
                result2 += 3;
                break;
            case 'f':
            case 'h':
            case 'v':
            case 'w':
            case 'y':
                result2 += 4;
                break;
            case 'k':
                result2 += 5;
                break;
            case 'j':
            case 'x':
                result2 += 8;
                break;
            case 'q':
            case 'z':
                result2 += 10;
                break;
            default:
                result2 += 1;
        }
    }

    // print winner
    if (result1 > result2) {
        printf("Player 1 wins!");
    } else if (result2 > result1) {
        printf("Player 2 wins!")
    } else {
        printf("Tie!");
    }

    return 0;
}
