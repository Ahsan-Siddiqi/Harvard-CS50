#include <stdio.h>

int main() {

    char input1[100];
    char input2[100];
    int result1, result2;

    // input
    printf("Player 1: ");
    fgets(input1, sizeof(input1), stdin);

    printf("Player 2: ");
    fgets(input2, sizeof(input2), stdin);


    // calculate
    for (int i = 0; i < sizeof(input1); i++) {
        switch (input1[i]) {
            case 'd' || 'g':
                result1 += 2;
                break;
            case 'b' || 'c' || 'm' || 'p':
                result1 += 3;
                break;
            case 'f' || 'h' || 'v' || 'w' || 'y':
                result1 += 4;
                break;
            case 'k':
                result1 += 5;
                break;
            case 'j' || 'x':
                result1 += 8;
                break;
            case 'q' || 'z' = 10;
                result1 += 10;
                break;
            default:
                result1 += 1;
        }
    }

        for (int i = 0; i < sizeof(input2); i++) {
        switch (input1[i]) {
            case 'd' || 'g':
                result2 += 2;
                break;
            case 'b' || 'c' || 'm' || 'p':
                result2 += 3;
                break;
            case 'f' || 'h' || 'v' || 'w' || 'y':
                result2 += 4;
                break;
            case 'k':
                result2 += 5;
                break;
            case 'j' || 'x':
                result2 += 8;
                break;
            case 'q' || 'z' = 10;
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
