#include <stdio.h>

int main() {
    int height;
    char tag = '#';

    printf("Height: ");
    scanf("%d", &height);

    for (int i= 0; i<height; i++) {
        for (int j=1; j<=height; j++) {
            if (j<height-i) {
                printf(" ");
            } else {
                printf("%c", tag);
            }
        }
        printf("\n");
    }
    return 0;
}
